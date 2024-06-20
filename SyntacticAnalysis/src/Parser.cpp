//
// Created by Tung Wu on 2024/6/21.
//

#include "../include/Parser.h"

void Parser::parseInit()
{
    this->cx = this->tx = this->cur_index = 0;
    this->symbolTable.clear();
    this->code.clear();
}

void Parser::getNextToken()
{
    this->cur_token = this->tokens[cur_index ++];
    this->cur_type = cur_token.getType();
    if (this->cur_type == TokenType::identSym) this->cur_ident = this->cur_token.getValue();
    else if (this->cur_type == TokenType::numberSym) this->cur_val = this->cur_token.getValue();
}

int Parser::position(Token token, int lev)
{
    int s = this->tx;
    int res = 0, count = 0;
    int diff, preDiff;
    while (s)
    {
        if (this->symbolTable[s].ident == token.getValue())
        {
            if (symbolTable[s].level <= lev)
            {
                if (count) preDiff = diff;
                diff = lev - symbolTable[s].level;
                if (!count || diff < preDiff) res = s;
                ++ count;
            }
        }
        -- s;
    }
    return res;
}

void Parser::enter(SymbolType symbolType, int *pdx, int lev)
{
    ++ this->tx;
    symbolTable[this->tx].ident = this->cur_ident;
    symbolTable[this->tx].type = symbolType;
    if (symbolType == SymbolType::CONST) this->symbolTable[this->tx].val = this->cur_val;
    else if (symbolType == SymbolType::VAR)
    {
        symbolTable[this->tx].level = lev;
        symbolTable[this->tx].addr = *pdx;
        (*pdx) ++;
    }
    else symbolTable[this->tx].level = lev;
}

void Parser::emit(InstructionType f, int l, int a)
{
    this->code[this->cx].f = f;
    this->code[this->cx].l = l;
    this->code[this->cx].a = a;
    ++ this->cx;
}

void Parser::block(int lev)
{
    int dx = 4, tx0 = this->symbolTable.size();
    this->symbolTable[tx0].addr = this->cx;
    emit(InstructionType::jmp, 0, 0);
    if (this->cur_token.getType() == TokenType::constSym)
    {
        getNextToken();
        constdeclaration(lev, &dx);
        while (this->cur_token.getType() == TokenType::commaSym)
        {
            getNextToken();
            constdeclaration(lev, &dx);
        }
        if (this->cur_token.getType() == TokenType::semicolonSym) getNextToken();
        else Error::printErrors(ErrorType::SyntaxError, "comma missing.");
    }
    else if (this->cur_token.getType() == TokenType::varSym)
    {
        getNextToken();
        vardeclaration(lev, &dx);
        while (this->cur_token.getType() == TokenType::commaSym)
        {
            getNextToken();
            vardeclaration(lev, &dx);
        }
        if (this->cur_token.getType() == TokenType::semicolonSym) getNextToken();
        else Error::printErrors(ErrorType::SyntaxError, "comma missing.");
    }
    else if (this->cur_token.getType() == TokenType::plusSym)
    {

    }
}

void Parser::constdeclaration(int lev, int *pdx)
{
    if (this->cur_token.getType() == TokenType::identSym)
    {
        getNextToken();
        if ((this->cur_token.getType() == TokenType::eqSym) || (this->cur_token.getType() == TokenType::becomesSym))
        {
            if (this->cur_token.getType() == TokenType::becomesSym)
                Error::printErrors(ErrorType::SyntaxError, ":= is expected");
            getNextToken();
            if (this->cur_token.getType() == TokenType::numberSym) {
                enter(SymbolType::CONST, pdx, lev);
                getNextToken();
            }
        }
    }
    else Error::printErrors(ErrorType::SyntaxError, "const is expected");
}

void Parser::vardeclaration(int lev, int *pdx)
{
    if (this->cur_token.getType() == TokenType::identSym)
    {
        enter(SymbolType::VAR, pdx, lev);
        getNextToken();
    }
    else Error::printErrors(ErrorType::SyntaxError, "var is expected");
}

void Parser::statement(int lev)
{
    if (this->cur_token.getType() == TokenType::identSym)
    {
        int pos = position(this->cur_token, lev);
        if (pos == 0) Error::printErrors(ErrorType::SyntaxError, "No such variable");
        else if (symbolTable[pos].type != SymbolType::VAR)
            Error::printErrors(ErrorType::SyntaxError, "var is expected");
        getNextToken();
        if (this->cur_token.getType() == TokenType::becomesSym) getNextToken();
        else Error::printErrors(ErrorType::SyntaxError, ":= is expected");
        expression(lev);
        emit(InstructionType::sto, lev - symbolTable[pos].level, symbolTable[pos].addr);
    }
    else if (this->cur_token.getType() == TokenType::callSym)
    {
        getNextToken();
        if (this->cur_token.getType() != TokenType::identSym)
            Error::printErrors(ErrorType::SyntaxError, "call must be followed by an identifier");
        else
        {
            int pos = position(this->cur_token, lev);
            if (pos == 0) Error::printErrors(ErrorType::SyntaxError, "No such call");
            if (symbolTable[pos].type != SymbolType::PROC)
                Error::printErrors(ErrorType::SyntaxError, "identifier should be a proc");
            emit(InstructionType::cal, lev - symbolTable[pos].level, symbolTable[pos].addr);
            getNextToken();
        }
    }
    else if (this->cur_token.getType() == TokenType::ifSym)
    {
        int backup_cx;

        getNextToken();
        condition(lev);
        if (this->cur_token.getType() != TokenType::thenSym)
            Error::printErrors(ErrorType::SyntaxError, "'then' is expected");
        else getNextToken();

        backup_cx = this->cx;
        emit(InstructionType::jpc, 0, 0);
        statement(lev);
        if (this->cur_token.getType() == TokenType::elseSym)
        {
            getNextToken();
            this->code[backup_cx].l = this->cx + 1;
            backup_cx = cx;
            emit(InstructionType::jmp, 0, 0);
            statement(lev);
        }
        code[backup_cx].l = cx;
    }
    else if (this->cur_token.getType() == TokenType::beginSym)
    {
        getNextToken();
        statement(lev);

        while (this->cur_token.getType() == TokenType::semicolonSym)
        {
            getNextToken();
            statement(lev);
        }

        if (this->cur_token.getType() == TokenType::endSym) getNextToken();
        else Error::printErrors(ErrorType::SyntaxError, "end is expected");
    }
    else if (this->cur_token.getType() == TokenType::whileSym)
    {
        int backup_cx1, backup_cx2;
        backup_cx1 = this->cx;
        getNextToken();
        condition(lev);
        backup_cx2 = this->cx;
        emit(InstructionType::jpc, 0, 0);
        if (this->cur_token.getType() == TokenType::doSym) getNextToken();
        else Error::printErrors(ErrorType::SyntaxError, "do is expected");
        statement(lev);
        emit(InstructionType::jmp, 0, backup_cx1);
        code[backup_cx2].l = this->cx;
    }
    else if (this->cur_token.getType() == TokenType::writeSym)
    {
        getNextToken();
        expression(lev);
        emit(InstructionType::sio, 0, 1);
    }
    else if (this->cur_token.getType() == TokenType::readSym)
    {
        getNextToken();
        emit(InstructionType::sio, 0, 2);
        int pos = position(this->cur_token, lev);
        if (pos == 0) Error::printErrors(ErrorType::SyntaxError, "No such variable");
        if (symbolTable[pos].type != SymbolType::VAR)
            Error::printErrors(ErrorType::SyntaxError, "No such variable");
        emit(InstructionType::sto, lev - symbolTable[pos].level, symbolTable[pos].addr);
        getNextToken();
    }
}

void Parser::condition(int lev)
{
    if (this->cur_token.getType() == TokenType::oddSym)
    {
        getNextToken();
        expression(lev);
        emit(InstructionType::opr, 0, 6);
    }
    else
    {
        expression(lev);
        TokenType op = this->cur_token.getType();
        if (op != TokenType::eqSym && op != TokenType::neqSym && op != TokenType::lesSym && op != TokenType::leqSym
               && op != TokenType::gtrSym && op != TokenType::geqSym)
            Error::printErrors(ErrorType::SyntaxError, "Relation operator expected");
        getNextToken();
        expression(lev);
        switch(op)
        {
            case TokenType::eqSym:
                emit(InstructionType::opr, 0, 8);
            case TokenType::neqSym:
                emit(InstructionType::opr, 0, 9);
            case TokenType::lesSym:
                emit(InstructionType::opr, 0, 10);
            case TokenType::leqSym:
                emit(InstructionType::opr, 0, 11);
            case TokenType::gtrSym:
                emit(InstructionType::opr, 0, 12);
            case TokenType::geqSym:
                emit(InstructionType::opr, 0, 13);
        }
    }
}

void Parser::expression(int lev)
{
    TokenType op = this->cur_token.getType();
    if (op == TokenType::plusSym || op == TokenType::minusSym)
    {
        getNextToken();
        term(lev);
        if (op == TokenType::minusSym) emit(InstructionType::opr, 0, 1);
    }
    else term(lev);

    while (this->cur_token.getType() == TokenType::plusSym || this->cur_token.getType() == TokenType::minusSym)
    {
        op = this->cur_token.getType();
        getNextToken();
        term(lev);
        if (op == TokenType::plusSym) emit(InstructionType::opr, 0, 2);
        else emit(InstructionType::opr, 0, 3);
    }
}

void Parser::term(int lev)
{
    factor(lev);
    while (this->cur_token.getType() == TokenType::mulSym || this->cur_token.getType() == TokenType::slashSym)
    {
        TokenType op = this->cur_token.getType();
        getNextToken();
        factor(lev);
        if (op == TokenType::mulSym) emit(InstructionType::opr, 0, 4);
        else emit(InstructionType::opr, 0, 5);
    }
}

void Parser::factor(int lev)
{
    TokenType tokenType = this->cur_token.getType();
    if (tokenType == TokenType::identSym)
    {
        int pos = position(this->cur_token, lev);
        if (pos == 0) Error::printErrors(ErrorType::SemanticError, "No such variable");
        const Symbol &symbol = symbolTable[pos];
        if (symbol.type == SymbolType::CONST)
            emit(InstructionType::lit, 0, std::stoi(symbol.val));
        else if (symbol.type == SymbolType::VAR)
            emit(InstructionType::lod, lev - symbol.level, symbol.addr);
        else Error::printErrors(ErrorType::SemanticError, "Expression must not contain a procedure identifier");
        getNextToken();
    }
    else if (tokenType == TokenType::numberSym)
    {
        emit(InstructionType::lit, 0, std::stoi(this->cur_val));
        getNextToken();
    }
    else if (tokenType == TokenType::lparentSym)
    {
        getNextToken();
        expression(lev);
        if (this->cur_token.getType() == TokenType::rparentSym) getNextToken();
        else Error::printErrors(ErrorType::SyntaxError, "Right parenthesis missing.");
    }
    else Error::printErrors(ErrorType::SyntaxError, "ungrammatical");
}

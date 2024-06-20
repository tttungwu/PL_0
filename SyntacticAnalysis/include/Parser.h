//
// Created by Tung Wu on 2024/6/21.
//

#ifndef PL_0_PARSER_H
#define PL_0_PARSER_H

#include <vector>
#include "../../Common/include/Token.h"
#include "../../Common/include/Error.h"
#include "Symbol.h"
#include "Instruction.h"

class Parser {
private:
    int cx, tx, cur_index;
    Token cur_token;
    std::vector<Symbol> symbolTable;
    std::vector<Instruction> code;
    std::vector<Token> tokens;

    TokenType cur_type;
    std::string cur_ident, cur_val;

    void parseInit();
    void getNextToken();
    int position(Token, int);
    void enter(SymbolType, int *, int);
    void emit(InstructionType, int, int);

    void statement(int);
    void condition(int);
    void expression(int);
    void term(int);
    void factor(int);
public:
    Parser(std::vector<Token> tokens) : tokens(tokens){}
};


#endif //PL_0_PARSER_H
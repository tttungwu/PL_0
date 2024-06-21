//
// Created by Tung Wu on 2024/6/21.
//

#ifndef PL_0_PARSER_H
#define PL_0_PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../../Common/include/Token.h"
#include "../../Common/include/Error.h"
#include "Symbol.h"
#include "Instruction.h"

class Parser {
private:
    int cx, cur_index;
    Token cur_token;
    std::vector<Symbol> symbolTable;
    std::vector<Instruction> code;
    std::vector<Token> tokens;

    TokenType cur_type;
    std::string cur_ident, cur_val;

    void parseInit();
    void getNextToken();
    int position(Token, int, int *);
    void enter(SymbolType, int *, int, int *);
    void emit(InstructionType, int, int);

    void program();
    void block(int, int);
    void constdeclaration(int, int *, int *);
    void vardeclaration(int, int *, int *);
    void statement(int, int *);
    void condition(int, int *);
    void expression(int, int *);
    void term(int, int *);
    void factor(int, int *);

    void output();
public:
    Parser() {};

    void parse(std::vector<Token> tokens);
};


#endif //PL_0_PARSER_H

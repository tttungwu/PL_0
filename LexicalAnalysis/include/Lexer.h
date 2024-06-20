//
// Created by Tung Wu on 2024/6/21.
//

#ifndef PL_0_LEXER_H
#define PL_0_LEXER_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <deque>
#include <vector>
#include "Statechart.h"
#include "../../Common/include/Token.h"


class Lexer {
public:
    static std::vector<Token> tokenize(const std::string &filename);

private:
    Lexer() {}

    static std::vector<Token> scanLine(std::string line);
};


#endif //PL_0_LEXER_H

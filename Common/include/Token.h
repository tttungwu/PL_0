//
// Created by Tung Wu on 2024/6/20.
//

#ifndef PL_0_TOKEN_H
#define PL_0_TOKEN_H


#include "TokenType.h"
#include <string>

class Token {
private:
    TokenType type;     // 类型
    std::string val;    // 值
public:
    Token(TokenType, std::string);
    std::string getValue();
    TokenType getType();
    void print();
};


#endif //PL_0_TOKEN_H

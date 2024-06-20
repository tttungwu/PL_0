//
// Created by Tung Wu on 2024/6/20.
//

#include "../include/Token.h"

Token::Token(TokenType t, std::string s) : type(t), val(s) {}

std::string Token::getValue()
{
    return this->val;
}

TokenType Token::getType()
{
    return this->type;
}

void Token::print()
{
    std::cout << type2str(this->type) << ' ' << this->val << std::endl;
}

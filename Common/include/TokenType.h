//
// Created by Tung Wu on 2024/6/20.
//

#ifndef PL_0_TOKENTYPE_H
#define PL_0_TOKENTYPE_H

#include <iostream>
#include <string>
#include <unordered_map>

enum TokenType {
    plusSym, minusSym, mulSym, slashSym,
    eqSym, neqSym, leqSym, lesSym, geqSym, gtrSym,
    lparentSym, rparentSym, commaSym, semicolonSym,
    periodSym, becomesSym, oddSym, beginSym, endSym, ifSym,
    thenSym, whileSym, doSym, callSym, constSym, varSym,
    procSym, writeSym, readSym , elseSym, identSym, numberSym,
    tokenTypeCount
};

extern std::unordered_map<TokenType, std::string> type2strMap;
extern std::string type2str(TokenType type);

#endif //PL_0_TOKENTYPE_H

//
// Created by Tung Wu on 2024/6/21.
//

#include "../include/TokenType.h"


std::unordered_map<TokenType, std::string> type2strMap = {
        {TokenType::identSym, "identSym"},
        {TokenType::numberSym, "numberSym"},
        {TokenType::plusSym, "plusSym"},
        {TokenType::minusSym, "minusSym"},
        {TokenType::mulSym, "mulSym"},
        {TokenType::slashSym, "slashSym"},
        {TokenType::oddSym, "oddSym"},
        {TokenType::eqSym, "eqSym"},
        {TokenType::neqSym, "neqSym"},
        {TokenType::lesSym, "lesSym"},
        {TokenType::leqSym, "leqSym"},
        {TokenType::gtrSym, "gtrSym"},
        {TokenType::geqSym, "geqSym"},
        {TokenType::lparentSym, "lparentSym"},
        {TokenType::rparentSym, "rparentSym"},
        {TokenType::commaSym, "commaSym"},
        {TokenType::semicolonSym, "semicolonSym"},
        {TokenType::periodSym, "periodSym"},
        {TokenType::becomesSym, "becomesSym"},
        {TokenType::beginSym, "beginSym"},
        {TokenType::endSym, "endSym"},
        {TokenType::ifSym, "ifSym"},
        {TokenType::thenSym, "thenSym"},
        {TokenType::whileSym, "whileSym"},
        {TokenType::doSym, "doSym"},
        {TokenType::callSym, "callSym"},
        {TokenType::constSym, "constSym"},
        {TokenType::varSym, "varSym"},
        {TokenType::procSym, "procSym"},
        {TokenType::writeSym, "writeSym"},
        {TokenType::readSym, "readSym"},
        {TokenType::elseSym, "elseSym"},
};

std::string type2str(TokenType type)
{
    if (type2strMap.count(type)) return type2strMap[type];
    else return "NotFound";
}

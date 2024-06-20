//
// Created by Tung Wu on 2024/6/20.
//

#include "../include/Statechart.h"

Statechart::Statechart()
{
    this->diagram[TokenType::plusSym][std::make_pair(0, '+')] = 1;
    this->finalState[TokenType::plusSym] = 1;

    this->diagram[TokenType::minusSym][std::make_pair(0, '-')] = 1;
    this->finalState[TokenType::minusSym] = 1;

    this->diagram[TokenType::slashSym][std::make_pair(0, '/')] = 1;
    this->finalState[TokenType::slashSym] = 1;

    this->diagram[TokenType::mulSym][std::make_pair(0, '*')] = 1;
    this->finalState[TokenType::mulSym] = 1;

    this->diagram[TokenType::eqSym][std::make_pair(0, '=')] = 1;
    this->finalState[TokenType::eqSym] = 1;

    this->diagram[TokenType::neqSym][std::make_pair(0, '<')] = 1;
    this->diagram[TokenType::neqSym][std::make_pair(1, '>')] = 2;
    this->finalState[TokenType::neqSym] = 2;

    this->diagram[TokenType::lesSym][std::make_pair(0, '<')] = 1;
    this->finalState[TokenType::lesSym] = 1;

    this->diagram[TokenType::leqSym][std::make_pair(0, '<')] = 1;
    this->diagram[TokenType::leqSym][std::make_pair(1, '=')] = 2;
    this->finalState[TokenType::leqSym] = 2;

    this->diagram[TokenType::gtrSym][std::make_pair(0, '>')] = 1;
    this->finalState[TokenType::gtrSym] = 1;

    this->diagram[TokenType::geqSym][std::make_pair(0, '>')] = 1;
    this->diagram[TokenType::geqSym][std::make_pair(1, '=')] = 2;
    this->finalState[TokenType::geqSym] = 2;

    this->diagram[TokenType::lparentSym][std::make_pair(0, '(')] = 1;
    this->finalState[TokenType::lparentSym] = 1;

    this->diagram[TokenType::rparentSym][std::make_pair(0, ')')] = 1;
    this->finalState[TokenType::rparentSym] = 1;

    this->diagram[TokenType::commaSym][std::make_pair(0, ',')] = 1;
    this->finalState[TokenType::commaSym] = 1;

    this->diagram[TokenType::semicolonSym][std::make_pair(0, ';')] = 1;
    this->finalState[TokenType::semicolonSym] = 1;

    this->diagram[TokenType::periodSym][std::make_pair(0, '.')] = 1;
    this->finalState[TokenType::periodSym] = 1;

    this->diagram[TokenType::becomesSym][std::make_pair(0, ':')] = 1;
    this->diagram[TokenType::becomesSym][std::make_pair(1, '=')] = 2;
    this->finalState[TokenType::becomesSym] = 2;

    this->diagram[TokenType::oddSym][std::make_pair(0, 'o')] = 1;
    this->diagram[TokenType::oddSym][std::make_pair(1, 'd')] = 2;
    this->diagram[TokenType::oddSym][std::make_pair(2, 'd')] = 3;
    this->finalState[TokenType::oddSym] = 3;

    this->diagram[TokenType::beginSym][std::make_pair(0, 'b')] = 1;
    this->diagram[TokenType::beginSym][std::make_pair(1, 'e')] = 2;
    this->diagram[TokenType::beginSym][std::make_pair(2, 'g')] = 3;
    this->diagram[TokenType::beginSym][std::make_pair(3, 'i')] = 4;
    this->diagram[TokenType::beginSym][std::make_pair(4, 'n')] = 5;
    this->finalState[TokenType::beginSym] = 5;

    this->diagram[TokenType::endSym][std::make_pair(0, 'e')] = 1;
    this->diagram[TokenType::endSym][std::make_pair(1, 'n')] = 2;
    this->diagram[TokenType::endSym][std::make_pair(2, 'd')] = 3;
    this->finalState[TokenType::endSym] = 3;

    this->diagram[TokenType::ifSym][std::make_pair(0, 'i')] = 1;
    this->diagram[TokenType::ifSym][std::make_pair(1, 'f')] = 2;
    this->finalState[TokenType::ifSym] = 2;

    this->diagram[TokenType::thenSym][std::make_pair(0, 't')] = 1;
    this->diagram[TokenType::thenSym][std::make_pair(1, 'h')] = 2;
    this->diagram[TokenType::thenSym][std::make_pair(2, 'e')] = 3;
    this->diagram[TokenType::thenSym][std::make_pair(2, 'n')] = 4;
    this->finalState[TokenType::thenSym] = 4;

    this->diagram[TokenType::whileSym][std::make_pair(0, 'w')] = 1;
    this->diagram[TokenType::whileSym][std::make_pair(1, 'h')] = 2;
    this->diagram[TokenType::whileSym][std::make_pair(2, 'i')] = 3;
    this->diagram[TokenType::whileSym][std::make_pair(3, 'l')] = 4;
    this->diagram[TokenType::whileSym][std::make_pair(4, 'e')] = 5;
    this->finalState[TokenType::whileSym] = 5;

    this->diagram[TokenType::doSym][std::make_pair(0, 'd')] = 1;
    this->diagram[TokenType::doSym][std::make_pair(1, 'o')] = 2;
    this->finalState[TokenType::doSym] = 2;

    this->diagram[TokenType::callSym][std::make_pair(0, 'c')] = 1;
    this->diagram[TokenType::callSym][std::make_pair(1, 'a')] = 2;
    this->diagram[TokenType::callSym][std::make_pair(2, 'l')] = 3;
    this->diagram[TokenType::callSym][std::make_pair(2, 'l')] = 4;
    this->finalState[TokenType::callSym] = 4;

    this->diagram[TokenType::constSym][std::make_pair(0, 'c')] = 1;
    this->diagram[TokenType::constSym][std::make_pair(1, 'o')] = 2;
    this->diagram[TokenType::constSym][std::make_pair(2, 'n')] = 3;
    this->diagram[TokenType::constSym][std::make_pair(3, 's')] = 4;
    this->diagram[TokenType::constSym][std::make_pair(4, 't')] = 5;
    this->finalState[TokenType::constSym] = 5;

    this->diagram[TokenType::varSym][std::make_pair(0, 'v')] = 1;
    this->diagram[TokenType::varSym][std::make_pair(1, 'a')] = 2;
    this->diagram[TokenType::varSym][std::make_pair(2, 'r')] = 3;
    this->finalState[TokenType::varSym] = 3;

    this->diagram[TokenType::procSym][std::make_pair(0, 'p')] = 1;
    this->diagram[TokenType::procSym][std::make_pair(1, 'r')] = 2;
    this->diagram[TokenType::procSym][std::make_pair(2, 'o')] = 3;
    this->diagram[TokenType::procSym][std::make_pair(2, 'c')] = 4;
    this->finalState[TokenType::procSym] = 4;

    this->diagram[TokenType::writeSym][std::make_pair(0, 'w')] = 1;
    this->diagram[TokenType::writeSym][std::make_pair(1, 'r')] = 2;
    this->diagram[TokenType::writeSym][std::make_pair(2, 'i')] = 3;
    this->diagram[TokenType::writeSym][std::make_pair(3, 't')] = 4;
    this->diagram[TokenType::writeSym][std::make_pair(4, 'e')] = 5;
    this->finalState[TokenType::writeSym] = 5;

    this->diagram[TokenType::readSym][std::make_pair(0, 'r')] = 1;
    this->diagram[TokenType::readSym][std::make_pair(1, 'e')] = 2;
    this->diagram[TokenType::readSym][std::make_pair(2, 'a')] = 3;
    this->diagram[TokenType::readSym][std::make_pair(2, 'd')] = 4;
    this->finalState[TokenType::readSym] = 4;

    this->diagram[TokenType::elseSym][std::make_pair(0, 'e')] = 1;
    this->diagram[TokenType::elseSym][std::make_pair(1, 'l')] = 2;
    this->diagram[TokenType::elseSym][std::make_pair(2, 's')] = 3;
    this->diagram[TokenType::elseSym][std::make_pair(2, 'e')] = 4;
    this->finalState[TokenType::elseSym] = 4;

    for (char c = 'a'; c <= 'z'; ++ c)
    {
        this->diagram[TokenType::identSym][std::make_pair(0, c)] = 1;
        this->diagram[TokenType::identSym][std::make_pair(0, c + 'A' - 'a')] = 1;
        this->diagram[TokenType::identSym][std::make_pair(1, c)] = 1;
        this->diagram[TokenType::identSym][std::make_pair(1, c + 'A' - 'a')] = 1;
    }
    for (char c = '0'; c <= '9'; ++ c)
        this->diagram[TokenType::identSym][std::make_pair(1, c)] = 1;
    this->finalState[TokenType::identSym] = 1;

    for (char c = '0'; c <= '9'; ++ c)
    {
        this->diagram[TokenType::numberSym][std::make_pair(0, c)] = 1;
        this->diagram[TokenType::numberSym][std::make_pair(1, c)] = 1;
    }
    this->finalState[TokenType::numberSym] = 1;
}

int Statechart::transferTo(std::map<std::pair<int, char>, int> &diagram, int state, char c)
{
    if (diagram.count(std::make_pair(state, c)) == 0) return -1;
    return diagram[std::make_pair(state, c)];
}

bool Statechart::isFinalState(int finalState, int state)
{
    return finalState == state;
}

std::vector<Token> Statechart::getTokens(std::string line)
{
    std::vector<Token> res;
    for (int i = 0; i < line.size(); ++ i)
    {
        bool bad = true;
        for (int j = 0; j < TokenType::tokenTypeCount; ++ j)
        {
            TokenType type = static_cast<TokenType>(j);
            std::string value = "";
            std::map<std::pair<int, char>, int> &diagram = this->diagram[type];
            int finalState = this->finalState[type];
            int state = 0;
            for (int k = i; k < line.size(); ++ k)
            {
                int to = transferTo(diagram, state, line[k]);
                if (to == -1)
                {
                    if (isFinalState(finalState, state))
                    {
                        bad = false;
                        i = k - 1;
                    }
                    break;
                }
                value += line[k];
                state = to;
                if (k == line.size() - 1 && isFinalState(finalState, state))
                {
                    bad = false;
                    i = k;
                }
            }
            if (!bad)
            {
                res.emplace_back(type, value);
                break;
            }
        }
        if (bad)
        {
            res.clear();
            break;
        }
    }
    return res;
}
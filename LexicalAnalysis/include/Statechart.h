//
// Created by Tung Wu on 2024/6/20.
//

#ifndef PL_0_STATECHART_H
#define PL_0_STATECHART_H

#include <map>
#include <vector>
#include "../../Common/include/Token.h"

class Statechart {
private:
    Statechart();

    // 对应不同类型的状态图
    std::map<std::pair<int, char>, int> diagram[TokenType::tokenTypeCount];
    // 对应不同类型的状态图的终结态
    std::map<TokenType, int> finalState;

    // 返回对应状态的转移结果，如果返回-1表示转移失败
    int transferTo(std::map<std::pair<int, char>, int> &diagram, int state, char c);
    // 判断对应状态是否终结态
    bool isFinalState(int finalState, int state);

public:
    static Statechart& getStatechart()
    {
        static Statechart statechart;
        return statechart;
    }

    std::vector<Token> getTokens(std::string line);
};


#endif //PL_0_STATECHART_H

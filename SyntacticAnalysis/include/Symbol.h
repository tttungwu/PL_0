//
// Created by Tung Wu on 2024/6/21.
//

#ifndef PL_0_SYMBOL_H
#define PL_0_SYMBOL_H

#include <string>

enum SymbolType {
    CONST, VAR, PROC
};

class Symbol {
/*
 * For constants, store type, ident and val.
 * For variables, store type, ident, L and M.
 * For procedures, store type, ident, L and M.
 */
public:
    SymbolType type;    // 类型
    std::string ident;  // 标识符号
    std::string val;    // 值
    int level; 		    // 定义层
    int addr; 		    // 地址

    Symbol() {};
};


#endif //PL_0_SYMBOL_H

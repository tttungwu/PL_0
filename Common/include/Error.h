//
// Created by Tung Wu on 2024/6/21.
//

#ifndef PL_0_ERROR_H
#define PL_0_ERROR_H

#include <iostream>
#include <string>

enum class ErrorType {
    LexicalError,
    SyntaxError,
    SemanticError,
    CodeGenError,
    OtherError,
};


class Error {
public:
    static void printErrors(ErrorType type, const std::string &message, bool exitFlag = true, int line = -1);

private:
    static std::string getTypeString(ErrorType type);
};



#endif //PL_0_ERROR_H

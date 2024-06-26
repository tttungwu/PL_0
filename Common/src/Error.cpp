//
// Created by Tung Wu on 2024/6/21.
//

#include "../include/Error.h"

std::string Error::getTypeString(ErrorType type) {
    switch (type) {
        case ErrorType::LexicalError: return "Lexical Error";
        case ErrorType::SyntaxError: return "Syntax Error";
        case ErrorType::SemanticError: return "Semantic Error";
        case ErrorType::CodeGenError: return "Code Generation Error";
        case ErrorType::OtherError: return "Other Error";
        default: return "Unknown Error";
    }
}

void Error::printErrors(ErrorType type, const std::string &message, bool exitFlag, int line) {
    std::cout << "Error Type: " << getTypeString(type) << "\n";
    if (line != -1) std::cout << "Line: " << line << "\n";
    std::cout << "Message: " << message << "\n\n";
    if (exitFlag) exit(1);
}

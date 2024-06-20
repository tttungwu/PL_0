#include <iostream>
#include <vector>
#include "Common/include/Token.h"
#include "LexicalAnalysis/include/Lexer.h"

int main() {
    std::vector<Token> tokens = Lexer::tokenize("../test.txt");
    for (auto token : tokens)
        token.print();
    return 0;
}

#include <iostream>
#include <vector>
#include "Common/include/Token.h"
#include "LexicalAnalysis/include/Lexer.h"
#include "SyntacticAnalysis/include/Parser.h"

int main() {
    std::cout << "********** Lexical Analysis **********" << std::endl;
    std::vector<Token> tokens = Lexer::tokenize("../test.txt");
    for (auto token : tokens)
        token.print();
    std::cout << std::endl << std::endl;

    std::cout << "********** Syntactic Analysis **********" << std::endl;
    Parser* parser = new Parser();
    parser->parse(tokens);

    return 0;
}

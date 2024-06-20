cmake_minimum_required(VERSION 3.26)
project(PL_0)

set(CMAKE_CXX_STANDARD 17)

add_executable(PL_0 main.cpp
        Common/include/Token.h
        Common/src/Token.cpp
        LexicalAnalysis/include/Statechart.h
        LexicalAnalysis/src/Statechart.cpp
        Common/src/TokenType.cpp
        LexicalAnalysis/include/Lexer.h
        LexicalAnalysis/src/Lexer.cpp
        Common/include/Error.h
        Common/src/Error.cpp
        SyntacticAnalysis/include/Symbol.h
        SyntacticAnalysis/include/Symbol.cpp
        SyntacticAnalysis/include/Instruction.h
        SyntacticAnalysis/include/Instruction.cpp
        SyntacticAnalysis/include/Parser.h
        SyntacticAnalysis/src/Parser.cpp)

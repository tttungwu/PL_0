//
// Created by Tung Wu on 2024/6/21.
//

#ifndef PL_0_INSTRUCTION_H
#define PL_0_INSTRUCTION_H

enum InstructionType {
    illegal, lit, opr, lod, sto, cal, inc, jmp, jpc, sio
};

class Instruction {
public:
    InstructionType f;  // 代码指令
    int l;              //引用层与声明层的层次差
    int a;              //根据f的不同而不同
};


#endif //PL_0_INSTRUCTION_H

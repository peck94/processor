//
//  JmpInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "JmpInstruction.h"
using namespace std;

JmpInstruction::JmpInstruction(vector<string> args): IInstruction(args) {}

void JmpInstruction::run(State &s) {
    s.jmp(s.call(args[0]));
}

string JmpInstruction::to_string() {
    return "JMP " + args[0];
}
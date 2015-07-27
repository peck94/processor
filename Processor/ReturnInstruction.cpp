//
//  ReturnInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "ReturnInstruction.h"
using namespace std;

ReturnInstruction::ReturnInstruction(vector<string> args): IInstruction(args) {}

void ReturnInstruction::run(State &s) {
    s.jmp(s.pop());
}

string ReturnInstruction::to_string() {
    return "RET";
}
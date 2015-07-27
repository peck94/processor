//
//  CallInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "CallInstruction.h"
using namespace std;

CallInstruction::CallInstruction(vector<string> args): IInstruction(args) {}

void CallInstruction::run(State &s) {
    s.push();
    s.jmp(s.call(args[0]));
}

string CallInstruction::to_string() {
    return "CALL " + args[0];
}
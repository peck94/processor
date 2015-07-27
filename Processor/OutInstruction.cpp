//
//  OutInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "OutInstruction.h"
using namespace std;

OutInstruction::OutInstruction(vector<string> args): IInstruction(args) {}

void OutInstruction::run(State &s) {
    s.set(args[0][0]);
    s.next();
}

string OutInstruction::to_string() {
    return "OUT " + args[0];
}
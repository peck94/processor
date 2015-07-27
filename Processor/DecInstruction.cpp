//
//  DecInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "DecInstruction.h"
using namespace std;

DecInstruction::DecInstruction(vector<string> args): IInstruction(args) {}

void DecInstruction::run(State &s) {
    s.dec();
    s.next();
}

string DecInstruction::to_string() {
    return "DEC";
}
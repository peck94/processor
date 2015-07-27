//
//  NopInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "NopInstruction.h"
using namespace std;

NopInstruction::NopInstruction(vector<string> args): IInstruction(args) {};

void NopInstruction::run(State &s) {
    s.next();
}

string NopInstruction::to_string() {
    return "NOP";
}
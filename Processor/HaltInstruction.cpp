//
//  HaltInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "HaltInstruction.h"
using namespace std;

HaltInstruction::HaltInstruction(vector<string> args): IInstruction(args) {}

void HaltInstruction::run(State &s) {
    s.halt();
}

string HaltInstruction::to_string() {
    return "HALT";
}
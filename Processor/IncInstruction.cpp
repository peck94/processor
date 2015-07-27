//
//  IncInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "IncInstruction.h"
using namespace std;

IncInstruction::IncInstruction(vector<string> args): IInstruction(args) {}

void IncInstruction::run(State &s) {
    s.inc();
    s.next();
}

string IncInstruction::to_string() {
    return "INC";
}
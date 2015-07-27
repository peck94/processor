//
//  LabelInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "LabelInstruction.h"
using namespace std;

LabelInstruction::LabelInstruction(vector<string> args): IInstruction(args) {}

void LabelInstruction::run(State &s) {
    s.label(args[0], s.where());
    s.next();
}

string LabelInstruction::to_string() {
    return "LABEL " + args[0];
}
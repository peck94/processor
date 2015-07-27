//
//  IfThenInstruction.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "IfThenInstruction.h"
#include <iostream>
using namespace std;

IfThenInstruction::IfThenInstruction(vector<string> args): IInstruction(args) {}

void IfThenInstruction::run(State &s) {
    if(s.get() == args[0][0]) {
        s.jmp(s.call(args[1]));
    }else{
        s.next();
    }
}

string IfThenInstruction::to_string() {
    return "IF " + args[0] + " THEN " + args[1];
}
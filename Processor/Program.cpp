//
//  Program.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "Program.h"
#include <iostream>
using namespace std;

void Program::addInstruction(IInstruction *inst) {
    counts[(unsigned int)instructions.size()] = 0;
    instructions.push_back(inst);
}

void Program::run(State &s, string input, bool verbose, bool very_verbose) {
    s.inc();
    for(int i = 0; i < input.length(); i++) {
        s.set(input[i]);
        s.inc();
    }
    s.memset(1);
    
    cout << "Input: " << endl;
    cout << s.print() << endl;
    
    unsigned int count = 0;
    s.jmp(0);
    while(!s.isHalted()) {
        if(very_verbose) {
            cerr << "line " << s.where() << ": " << instructions[s.where()]->to_string() << endl;
        }
        count++;
        counts[s.where()]++;
        instructions[s.where()]->run(s);
    }
    
    cout << "Output: " << endl;
    cout << s.print() << endl;
    
    // stats
    if(verbose) {
        cerr << "Cycle count: " << count << endl;
        for(pair<unsigned int, unsigned int> p: counts) {
            cerr << "Line " << p.first << ": " << p.second << " (" << 100*p.second/count << "%)" << endl;
        }
    }
}
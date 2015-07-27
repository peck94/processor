//
//  Compiler.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "Compiler.h"
#include <iostream>
using namespace std;

Compiler::Compiler(State &s): s(s) {
    lines["OUT (.*)$"] = [] (vector<string> args) {
        return new OutInstruction(args);
    };
    lines["INC"] = [] (vector<string> args) {
        return new IncInstruction(args);
    };
    lines["DEC"] = [] (vector<string> args) {
        return new DecInstruction(args);
    };
    lines["IF ([^ ]+) THEN (.+)$"] = [] (vector<string> args) {
        return new IfThenInstruction(args);
    };
    lines["JMP (.+)$"] = [] (vector<string> args) {
        return new JmpInstruction(args);
    };
    lines["HALT"] = [] (vector<string> args) {
        return new HaltInstruction(args);
    };
    lines["NOP"] = [] (vector<string> args) {
        return new NopInstruction(args);
    };
    lines["LABEL (.*)$"] = [] (vector<string> args) {
        return new LabelInstruction(args);
    };
    lines["CALL (.*)$"] = [] (vector<string> args) {
        return new CallInstruction(args);
    };
    lines["RET"] = [] (vector<string> args) {
        return new ReturnInstruction(args);
    };
    
    pre.insert("LABEL (.*)$");
}

Program* Compiler::compile(vector<string> lines) {
    Program *program = new Program();
    for(int i = 0; i < lines.size(); i++) {
        string line = lines[i];
        bool found = false;
        s.jmp(i);
        for(pair<string, factory> p: this->lines) {
            IInstruction *inst;
            regex r(p.first);
            if(regex_match(line, r)) {
                found = true;
                
                smatch result;
                vector<string> args;
                regex_search(line, result, r);
                
                for(int i = 1; i < result.size(); i++) {
                    args.push_back(result[i].str());
                }

                inst = p.second(args);
                program->addInstruction(inst);
                
                if(pre.find(p.first) != pre.end()) {
                    inst->run(s);
                }
            }
        }
        if(!found) {
            cerr << "Invalid opcode on line " << i << ": " << line << endl;
            delete program;
            return nullptr;
        }
    }
    
    s.jmp(0);
    return program;
}
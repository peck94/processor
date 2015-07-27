//
//  main.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Compiler.h"
#include "Program.h"
#include "State.h"
using namespace std;

int main(int argc, const char * argv[]) {
    if(argc < 3) {
        cerr << "Usage: " << argv[0] << " <file> <args> [verbose] [very-verbose]" << endl;
        return 1;
    }
    
    bool verbose = (argc >= 4);
    bool very_verbose = (argc >= 5);
    
    ifstream file(argv[1], ios_base::in);
    if(!file.is_open()) {
        cerr << "Cannot open file: " << argv[1] << endl;
        return 1;
    }
    
    vector<string> lines;
    while(!file.eof()) {
        string line;
        getline(file, line);
        if(line.length() > 0 && line[0] != ';') {
            lines.push_back(line);
        }else{
            lines.push_back("NOP");
        }
    }

    file.close();
    
    State s(512);
    Compiler *c = new Compiler(s);
    Program *p = c->compile(lines);
    if(p) {
        p->run(s, argv[2], verbose, very_verbose);
        delete p;
    }
    delete c;

    return 0;
}

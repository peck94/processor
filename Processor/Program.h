//
//  Program.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__Program__
#define __Processor__Program__

#include "State.h"
#include "IInstruction.h"
#include <vector>
#include <map>
#include <regex>

class Program {
private:
    std::vector<IInstruction*> instructions;
    std::map<unsigned int, unsigned int> counts;

public:
    Program() = default;
    
    void addInstruction(IInstruction*);
    void run(State&, std::string, bool, bool);
};

#endif /* defined(__Processor__Program__) */

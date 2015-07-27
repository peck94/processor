//
//  IInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef Processor_IInstruction_h
#define Processor_IInstruction_h

#include "State.h"
#include <vector>
#include <string>

class IInstruction {
protected:
    std::vector<std::string> args;
    
public:
    IInstruction(std::vector<std::string> args) {
        this->args = args;
    }
    
    virtual void run(State&) = 0;
    virtual std::string to_string() = 0;
};

#endif

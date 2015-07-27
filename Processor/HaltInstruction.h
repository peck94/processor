//
//  HaltInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__HaltInstruction__
#define __Processor__HaltInstruction__

#include "IInstruction.h"

class HaltInstruction: public IInstruction {
public:
    HaltInstruction(std::vector<std::string> args);
    
    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__HaltInstruction__) */

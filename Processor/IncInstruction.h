//
//  IncInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__IncInstruction__
#define __Processor__IncInstruction__

#include "IInstruction.h"

class IncInstruction: public IInstruction {
public:
    IncInstruction(std::vector<std::string> args);
    
    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__IncInstruction__) */

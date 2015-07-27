//
//  IfThenInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__IfThenInstruction__
#define __Processor__IfThenInstruction__

#include "IInstruction.h"

class IfThenInstruction: public IInstruction {
public:
    IfThenInstruction(std::vector<std::string> args);
    
    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__IfThenInstruction__) */

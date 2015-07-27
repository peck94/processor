//
//  JmpInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__JmpInstruction__
#define __Processor__JmpInstruction__

#include "IInstruction.h"

class JmpInstruction: public IInstruction {
public:
    JmpInstruction(std::vector<std::string> args);
    
    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__JmpInstruction__) */

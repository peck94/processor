//
//  CallInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__CallInstruction__
#define __Processor__CallInstruction__

#include "IInstruction.h"

class CallInstruction: public IInstruction {
public:
    CallInstruction(std::vector<std::string>);
    
    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__CallInstruction__) */

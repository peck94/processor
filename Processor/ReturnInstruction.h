//
//  ReturnInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__ReturnInstruction__
#define __Processor__ReturnInstruction__

#include "IInstruction.h"

class ReturnInstruction: public IInstruction {
public:
    ReturnInstruction(std::vector<std::string>);
    
    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__ReturnInstruction__) */

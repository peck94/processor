//
//  NopInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__NopInstruction__
#define __Processor__NopInstruction__

#include "IInstruction.h"

class NopInstruction: public IInstruction {
public:
    NopInstruction(std::vector<std::string>);

    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__NopInstruction__) */

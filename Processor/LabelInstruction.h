//
//  LabelInstruction.h
//  Processor
//
//  Created by Jonathan Peck on 24/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__LabelInstruction__
#define __Processor__LabelInstruction__

#include "IInstruction.h"

class LabelInstruction: public IInstruction {
public:
    LabelInstruction(std::vector<std::string>);
    
    virtual void run(State&);
    virtual std::string to_string();
};

#endif /* defined(__Processor__LabelInstruction__) */

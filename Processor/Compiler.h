//
//  Compiler.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__Compiler__
#define __Processor__Compiler__

#include "Program.h"
#include "OutInstruction.h"
#include "IncInstruction.h"
#include "DecInstruction.h"
#include "IfThenInstruction.h"
#include "JmpInstruction.h"
#include "HaltInstruction.h"
#include "NopInstruction.h"
#include "LabelInstruction.h"
#include "CallInstruction.h"
#include "ReturnInstruction.h"
#include <map>
#include <set>
#include <regex>
#include <functional>

typedef std::function<IInstruction*(std::vector<std::string>)> factory;

class Compiler {
private:
    std::map<std::string, factory> lines;
    std::set<std::string> pre;
    State &s;

public:
    Compiler(State&);
    
    Program* compile(std::vector<std::string>);
};

#endif /* defined(__Processor__Compiler__) */

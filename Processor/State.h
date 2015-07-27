//
//  State.h
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#ifndef __Processor__State__
#define __Processor__State__

#include <string>
#include <map>
#include <stack>

class State {
private:
    unsigned char *memory;
    unsigned int space;
    unsigned int memptr;
    unsigned int instptr;
    bool halted;
    std::map<std::string, unsigned int> labels;
    std::stack<unsigned int> s;

public:
    State(unsigned int);
    
    // set memory contents
    void set(unsigned char);
    // get memory contents
    unsigned char get();
    
    // increase memory pointer
    void inc();
    // decrease memory pointer
    void dec();
    // set memory pointer
    void memset(unsigned int);
    
    // jump to instruction
    void jmp(unsigned int);
    
    // get current instruction pointer
    unsigned int where();
    // increment instruction pointer
    void next();
    
    // print memory
    std::string print();
    
    // halt program
    void halt();
    // check if halted
    bool isHalted();
    
    // assign labels to lines
    void label(std::string, unsigned int);
    // get label line
    unsigned int call(std::string);
    
    // push to stack
    void push();
    // pop from stack
    unsigned int pop();
    
    ~State();
};

#endif /* defined(__Processor__State__) */

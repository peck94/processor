//
//  State.cpp
//  Processor
//
//  Created by Jonathan Peck on 23/07/15.
//  Copyright (c) 2015 Jonathan Peck. All rights reserved.
//

#include "State.h"
using namespace std;

State::State(unsigned int space) {
    this->space = space;
    this->memptr = 0;
    this->memory = new unsigned char[space];
    this->halted = false;
    
    for(int i = 0; i < space; i++) {
        this->memory[i] = '.';
    }
}

void State::set(unsigned char value) {
    this->memory[this->memptr] = value;
}

unsigned char State::get() {
    return this->memory[this->memptr];
}

void State::inc() {
    if(this->memptr < space) {
        this->memptr++;
    }
}

void State::dec() {
    if(this->memptr > 0) {
        this->memptr--;
    }
}

void State::memset(unsigned int index) {
    if(index < space) {
        this->memptr = index;
    }
}

void State::jmp(unsigned int ptr) {
    this->instptr = ptr;
}

unsigned int State::where() {
    return this->instptr;
}

void State::next() {
    this->instptr++;
}

string State::print() {
    string s = "";
    for(int i = 0; i < this->space; i++) {
        s+= memory[i];
    }
    
    return s;
}

void State::halt() {
    halted = true;
}

bool State::isHalted() {
    return halted;
}

void State::label(string name, unsigned int line) {
    labels[name] = line;
}

unsigned int State::call(string name) {
    return labels[name];
}

void State::push() {
    s.push(where()+1);
}

unsigned int State::pop() {
    unsigned int r = s.top();
    s.pop();
    
    return r;
}

State::~State() {
    delete[] this->memory;
}
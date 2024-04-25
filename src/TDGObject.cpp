//
// Created by bear on 4/19/24.
//

#include "TDGObject.h"

int TDGObject::count = 0;

TDGObject::TDGObject(TDGObject* const parent, const char* name) : name(name) {
    if (parent) {
        parent->insertChild(this);
    }
    count++;
    INFO(std::string("Added a child ")+std::to_string(count));
}

TDGObject::~TDGObject() {
    // Murder the children
    for(auto itr=std::begin(children); itr!=std::end(children);) {
        delete *itr;
        itr = children.erase(itr);
        count--;
        INFO(std::string("Removed a child ")+std::to_string(count));
    }
}

void TDGObject::insertChild(TDGObject* const child) {
    children.push_back(child);
}

void TDGObject::removeChild(TDGObject* const child) {
    children.remove(child);
}


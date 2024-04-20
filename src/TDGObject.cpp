//
// Created by bear on 4/19/24.
//

#include "TDGObject.h"


TDGObject::TDGObject(TDGObject* const parent, const char* name) : name(name) {
    if (parent) {
        parent->insertChild(this);
    }

}

TDGObject::~TDGObject() {
    // Murder the children
    for(auto itr=std::begin(children); itr!=std::end(children);) {
        delete *itr;
        itr = children.erase(itr);
    }
}

void TDGObject::insertChild(TDGObject* const child) {
    children.push_back(child);
}

void TDGObject::removeChild(TDGObject* const child) {
    children.remove(child);
}


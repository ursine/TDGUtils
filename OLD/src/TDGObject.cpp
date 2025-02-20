//
// Created by bear on 4/19/24.
//

#include "TDGObject.h"

int TDGObject::count = 0;

TDGObject::TDGObject(TDGObject* const parent, const char* name) :
    parent(nullptr), name(name ? std::string(name) : "nullptr")
{
    if (parent) {
        parent->insertChild(this);
        count++;
        std::string cName = name;
        std::string pName = parent->name;
        INFO(std::string("Added a child ")+std::to_string(count)+"' name '"+cName+"' to parent '"+pName+"'");
    }
}

TDGObject::~TDGObject() {
    INFO("Object destructor '"+name+"' Children "+std::to_string(children.size())+" of "+std::to_string(count));
    // Murder the children
    int c = 0;
    while(!children.empty()) {
        delete children.front();
    }
    count--;
    if (parent) {
        parent->removeChild(this);
    }
    INFO("Completed destruction of '"+name+"'");
}

void TDGObject::insertChild(TDGObject* const child) {
    child->parent = this;
    children.push_back(child);
}

void TDGObject::removeChild(TDGObject* const child) {
    children.remove(child);
    child->parent = nullptr;
}


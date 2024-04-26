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
    INFO("Widget destructor '"+name+"' Children "+std::to_string(children.size()));
    // Murder the children
    int c = 0;
    for(auto itr=std::begin(children); itr!=std::end(children);) {
        auto obj = (*itr);

        INFO("Removing "+std::to_string(c++));

        obj->parent = nullptr;
        delete *itr;
        itr = children.erase(itr);
        count--;
        INFO(std::string("Removed a child ")+std::to_string(count));
    }
}

void TDGObject::insertChild(TDGObject* const child) {
    child->parent = this;
    children.push_back(child);
}

void TDGObject::removeChild(TDGObject* const child) {
    children.remove(child);
    child->parent = nullptr;
}


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

}


static std::list<TDGObject*> orphanObjects;
static void insertOrphan(TDGObject* obj) {
    orphanObjects.push_back(obj);
}

static void removeOrphan(TDGObject* obj) {
    orphanObjects.remove(obj);
}

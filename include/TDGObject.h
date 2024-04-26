//
// Created by bear on 4/19/24.
//

#pragma once

#include "TDGLog.h"

#include <string>
#include <list>


class TDGObject {
private:
    std::string name;

    std::list<TDGObject*> children;
    TDGObject* parent;

    static int count;

public:
    explicit TDGObject(TDGObject* parent = nullptr, const char* name = nullptr);
    virtual ~TDGObject();

    void setName(const char* n) {name = n;}

    virtual void insertChild(TDGObject* child);
    virtual void removeChild(TDGObject* child);

    [[nodiscard]] inline std::string getName() const { return name; }
    [[nodiscard]] inline TDGObject* getParent() const { return parent; }
};


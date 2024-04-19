//
// Created by bear on 4/19/24.
//

#pragma once

#include <string>
#include <list>

class TDGObject {
private:
    std::string name;

    std::list<TDGObject*> children;

public:
    explicit TDGObject(TDGObject* parent = nullptr, const char* name = nullptr);
    virtual ~TDGObject();

    [[nodiscard]] const std::string& getName() const {return name;}
    void setName(const std::string& n) {name = n;}

    virtual void insertChild(TDGObject* child);
    virtual void removeChild(TDGObject* child);

};


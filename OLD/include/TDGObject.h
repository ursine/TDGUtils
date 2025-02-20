//
// Created by bear on 4/19/24.
//

#pragma once

#include "TDGLog.h"

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <iterator>


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

    [[nodiscard]] inline std::list<TDGObject*> getChildren() const { return children; }

    [[nodiscard]] std::string getTree() const {
        std::stringstream ss;
        getTree(ss, 0);
        return ss.str();
    }

    void getTree(std::stringstream& ss, const int space) const {
        std::fill_n(std::ostream_iterator<std::string>(ss), space*2, " ");
        ss << name << std::endl;
        for (auto& child : children) {
            child->getTree(ss, space+1);
        }
    }

};


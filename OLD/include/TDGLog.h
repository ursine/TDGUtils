//
// Created by bear on 4/25/24.
//

#pragma once

#include <iostream>
#include <string>
#include <source_location>

class TDGLog {
private:
    static TDGLog* instance;

    TDGLog() = default;

public:
    static TDGLog* getInstance() {
        if (!instance) {
            instance = new TDGLog();
        }
        return instance;
    }

    void info(const std::string& s, const std::source_location loc = std::source_location::current()) {
        std::cout << "[" << loc.file_name() << ":" << loc.line() << ":" << loc.function_name() << "] " << s << std::endl;
    }
};

#define INFO(X) TDGLog::getInstance()->info(X);

//
// Created by bear on 4/26/24.
//

#pragma once

#include "TDGObject.h"
#include <cstdint>
#include <SDL_video.h>

enum WidgetFlags : uint32_t {
    WF_NONE      = 0b00000000000000000000000000000000,
    WF_TOP_LEVEL = 0b00000000000000000000000000000001,
};

class TDGWidget : public TDGObject {
private:
    SDL_Window* appWindow = nullptr;

public:
    explicit TDGWidget(TDGObject* parent = nullptr, const char* name = nullptr,
                       const uint32_t flags = WidgetFlags::WF_NONE):
        TDGObject(parent, name)
    {
        appWindow = SDL_CreateWindow("SDL Tutorial",
                                     SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,
                                     1,
                                     1,
                                     SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

        if (appWindow== nullptr) {
            throw std::runtime_error(std::string("Window could not be created! SDL_Error: ")+ SDL_GetError());
        }
    }

    ~TDGWidget() override {
        INFO("Widget destructor '"+getName()+"'");
        //Destroy window
        if (getParent()) {
            getParent()->removeChild(this);
        }
        SDL_DestroyWindow(appWindow);
    }

};
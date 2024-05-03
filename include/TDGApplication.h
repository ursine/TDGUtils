//
// Created by bear on 4/12/24.
//

#pragma once

#include <SDL.h>
#include <system_error>
#include <TDGReflection.h>
#include <iostream>
#include <map>
#include <TDGLog.h>


//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

class TDGWidget;
class TDGApplication;

extern TDGApplication* tdgApp;

class TDGApplication {
private:
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;

    TDGWidget* primaryWidget = nullptr;

public:
    TDGApplication(int argc, char* args[]) {
        tdgApp = this;

        //Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw std::runtime_error(std::string("SDL could not initialize! SDL_Error: ")+SDL_GetError());
        }

        SDL_version sdlVersion;
        SDL_VERSION(&sdlVersion);
        INFO("Compiled with SDL Version "+std::to_string(sdlVersion.major)+
             "."+std::to_string(sdlVersion.minor)+"."+std::to_string(sdlVersion.patch));

        SDL_GetVersion(&sdlVersion);
        INFO("Using SDL Version "+std::to_string(sdlVersion.major)+
             "."+std::to_string(sdlVersion.minor)+"."+std::to_string(sdlVersion.patch));

        const int cpus = SDL_GetCPUCount();

    }

    ~TDGApplication() {
        SDL_Quit();
    }

    void setPrimaryWidget(TDGWidget* const w) {
        primaryWidget = w;
    }

    int exec() {return 0;}
};


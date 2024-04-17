//
// Created by bear on 4/12/24.
//

#pragma once

#include <SDL.h>
#include <system_error>
#include <TDGReflection.h>
#include <iostream>

//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

class TDGApplication {
private:
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;

    SDL_Window* appWindow = nullptr;

public:
    TDGApplication(int argc, char* args[]) {
        //Initialize SDL
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw std::runtime_error(std::string("SDL could not initialize! SDL_Error: ")+SDL_GetError());
        }

        appWindow = SDL_CreateWindow("SDL Tutorial",
                                              SDL_WINDOWPOS_UNDEFINED,
                                              SDL_WINDOWPOS_UNDEFINED,
                                              width,
                                              height,
                                              SDL_WINDOW_SHOWN);

        std::cout << TDG::internal::get_type_name<decltype(this)>() << std::endl;

        if (appWindow== nullptr) {
            throw std::runtime_error(std::string("Window could not be created! SDL_Error: ")+ SDL_GetError());
        }

    }

    ~TDGApplication() {
        //Destroy window
        SDL_DestroyWindow(appWindow);

        //Quit SDL subsystems
        SDL_Quit();
    }

    [[nodiscard]] SDL_Window* window() const {return appWindow;}

    int exec() {return 0;}
};


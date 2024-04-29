//
// Created by bear on 4/12/24.
//
//Using SDL and standard IO

#include <SDL.h>
#include <cstdio>
#include <iostream>
#include "TDGApplication.h"
#include "TDGSDLEventsDebugging.h"
#include "TDGLog.h"
#include "TDGWidget.h"

int main(int argc, char* args[]) {

    TDGApplication app(argc, args);

    INFO("Starting application");

    TDGWidget main(nullptr, "main");
    TDGWidget extra1(&main, "extra1");
    auto extra2 = new TDGWidget(&main, "extra2");
    auto extra3 = new TDGWidget(&main, "extra3");
    auto extra4 = new TDGWidget(&main, "extra4");
    auto extra5 = new TDGWidget(&main, "extra5");
    auto extra6 = new TDGWidget(&main, "extra6");
    auto extra7 = new TDGWidget(&main, "extra7");

    auto extra8 = new TDGWidget(extra3, "extra8");
    auto extra9 = new TDGWidget(extra3, "extra9");

    auto extra10 = new TDGWidget(extra8, "extra10");

    std::cout << main.getTree() << std::endl;

    app.exec();

    /*SDL_Window* window = app.window();
        //Create window

            //Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    //Fill the surface white
    SDL_FillRect(screenSurface, nullptr,
                 SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

    //Update the surface
    SDL_UpdateWindowSurface(window);

    //Hack to get window to stay up
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            printf("Type: %s\n", TDG::sdlEvent2string(&e).c_str());
            if (e.type == SDL_QUIT) quit = true;
        }
    }*/

    return EXIT_SUCCESS;
}
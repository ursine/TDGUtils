//
// Created by bear on 4/12/24.
//
//Using SDL and standard IO

#include <SDL.h>
#include <cstdio>
#include "TDGApplication.h"
#include "TDGSDLEventsDebugging.h"

int main(int argc, char* args[]) {

    TDGApplication app(argc, args);

    app.exec();

    //The surface contained by the window
    SDL_Surface* screenSurface = nullptr;

    SDL_Window* window = app.window();
        //Create window

            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);

            //Fill the surface white
            SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

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
            }





    return 0;
}
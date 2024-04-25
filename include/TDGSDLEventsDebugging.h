//
// Created by bear on 4/12/24.
//

#pragma once

#include <SDL.h>
#include <string>
#include <sstream>

#define SDLCASE(X) case X: {ss << #X;} break
#define SDLCASE2(X,Y) case X: {ss << #X; ss << SDLEventDetails(&e->Y).brackets();} break
#define SDLED_START(X) explicit SDLEventDetails(const X* const e) { eventObject = #X; \
  ss << "Type: " << e->type; ss << " Timestamp: " << e->timestamp
#define SDLED_END() }

namespace TDG {

    class SDLEventDetails {
    private:
        std::stringstream ss;
        std::string eventObject;

    public:
        explicit SDLEventDetails(const SDL_Event* const e) {
            auto t = e->type;
            switch(t) {
                SDLCASE(SDL_FIRSTEVENT);
                SDLCASE2(SDL_QUIT, quit);
                SDLCASE(SDL_APP_TERMINATING);
                SDLCASE(SDL_APP_LOWMEMORY);
                SDLCASE(SDL_APP_WILLENTERBACKGROUND);
                SDLCASE(SDL_APP_DIDENTERBACKGROUND);
                SDLCASE(SDL_APP_WILLENTERFOREGROUND);
                SDLCASE(SDL_APP_DIDENTERFOREGROUND);
                SDLCASE(SDL_LOCALECHANGED);
                SDLCASE(SDL_DISPLAYEVENT);
                SDLCASE2(SDL_WINDOWEVENT, window);
                SDLCASE(SDL_SYSWMEVENT);
                SDLCASE(SDL_KEYDOWN);
                SDLCASE(SDL_KEYUP);
                SDLCASE2(SDL_TEXTEDITING, edit);
                SDLCASE(SDL_TEXTINPUT);
                SDLCASE(SDL_KEYMAPCHANGED);
                //SDLCASE(SDL_TEXTEDITING_EXT);
                SDLCASE2(SDL_MOUSEMOTION, motion);
                SDLCASE(SDL_MOUSEBUTTONDOWN);
                SDLCASE(SDL_MOUSEBUTTONUP);
                SDLCASE(SDL_MOUSEWHEEL);
                SDLCASE(SDL_JOYAXISMOTION);
                SDLCASE(SDL_JOYBALLMOTION);
                SDLCASE(SDL_JOYHATMOTION);
                SDLCASE(SDL_JOYBUTTONDOWN);
                SDLCASE(SDL_JOYBUTTONUP);
                SDLCASE(SDL_JOYDEVICEADDED);
                SDLCASE(SDL_JOYDEVICEREMOVED);
                //SDLCASE(SDL_JOYBATTERYUPDATED);
                SDLCASE(SDL_CONTROLLERAXISMOTION);
                SDLCASE(SDL_CONTROLLERBUTTONDOWN);
                SDLCASE(SDL_CONTROLLERBUTTONUP);
                SDLCASE(SDL_CONTROLLERDEVICEADDED);
                SDLCASE(SDL_CONTROLLERDEVICEREMOVED);
                SDLCASE(SDL_CONTROLLERDEVICEREMAPPED);
                SDLCASE(SDL_CONTROLLERTOUCHPADDOWN);
                SDLCASE(SDL_CONTROLLERTOUCHPADMOTION);
                SDLCASE(SDL_CONTROLLERTOUCHPADUP);
                SDLCASE(SDL_CONTROLLERSENSORUPDATE);
                SDLCASE(SDL_FINGERDOWN);
                SDLCASE(SDL_FINGERUP);
                SDLCASE(SDL_FINGERMOTION);
                SDLCASE(SDL_DOLLARGESTURE);
                SDLCASE(SDL_DOLLARRECORD);
                SDLCASE(SDL_MULTIGESTURE);
                SDLCASE(SDL_CLIPBOARDUPDATE);
                SDLCASE(SDL_DROPFILE);
                SDLCASE(SDL_DROPTEXT);
                SDLCASE(SDL_DROPBEGIN);
                SDLCASE(SDL_DROPCOMPLETE);
                SDLCASE(SDL_AUDIODEVICEADDED);
                SDLCASE(SDL_AUDIODEVICEREMOVED);
                SDLCASE(SDL_SENSORUPDATE);
                SDLCASE(SDL_RENDER_TARGETS_RESET);
                SDLCASE(SDL_RENDER_DEVICE_RESET);
                SDLCASE(SDL_POLLSENTINEL);
                SDLCASE(SDL_USEREVENT);
                SDLCASE(SDL_LASTEVENT);
                default:
                    break;
            }
        }
        std::string str() { return ss.str(); }

    private:
        SDLED_START(SDL_CommonEvent);
        SDLED_END();

        SDLED_START(SDL_DisplayEvent);
            ss << " Display: " << e->display;
            ss << " Event: " << e->event;
            ss << " Data1: " << e->data1;
        SDLED_END();

        SDLED_START(SDL_WindowEvent);
            ss << " WindowsID: " << e->windowID;
            ss << " Event: " << static_cast<int>(e->event);
            ss << " Data1: " << e->data1;
            ss << " Data2: " << e->data2;
        SDLED_END();

        explicit SDLEventDetails(const SDL_KeyboardEvent* const e) {}

        explicit SDLEventDetails(const SDL_TextEditingEvent* const e) {
            eventObject = "SDL_WindowEvent";
            ss << "Type: " << e->type;
            ss << " Timestamp: " << e->timestamp;
            ss << " WindowsID: " << e->windowID;
            ss << " Text: " << e->text;
            ss << " Start: " << e->start;
            ss << " Length: " << e->length;
        }

        //explicit SDLEventDetails(const SDL_TextEditingExtEvent* const editExt) {}

        explicit SDLEventDetails(const SDL_TextInputEvent* const text) {}

        explicit SDLEventDetails(const SDL_MouseMotionEvent* const m) {
            eventObject = "SDL_MouseMotionEvent";
            ss << "Type: " << m->type;
            ss << " Timestamp: " << m->timestamp;
            ss << " WindowsID: " << m->windowID;
            ss << " Which: " << static_cast<int>(m->which);
            ss << " State: " << m->state;
            ss << " x: " << m->x;
            ss << " y: " << m->y;
            ss << " xrel: " << m->xrel;
            ss << " yrel: " << m->yrel;
        }

        explicit SDLEventDetails(const SDL_MouseButtonEvent* const button) {}

        explicit SDLEventDetails(const SDL_MouseWheelEvent* const wheel) {}

        explicit SDLEventDetails(const SDL_JoyAxisEvent* const jaxis) {}

        explicit SDLEventDetails(const SDL_JoyBallEvent* const jball) {}

        explicit SDLEventDetails(const SDL_JoyHatEvent* const jhat) {}

        explicit SDLEventDetails(const SDL_JoyButtonEvent* const jbutton) {}

        explicit SDLEventDetails(const SDL_JoyDeviceEvent* const jdevice) {}

        //explicit SDLEventDetails(const SDL_JoyBatteryEvent* const jbattery) {}

        explicit SDLEventDetails(const SDL_ControllerAxisEvent* const caxis) {}

        explicit SDLEventDetails(const SDL_ControllerButtonEvent* const cbutton) {}

        explicit SDLEventDetails(const SDL_ControllerDeviceEvent* const cdevice) {}

        explicit SDLEventDetails(const SDL_ControllerTouchpadEvent* const ctouchpad) {}

        explicit SDLEventDetails(const SDL_ControllerSensorEvent* const csensor) {}

        explicit SDLEventDetails(const SDL_AudioDeviceEvent* const adevice) {}

        explicit SDLEventDetails(const SDL_SensorEvent* const sensor) {}

        explicit SDLEventDetails(const SDL_QuitEvent* const quit) {
            eventObject = "SDL_QuitEvent";
            ss << "Type: " << quit->type << " Timestamp: " << quit->timestamp << ")";
        }

        explicit SDLEventDetails(const SDL_UserEvent* const user) {}

        explicit SDLEventDetails(const SDL_SysWMEvent* const syswm) {}

        explicit SDLEventDetails(const SDL_TouchFingerEvent* const tfinger) {}

        explicit SDLEventDetails(const SDL_MultiGestureEvent* const mgesture) {}

        explicit SDLEventDetails(const SDL_DollarGestureEvent* const dgesture) {}

        explicit SDLEventDetails(const SDL_DropEvent* const drop) {}

        std::string brackets() {
            return "[" + eventObject + "(" + ss.str() + ")]";
        }
    };


    std::string sdlEvent2string(const SDL_Event* const e) {
        return SDLEventDetails(e).str();
    }
}

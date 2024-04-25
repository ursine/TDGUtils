//
// Created by bear on 4/12/24.
//

#pragma once

#include <SDL.h>
#include <string>
#include <sstream>

#define SDLCASE(X) case X: ss << #X; break

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
                case SDL_QUIT:
                    ss << "SDL_QUIT";
                    ss << SDLEventDetails(&e->quit).brackets();
                    break;
                SDLCASE(SDL_APP_TERMINATING);
                SDLCASE(SDL_APP_LOWMEMORY);
                SDLCASE(SDL_APP_WILLENTERBACKGROUND);
                SDLCASE(SDL_APP_DIDENTERBACKGROUND);
                SDLCASE(SDL_APP_WILLENTERFOREGROUND);
                SDLCASE(SDL_APP_DIDENTERFOREGROUND);
                SDLCASE(SDL_LOCALECHANGED);
                SDLCASE(SDL_DISPLAYEVENT);
                case SDL_WINDOWEVENT:
                    ss << "SDL_WINDOWEVENT";
                    ss << SDLEventDetails(&e->window).brackets();
                    break;
                SDLCASE(SDL_SYSWMEVENT);
                SDLCASE(SDL_KEYDOWN);
                SDLCASE(SDL_KEYUP);
                SDLCASE(SDL_TEXTEDITING);
                SDLCASE(SDL_TEXTINPUT);
                SDLCASE(SDL_KEYMAPCHANGED);
                //SDLCASE(SDL_TEXTEDITING_EXT);
                SDLCASE(SDL_MOUSEMOTION);
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
        explicit SDLEventDetails(const SDL_CommonEvent* const e) {
            eventObject = "SDL_CommonEvent";
            ss << "Type: " << e->type;
            ss << " Timestamp: " << e->timestamp;
        }
        explicit SDLEventDetails(const SDL_DisplayEvent* const e) {
            eventObject = "SDL_DisplayEvent";
            ss << "Type: " << e->type;
            ss << " Timestamp: " << e->timestamp;
            ss << " Display: " << e->display;
            ss << " Event: " << e->event;
            ss << " Data1: " << e->data1;
        }
        explicit SDLEventDetails(const SDL_WindowEvent* const e) {
            eventObject = "SDL_WindowEvent";
            ss << "Type: " << e->type;
            ss << " Timestamp: " << e->timestamp;
            ss << " WindowsID: " << e->windowID;
            ss << " Event: " << static_cast<int>(e->event);
            ss << " Data1: " << e->data1;
            ss << " Data2: " << e->data2;
        }
        explicit SDLEventDetails(const SDL_KeyboardEvent* const e) {}
        explicit SDLEventDetails(const SDL_TextEditingEvent* const edit) {}
        //explicit SDLEventDetails(const SDL_TextEditingExtEvent* const editExt) {}
        explicit SDLEventDetails(const SDL_TextInputEvent* const text) {}
        explicit SDLEventDetails(const SDL_MouseMotionEvent* const motion) {}
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

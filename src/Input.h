#pragma once

#include <map>

#include "SDL.h"

namespace one
{
    class Input
    {
        public:
            Input()
                : mQuitEvent(false)
            {
            }

            void Update();

            bool IsKeyPressed(SDL_Keycode key);
            bool IsKeyReleased(SDL_Keycode key);
            bool IsKeyHeld(SDL_Keycode key);

            bool WasQuitEvent() { return mQuitEvent; }

        private:
            std::map<SDL_Keycode, bool> mHeldKeys;
            std::map<SDL_Keycode, bool> mPressedKeys;
            std::map<SDL_Keycode, bool> mReleasedKeys;

            bool mQuitEvent;
    };
}

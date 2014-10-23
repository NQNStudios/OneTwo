#include "Input.h"

void one::Input::Update()
{
    mPressedKeys.clear();
    mReleasedKeys.clear();

    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                mQuitEvent = true;
                break;

            case SDL_KEYDOWN:
                if (!event.key.repeat)
                {
                    mPressedKeys[event.key.keysym.sym] = true;
                    mHeldKeys[event.key.keysym.sym] = true;
                }
                break;

            case SDL_KEYUP:
                if (!event.key.repeat)
                {
                    mReleasedKeys[event.key.keysym.sym] = true;
                    mHeldKeys[event.key.keysym.sym] = false;
                }
                break;
        }
    }
}

bool one::Input::IsKeyPressed(SDL_Keycode key)
{
    return mPressedKeys[key];
}

bool one::Input::IsKeyReleased(SDL_Keycode key)
{
    return mReleasedKeys[key];
}

bool one::Input::IsKeyHeld(SDL_Keycode key)
{
    return mHeldKeys[key];
}

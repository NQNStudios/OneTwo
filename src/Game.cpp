#include "Game.h"

#include <iostream>
#include <string>

#include "LevelState.h"

namespace
{
    const int TARGET_FPS = 60;
    const int TARGET_MS_PER_FRAME = 1000 / TARGET_FPS;
    const int MAX_MS_PER_FRAME = 5 * TARGET_MS_PER_FRAME;
}

one::Game::Game()
    : mRunning(false)
{
}

one::Game::~Game()
{
}

void one::Game::Run()
{
    mRunning = true;

    one::Graphics graphics;
    one::Input input;

    this->LoadContent(graphics);

    int lastMS = SDL_GetTicks();

    while (mRunning)
    {
        const int startMS = SDL_GetTicks();

        input.Update();

        const int currentMS = SDL_GetTicks();

        const int deltaMS = currentMS - lastMS;

        this->Update(std::min(deltaMS, MAX_MS_PER_FRAME), input);
        lastMS = currentMS;

        this->Draw(graphics);

        const int elapsedMS = SDL_GetTicks() - startMS;

        if (elapsedMS < TARGET_MS_PER_FRAME)
        {
            SDL_Delay(TARGET_MS_PER_FRAME - elapsedMS);
        }

        if (input.WasQuitEvent())
        {
            Quit();
        }
    }
}

void one::Game::LoadContent(one::Graphics& graphics)
{
    graphics.LoadSpritesheet("tiles", "assets/tiles.png");
    graphics.LoadSpritesheet("sprites", "assets/sprites.png");

    SetState(LevelState::FromLevel(this, 1));

    //SetState(LevelState::FromFile(this, "assets/levels/01.one"));
}

void one::Game::Update(int deltaMS, one::Input& input)
{
    mState->Update(deltaMS, input);
}

void one::Game::Draw(one::Graphics& graphics)
{
    graphics.Clear();

    mState->Draw(graphics);

    graphics.Update();
}

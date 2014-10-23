#include "Game.h"

#include <iostream>
#include <string>

namespace
{
    const int TARGET_FPS = 60;
    const int TARGET_MS_PER_FRAME = 1000 / TARGET_FPS;
    const int MAX_MS_PER_FRAME = 5 * TARGET_MS_PER_FRAME;
}

one::Game::Game()
    : mRunning(false)
{
    playerX = 0;
    playerY = 0;
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

        if (deltaMS < TARGET_MS_PER_FRAME)
        {
            std::cout << "Delaying: " << (TARGET_MS_PER_FRAME - elapsedMS) << std::endl;
            SDL_Delay(TARGET_MS_PER_FRAME - elapsedMS);
        }
        std::cout << "-----------------------" << std::endl;
    }
}

void one::Game::LoadContent(one::Graphics& graphics)
{
    graphics.LoadSpritesheet("test", "assets/sprites.png");
}

void one::Game::Update(int deltaMS, one::Input& input)
{
    std::cout << "Delta MS: " << deltaMS << std::endl;

    if (input.IsKeyPressed(SDLK_UP))
    {
        std::cout << "Moving up" << std::endl;

        playerY -= 1;
    }
    else if (input.IsKeyPressed(SDLK_DOWN))
    {
        std::cout << "Moving down" << std::endl;

        playerY += 1;
    }
}

void one::Game::Draw(one::Graphics& graphics)
{
    graphics.Clear();

    graphics.DrawSprite("test", 28, playerX, playerY);

    graphics.Update();
}

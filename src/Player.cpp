#include "Player.h"

#include <iostream>

namespace
{
    const int SPEED = 64;
}

one::Player::Player(Color color, int x, int y)
    : x(x), y(y), color(color), direction(NONE), speed(SPEED)
{
    switch (color)
    {
        case BLUE:
            movementKeys[UP] = SDLK_UP;
            movementKeys[DOWN] = SDLK_DOWN;
            movementKeys[LEFT] = SDLK_LEFT;
            movementKeys[RIGHT] = SDLK_RIGHT;

            sprites[NONE] = 0;
            sprites[DOWN] = 1;
            sprites[LEFT] = 2;
            sprites[UP] = 3;
            sprites[RIGHT] = 4;
            break;

        case ORANGE:
            movementKeys[UP] = SDLK_w;
            movementKeys[DOWN] = SDLK_s;
            movementKeys[LEFT] = SDLK_a;
            movementKeys[RIGHT] = SDLK_d;

            sprites[NONE] = 6;
            sprites[DOWN] = 7;
            sprites[LEFT] = 8;
            sprites[UP] = 9;
            sprites[RIGHT] = 10;
            break;
    }
}

bool one::Player::WillMove(unsigned int deltaMS, one::Input& input, one::Level level)
{
    float elapsedSec = deltaMS / 1000.0f;

    int movement = (int)(speed * elapsedSec);

    int newX = x;
    int newY = y;
    Rectangle* screenBounds = ScreenBounds();

    if (input.IsKeyHeld(movementKeys[UP]))
    {
        newY -= movement;
        screenBounds->y -= movement;
        direction = UP;
    }

    else if (input.IsKeyHeld(movementKeys[DOWN]))
    {
        newY += movement;
        screenBounds->y += movement;
        direction = DOWN;
    }

    else if (input.IsKeyHeld(movementKeys[LEFT]))
    {
        newX -= movement;
        screenBounds->x -= movement;
        direction = LEFT;
    }

    else if (input.IsKeyHeld(movementKeys[RIGHT]))
    {
        newX += movement;
        screenBounds->x += movement;
        direction = RIGHT;
    }

    else
    {
        direction = NONE;
    }

    if (newX == x && newY == y) return false; // didn't move

    else
    {
        // make sure one of the hall lines CONTAINS the player in its rectangle

        std::vector<one::Line> hallLines = level.hallLines[color];

        for (std::vector<one::Line>::iterator it = hallLines.begin(); it != hallLines.end(); ++it)
        {
            if (it->ScreenBounds()->Contains(*screenBounds))
            {
                return true;
            }
        }

        return false;
    }}

void one::Player::Update(unsigned int deltaMS, one::Input& input, one::Level level)
{
    float elapsedSec = deltaMS / 1000.0f;

    int oldX = x;
    int oldY = y;

    int movement = (int)(speed * elapsedSec);

    if (input.IsKeyHeld(movementKeys[UP]))
    {
        y -= movement;
        direction = UP;
    }

    else if (input.IsKeyHeld(movementKeys[DOWN]))
    {
        y += movement;
        direction = DOWN;
    }

    else if (input.IsKeyHeld(movementKeys[LEFT]))
    {
        x -= movement;
        direction = LEFT;
    }

    else if (input.IsKeyHeld(movementKeys[RIGHT]))
    {
        x += movement;
        direction = RIGHT;
    }

    else
    {
        direction = NONE;
    }
}

bool one::Player::IsOnExit(one::Level level)
{
    return level.exits[color].ScreenBounds()->Contains(*ScreenBounds());
}

void one::Player::Draw(one::Graphics& graphics)
{
    graphics.DrawSprite("sprites", sprites[direction], x, y);
}

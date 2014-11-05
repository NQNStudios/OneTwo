#pragma once

#include <map>

#include "SDL.h"

#include "Game.h"
#include "Color.h"
#include "Graphics.h"
#include "Input.h"
#include "Level.h"
#include "Rectangle.h"

namespace one
{
    enum Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    class Player
    {
        public:
            Player()
                : color(BLUE), x(0), y(0)
            {
            }

            Player(Color color, int x, int y);

            bool WillMove(unsigned int deltaMS, one::Input& input, one::Level level);
            void Update(unsigned int deltaMS, one::Input& input, one::Level level);
            bool IsOnExit(one::Level level);

            void Draw(Graphics& graphics);
        private:
            Color color;

            int speed;

            std::map<Direction, int> sprites;
            std::map<Direction, SDL_Keycode> movementKeys;

            Direction direction;

            Rectangle* ScreenBounds()
            {
                return new Rectangle(x, y, Game::TILE_SIZE, Game::TILE_SIZE);
            }

            int x;
            int y;
    };
}

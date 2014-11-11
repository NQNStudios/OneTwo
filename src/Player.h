#pragma once

#include <map>
#include <iostream>

#include "SDL.h"

#include "Game.h"
#include "Color.h"
#include "Graphics.h"
#include "Input.h"
#include "Level.h"
#include "Rectangle.h"
#include "Tile.h"

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

            void SetPosition(int x, int y) {
                std::cout << "SETTING A PLAYER POSITION TO (" << x << ", " << y << ")" << std::endl;
                this->x = x; this->y = y;
            }

            int GetX() { return this->x; }
            int GetY() { return this->y; }

            // convenience method
            Tile GetNearestTile() {
                int tileX = round((float) this->x / (float) Game::TILE_SIZE);
                int tileY = round((float) this->y / (float) Game::TILE_SIZE);

                return Tile(tileX, tileY);
            }

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

#pragma once

#include "Rectangle.h"
#include "Game.h"

namespace one
{
    struct Tile
    {
        public:
            unsigned int x;
            unsigned int y;
        
            Tile()
                : x(0), y(0)
            {
            }

            Tile(unsigned int x, unsigned int y)
                : x(x), y(y)
            {
            }

            Rectangle* ScreenBounds()
            {
                return new Rectangle(x * Game::TILE_SIZE, y * Game::TILE_SIZE,
                        Game::TILE_SIZE, Game::TILE_SIZE);
            }
    };
}

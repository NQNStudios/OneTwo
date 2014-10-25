#pragma once

#include "Game.h"
#include "Rectangle.h"

namespace one
{

    enum LineType
    {
        HORIZONTAL,
        VERTICAL
    };

    struct Line
    {
        public:
            unsigned int x;
            unsigned int y;
            unsigned int length;
            LineType type;

            Line(unsigned int x, unsigned int y, unsigned int l, LineType type)
                : x(x), y(y), length(l), type(type)
            {
            }

            Rectangle* ScreenBounds()
            {
                unsigned int w = Game::TILE_SIZE;
                unsigned int h = Game::TILE_SIZE;

                switch (type)
                {
                    case HORIZONTAL:
                        w *= length;
                        break;

                    case VERTICAL:
                        h *= length;
                        break;
                }

                return new Rectangle(x * Game::TILE_SIZE, y * Game::TILE_SIZE, w, h);
            }
    };

}

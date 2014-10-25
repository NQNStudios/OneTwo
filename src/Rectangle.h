#pragma once

namespace one
{

    struct Rectangle
    {
        public:
            unsigned int x;
            unsigned int y;
            unsigned int width;
            unsigned int height;

            Rectangle(unsigned int x, unsigned int y, unsigned int w, unsigned int h)
                : x(x), y(y), width(w), height(h)
            {
            }

            bool Intersects(Rectangle other)
            {
                return !(other.x > x + width
                        || other.x + other.width < x
                        || other.y > y + height
                        || other.y + other.height < y);
            }

            bool Contains(Rectangle other)
            {
                return (other.x >= x
                        && other.y >= y
                        && other.x + other.width <= x + width
                        && other.y + other.height <= y + height);
            }
    };

}

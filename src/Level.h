#pragma once

#include <map>
#include <vector>

#include "Line.h"
#include "Tile.h"
#include "Color.h"

namespace one
{
    struct Level
    {
        public:
            std::map<Color, std::vector<Line> > hallLines;
            std::map<Color, Tile> exits;
    };
}

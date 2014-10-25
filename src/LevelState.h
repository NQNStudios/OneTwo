#pragma once

#include <map>
#include <vector>

#include "Color.h"
#include "State.h"
#include "Label.h"
#include "Tile.h"

namespace one
{
    class LevelState : public State
    {
        public:
            LevelState();

            void Update(const unsigned int deltaMS, Input& input);
            void Draw(Graphics& graphics);
        private:
            std::map<Color, std::vector<Line> > hallLines;
            std::map<Color, Tile> exits;
            std::map<Color, Tile> entrances;
            //std::vector<Tutorial> tutorials;

            Label* label;
    };
}

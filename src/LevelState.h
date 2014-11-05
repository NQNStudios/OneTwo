#pragma once

#include <map>
#include <vector>

#include "Color.h"
#include "State.h"
#include "Label.h"
#include "Tile.h"
#include "Player.h"
#include "Level.h"

namespace one
{
    class LevelState : public State
    {
        public:
            LevelState();

            void Update(const unsigned int deltaMS, Input& input);
            void Draw(Graphics& graphics);
        private:
            Level level;

            std::map<Color, Tile> entrances;
            //std::vector<Tutorial> tutorials;

            std::map<Color, int> hallTiles;
            std::map<Color, int> exitTiles;

            std::map<Color, Player> players;

            Label* label;

            void drawHalls(Color color, Graphics& graphics);
            void drawExit(Color color, Graphics& graphics);
    };
}

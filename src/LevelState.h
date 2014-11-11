#pragma once

#include <map>
#include <vector>
#include <string>

#include "Color.h"
#include "State.h"
#include "Label.h"
#include "Tile.h"
#include "Player.h"
#include "Level.h"
#include "Timer.h"

namespace one
{
    class LevelState : public State
    {
        public:
            LevelState(Game* game);

            void Update(const unsigned int deltaMS, Input& input);
            void Draw(Graphics& graphics);
            
            static LevelState* FromFile(Game* game, std::string path);
            static LevelState* FromLevel(Game* game, int level);
        private:
            Game* game;
            int levelNumber;
            bool fromLevel;

            Level level;

            std::map<Color, Tile> entrances;
            //std::vector<Tutorial> tutorials;

            std::map<Color, int> hallTiles;
            std::map<Color, int> exitTiles;

            std::map<Color, Player> players;

            Label* label;

            void resetLevel();

            Timer fadeInTimer;
            Timer fadeOutTimer;
            void drawFade(Graphics& graphics);

            Timer gravityTimer;
            void updateGravity(unsigned int deltaMS);

            void drawHalls(Color color, Graphics& graphics);
            void drawExit(Color color, Graphics& graphics);

            void gameOver();
    };
}

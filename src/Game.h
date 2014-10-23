#pragma once

#include "Graphics.h"
#include "Input.h"

namespace one
{
    class Game
    {
        public:
            Game();
            ~Game();

            void Run();

        private:
            void LoadContent(Graphics& graphics);
            void Update(int deltaMS, Input& input);
            void Draw(Graphics& graphics);

            int playerX, playerY;

            bool mRunning;
    };
}

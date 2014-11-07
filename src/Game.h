#pragma once

#include "Graphics.h"
#include "Input.h"
#include "State.h"

namespace one
{
    class Game
    {
        public:
            Game();
            ~Game();

            void Run();
            void Quit() { mRunning = false; }

            static const unsigned int TILE_SIZE = 8;
            static const unsigned int GRAVITY_INTERVAL = 500;

            void SetState(State* state) { mState = state; }

        private:
            void LoadContent(Graphics& graphics);
            void Update(int deltaMS, Input& input);
            void Draw(Graphics& graphics);

            State* mState;

            bool mRunning;
    };
}

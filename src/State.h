#pragma once

#include "Graphics.h"
#include "Input.h"

namespace one
{
    class State
    {
        public:
            virtual void Update(const unsigned int deltaMS, Input& input) = 0;
            virtual void Draw(Graphics& graphics) = 0;
    };
}

#pragma once

#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Graphics.h"

namespace one
{
    class Label
    {
        public:
            Label(std::string text, std::vector<Line> lines);

            void Draw(Graphics& graphics);
            
            void SetText(std::string text) { this->text = text; }
        private:
            static std::map<char, int> characterTiles;

            std::string text;
            std::vector<Line> lines;

            typedef std::vector<Line>::iterator LineIterator;
    };
}

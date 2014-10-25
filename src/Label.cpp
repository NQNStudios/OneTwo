#include "Label.h"

#include <sstream>

// static
std::map<char, int> one::Label::characterTiles;

one::Label::Label(std::string text, std::vector<one::Line> lines)
    : text(text), lines(lines)
{
    // initialize the character tile map if it hasn't already been done
    if (characterTiles.empty())
    {
        for (char letter = 'a'; letter <= 'z'; ++letter)
        {
            characterTiles[letter] = letter - 'a'; // a is index 0
        }

        characterTiles['@'] = 29;
        characterTiles[','] = 30;
        characterTiles['.'] = 31;
        characterTiles['!'] = 32;
        characterTiles[':'] = 33;
        characterTiles['?'] = 34;
        characterTiles[' '] = 39;
    }
}

void one::Label::Draw(one::Graphics& graphics)
{
    std::stringstream sstream(text);
    std::string word;

    LineIterator lineIt = lines.begin();

    while (sstream.rdbuf()->in_avail() && lineIt != lines.end())
    {
        int i = 0;

        do
        {
            sstream >> word;
            std::string::iterator wordIt = word.begin();

            while (wordIt != word.end())
            {
                int x = (i + lineIt->x) * Game::TILE_SIZE;
                int y = lineIt->y * Game::TILE_SIZE;

                graphics.DrawSprite("tiles", characterTiles[*wordIt], x, y);
                ++i;
                ++wordIt;
            }

            int x = (i + lineIt->x) * Game::TILE_SIZE;
            int y = lineIt->y * Game::TILE_SIZE;

            graphics.DrawSprite("tiles", characterTiles[' '], x, y);

            ++i;

        } while (i + word.size() < lineIt->length && sstream.rdbuf()->in_avail());

        ++lineIt;
    }
}

#include "LevelState.h"

#include <iostream>

#include "Game.h"

one::LevelState::LevelState()
{
    std::vector<one::Line> lines;

    lines.push_back(one::Line(1, 1, 6, HORIZONTAL));
    lines.push_back(one::Line(2, 2, 8, HORIZONTAL));
    lines.push_back(one::Line(5, 5, 15, HORIZONTAL));
    lines.push_back(one::Line(5, 6, 15, HORIZONTAL));
    lines.push_back(one::Line(6, 7, 20, HORIZONTAL));
    lines.push_back(one::Line(7, 8, 20, HORIZONTAL));

    std::string text = "we move as @ne though separate";

    label = new Label(text, lines);

    std::vector<one::Line> orangeHalls;

    orangeHalls.push_back(one::Line(1, 8, 10, HORIZONTAL));
    orangeHalls.push_back(one::Line(4, 8, 5, VERTICAL));

    level.hallLines[ORANGE].assign(orangeHalls.begin(), orangeHalls.end());

    std::vector<one::Line> blueHalls;
    
    blueHalls.push_back(one::Line(1, 14, 10, HORIZONTAL));
    blueHalls.push_back(one::Line(4, 14, 5, VERTICAL));

    level.hallLines[BLUE].assign(blueHalls.begin(), blueHalls.end());

    one::Tile blueExit(4, 18);
    one::Tile orangeExit(4, 12);

    level.exits[BLUE] = blueExit;
    level.exits[ORANGE] = orangeExit;

    Player blue(BLUE, 1 * Game::TILE_SIZE, 14 * Game::TILE_SIZE);
    Player orange(ORANGE, 1 * Game::TILE_SIZE, 8 * Game::TILE_SIZE);

    players[BLUE] = blue;
    players[ORANGE] = orange;

    hallTiles[ORANGE] = 36;
    hallTiles[BLUE] = 35;
    exitTiles[ORANGE] = 38;
    exitTiles[BLUE] = 37;
}

void one::LevelState::Update(unsigned int deltaMS, one::Input& input)
{
    bool allWillMove = true;
    for (Color color = COLOR_BEGIN; color != COLOR_END; color = (Color)((int)color + 1))
    {
        if (!players[color].WillMove(deltaMS, input, level))
        {
            allWillMove = false;
        }
    }

    if (allWillMove)
    {
        for (Color color = COLOR_BEGIN; color != COLOR_END; color = (Color)((int)color + 1))
        {
            players[color].Update(deltaMS, input, level);
        }
    }

    bool allOnExits = true;

    for (Color color = COLOR_BEGIN; color != COLOR_END; color = (Color)((int)color + 1))
    {
        if (!players[color].IsOnExit(level))
        {
            allOnExits = false;
            break;
        }
    }

    if (allOnExits)
    {
        label->SetText("game over! you win!");
    }
    else
    {
        label->SetText("we move as @ne though separate");
    }
}

void one::LevelState::Draw(one::Graphics& graphics)
{
    label->Draw(graphics);

    for (Color color = COLOR_BEGIN; color != COLOR_END; color = (Color)((int)color + 1))
    {
        drawHalls(color, graphics);

        drawExit(color, graphics);

    }

    for (Color color = COLOR_BEGIN; color != COLOR_END; color = (Color)((int)color + 1))
    {
        players[color].Draw(graphics);
    }
}

void one::LevelState::drawHalls(one::Color color, one::Graphics& graphics)
{
    std::vector<one::Line> lines;
    std::vector<one::Line>::iterator it;

    lines.assign(level.hallLines[color].begin(), level.hallLines[color].end());
    it = lines.begin();

    while (it != lines.end())
    {
        one::Line line = *it;

        int x = line.x;
        int y = line.y;

        while ((line.type == HORIZONTAL && x < line.x + line.length) ||
                (line.type == VERTICAL && y < line.y + line.length))
        {
            graphics.DrawSprite("tiles", hallTiles[color], x * Game::TILE_SIZE, y * Game::TILE_SIZE);

            if (line.type == HORIZONTAL) ++x;
            if (line.type == VERTICAL) ++y;
        }

        ++it;
    }
}

void one::LevelState::drawExit(one::Color color, one::Graphics& graphics)
{
    graphics.DrawSprite("tiles", exitTiles[color], level.exits[color].x * Game::TILE_SIZE,
            level.exits[color].y * Game::TILE_SIZE);
}

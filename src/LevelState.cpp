#include "LevelState.h"

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
}

void one::LevelState::Update(unsigned int deltaMS, one::Input& input)
{
}

void one::LevelState::Draw(one::Graphics& graphics)
{
    label->Draw(graphics);
}

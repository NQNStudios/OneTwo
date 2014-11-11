#pragma once

#include <map>
#include <string>

#include "SDL.h"

namespace one
{
    class Graphics
    {
        public:
            Graphics();
            ~Graphics();

            void Clear();
            void Update();

            void LoadSpritesheet(std::string key, const char* path);
            void DrawSprite(std::string sheetKey, unsigned int tileIndex, int x, int y);

            void DrawFade(float progress);
        private:
            SDL_Window* mWindow;
            SDL_Renderer* mRenderer;

            float mRenderScaleX;
            float mRenderScaleY;

            std::map<std::string, SDL_Texture*> mSpritesheets;
    };
}

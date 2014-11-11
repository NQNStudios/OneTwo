#include "Graphics.h"

#include <iostream>

#include "SDL_image.h"

#include "Game.h"

namespace
{
    const unsigned int RESOLUTION_WIDTH = 240;
    const unsigned int RESOLUTION_HEIGHT = 160;
}

one::Graphics::Graphics()
{
    int flags = IMG_INIT_PNG;
    IMG_Init(flags);

    unsigned int windowWidth = 0;
    unsigned int windowHeight = 0;
    SDL_WindowFlags windowFlags = SDL_WINDOW_SHOWN;

#ifdef NDEBUG
    windowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP;
#else
    windowWidth = RESOLUTION_WIDTH * 4;
    windowHeight = RESOLUTION_HEIGHT * 4;
#endif

    mWindow = SDL_CreateWindow("One", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, windowFlags);

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderSetLogicalSize(mRenderer, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
    SDL_SetRenderDrawBlendMode(mRenderer, SDL_BLENDMODE_BLEND);
}

one::Graphics::~Graphics()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    IMG_Quit();
}

void one::Graphics::Clear()
{
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);
}

void one::Graphics::Update()
{
    SDL_RenderPresent(mRenderer);
}

void one::Graphics::LoadSpritesheet(std::string key, const char* path)
{
    SDL_Surface* sheetSurface = IMG_Load(path);
    mSpritesheets[key] = SDL_CreateTextureFromSurface(mRenderer, sheetSurface);

    SDL_FreeSurface(sheetSurface); // clean up
}

void one::Graphics::DrawSprite(std::string sheetKey, unsigned int tileIndex, int x, int y)
{
    SDL_Rect source;
    SDL_Rect dest;

    int w, h;
    SDL_QueryTexture(mSpritesheets[sheetKey], NULL, NULL, &w, &h);
    w /= Game::TILE_SIZE;
    h /= Game::TILE_SIZE;

    source.x = (tileIndex % w) * Game::TILE_SIZE;
    source.y = (tileIndex / w) * Game::TILE_SIZE;
    source.w = Game::TILE_SIZE;
    source.h = Game::TILE_SIZE;

    dest.x = x;
    dest.y = y;
    dest.w = Game::TILE_SIZE;
    dest.h = Game::TILE_SIZE;

    SDL_RenderCopy(mRenderer, mSpritesheets[sheetKey], &source, &dest);
}

void one::Graphics::DrawFade(float progress)
{
    // black of opacity determined by progress

    int a = progress * 255;

    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, a);

    SDL_RenderFillRect(mRenderer, NULL);
}

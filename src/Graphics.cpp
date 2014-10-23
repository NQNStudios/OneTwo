#include "Graphics.h"

#include "SDL_image.h"

namespace
{
    const unsigned int TILE_SIZE = 8;
}

one::Graphics::Graphics()
{
    int flags = IMG_INIT_PNG;
    IMG_Init(flags);

    mWindow = SDL_CreateWindow("One", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);

    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderSetLogicalSize(mRenderer, 240, 160);
}

one::Graphics::~Graphics()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    IMG_Quit();
}

void one::Graphics::Clear()
{
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
    w /= TILE_SIZE;
    h /= TILE_SIZE;

    source.x = (tileIndex % w) * TILE_SIZE;
    source.y = (tileIndex / w) * TILE_SIZE;
    source.w = TILE_SIZE;
    source.h = TILE_SIZE;

    dest.x = x;
    dest.y = y;
    dest.w = TILE_SIZE;
    dest.h = TILE_SIZE;

    SDL_RenderCopy(mRenderer, mSpritesheets[sheetKey], &source, &dest);
}

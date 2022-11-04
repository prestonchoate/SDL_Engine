#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "player.h"

class Framework
{
private:
    int height;     // Height of the window
    int width;      // Width of the window
    SDL_Renderer *renderer = NULL;      // Pointer for the renderer
    SDL_Window *window = NULL;      // Pointer for the window
    bool isRunning = true;
    Player *player = NULL;
    SDL_Texture *background = NULL;
    Player *createPlayer();
    SDL_Texture *createBackground();
    void handleEvents();
    void handleKeyDownEvent(SDL_Event event);
    void handleKeyUpEvent(SDL_Event event);

public:
    Framework(int height_, int width_);
    ~Framework();
    int run();
    void update();
    void render();
};
#pragma once
#include <SDL2/SDL.h>

class Framework
{
private:
    int height;     // Height of the window
    int width;      // Width of the window
    SDL_Renderer *renderer = NULL;      // Pointer for the renderer
    SDL_Window *window = NULL;      // Pointer for the window
public:
    Framework(int height_, int width_);
    ~Framework();
    void drawCircle(int center_x, int center_y, int radius_);
    void moveCircle();
    int run();
    void update();
    void render();
};
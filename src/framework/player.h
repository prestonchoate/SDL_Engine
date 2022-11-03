#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player
{
    private:
        int xPos;
        int ypos;
        int xVel;
        int yVel;
        SDL_Texture *tex;
        SDL_Rect src;
        SDL_Rect dest;

    public:
        Player(SDL_Texture *_tex);
        ~Player();
        void setYVel(int _vel);
        void setXVel(int _vel);
        void update();
        void render(SDL_Renderer *ren);
        void handleEvents();
};
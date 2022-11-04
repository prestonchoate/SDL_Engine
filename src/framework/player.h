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
        int maxXPos;
        int maxYPos;
        SDL_Texture *tex;
        SDL_Rect src;
        SDL_Rect dest;
        static int clamp(int low, int high, int num);

    public:
        Player(SDL_Texture *_tex);
        ~Player();
        void setYVel(int _vel);
        void setXVel(int _vel);
        void update();
        void render(SDL_Renderer *ren);
        void handleEvents();
        void setMaxXPos(int maxPos);
        void setMaxYPos(int maxPos);
};
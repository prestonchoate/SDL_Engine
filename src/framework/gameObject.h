#pragma once
#include <SDL2/SDL.h>
#include <string>

class GameObject
{
    private:
        float xPos;
        float yPos;
        char* textureImage;
        SDL_Texture* texture;
        SDL_Surface* surface;

    public:
        GameObject(char* _textureImage, float _xPos = 0.0f, float _yPos = 0.0f);
        ~GameObject();
        float getXPos();
        void setXPos(float _xPos);
        float getYPos();
        float setYPos(float _yPos);
};
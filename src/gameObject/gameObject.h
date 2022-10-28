#pragma once
#include <SDL2/SDL.h>

class GameObject
{
    private:
        float xPos;
        float yPos;
        SDL_Texture* texture;

    public:
        GameObject(char *textureImage, float _xPos = 0.0f, float _yPos = 0.0f);
        ~GameObject();

};
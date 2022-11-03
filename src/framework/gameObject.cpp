#include "gameObject.h"
#include <SDL2/SDL_image.h>
#include "framework.h"

GameObject::GameObject(char *_textureImage, float _xPos, float _yPos) : xPos(_xPos), yPos(_yPos), textureImage(_textureImage)
{
    // create SDL_Surface from textureImage path
    surface = IMG_Load(textureImage);
}
#include <gameObject.h>
#include <SDL2/SDL_image.h>

GameObject::GameObject(char *_textureImage, float _xPos = 0.0f, float _yPos = 0.0f) : xPos(_xPos), yPos(_yPos), textureImage(_textureImage)
{
    // create SDL_Surface from textureImage path
    surface = IMG_Load(textureImage);
}
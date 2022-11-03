#include "player.h"

Player::Player(SDL_Texture *_tex) : tex(_tex)
{
    xPos = 0;
    ypos = 0;
    xVel = 0;
    yVel = 0;
    src.w = 16;
    src.h = 16;
    src.x = 0;
    src.y = 0;
    dest.w = 32;
    dest.h = 32;
    dest.x = 0;
    dest.x = 0;
}

Player::~Player()
{
    SDL_DestroyTexture(tex);
}

void Player::render(SDL_Renderer *ren)
{
    SDL_RenderCopy(ren, tex, &src, &dest);
}

void Player::update()
{
    dest.x += xVel;
    dest.y += yVel;
}

void Player::setYVel(int _vel)
{
    yVel = _vel;
}

void Player::setXVel(int _vel)
{
    xVel = _vel;
}
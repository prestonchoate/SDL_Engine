#include "player.h"

Player::Player(SDL_Texture *_tex) : tex(_tex)
{
    xPos = 0;
    ypos = 0;
    xVel = 0;
    yVel = 0;
    src.w = 124;
    src.h = 135;
    src.x = 0;
    src.y = 0;
    dest.w = 124;
    dest.h = 135;
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
    int newXPos, newYPos = 0;
    newXPos = dest.x + xVel;
    newYPos = dest.y + yVel;
    dest.x = Player::clamp(0, maxXPos, newXPos);
    dest.y = Player::clamp(0, maxYPos, newYPos);
}

void Player::setYVel(int _vel)
{
    yVel = _vel;
}

void Player::setXVel(int _vel)
{
    xVel = _vel;
}

void Player::setMaxXPos(int maxPos)
{
    maxXPos = maxPos - dest.w;
}

void Player::setMaxYPos(int maxPos)
{
    maxYPos = maxPos - dest.h;
}

// TODO: This should probalby be moved to some utility class at some point becuase it will be useful elsewhere
int Player::clamp(int low, int high, int num)
{
    if (num > high)
    {
        return high;
    } else if (num < low)
    {
        return low;
    } else 
    {
        return num;
    }
}
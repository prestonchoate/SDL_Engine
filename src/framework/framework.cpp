#include "framework.h"


// I got this example from http://www.libsdl.org/release/SDL-1.2.15/docs/html/guidetimeexamples.html
// But I'm not sure it's an optimal solution. It works for now though
#define TICK_INTERVAL    8

static Uint32 next_time;

Uint32 time_left(void)
{
    Uint32 now;

    now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}

Framework::Framework(int height_, int width_): height(height_), width(width_)
{
    Uint32 windowFlags = SDL_WINDOW_VULKAN | SDL_WINDOW_ALLOW_HIGHDPI;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(width, height, windowFlags, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    player = createPlayer();
    background = createBackground();
}

Framework::~Framework()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

int Framework::run()
{
    next_time = SDL_GetTicks() + TICK_INTERVAL;
    while (isRunning) {
        handleEvents();
        update();
        render();
        SDL_Delay(time_left());
        next_time += TICK_INTERVAL;
    }
    return 0;
}

void Framework::update()
{
    player->update();
}

void Framework::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    player->render(renderer);
    SDL_RenderPresent(renderer);
}

Player* Framework::createPlayer()
{
    // Create Surface
    SDL_Surface *player_sur = IMG_Load("assets/player/1B.png");
    if (player_sur == NULL) {
        std::cout << "Error loading image: " << IMG_GetError() << "\n";
        isRunning = false;
        return NULL;
    }
    // Create Texture from surface
    SDL_Texture *player_tex = SDL_CreateTextureFromSurface(renderer, player_sur);
    if (player_tex == NULL) {
        std::cout << "Error creating texture " << IMG_GetError() << "\n";
        isRunning = false;
        return NULL;
    }
    // Release surface
    SDL_FreeSurface(player_sur);

    Player *player = new Player(player_tex);

    // Get current window size and pass them to player
    player->setMaxXPos(width);
    player->setMaxYPos(height);

    return player;
}

SDL_Texture* Framework::createBackground()
{
    // Create Surface
    SDL_Surface *bg_sur = IMG_Load("assets/background/bg5.jpg");
    if (bg_sur == NULL) {
        std::cout << "Error loading image: " << IMG_GetError() << "\n";
        isRunning = false;
        return NULL;
    }
    // Create Texture from surface
    SDL_Texture *bg_tex = SDL_CreateTextureFromSurface(renderer, bg_sur);
    if (bg_tex == NULL) {
        std::cout << "Error creating texture " << IMG_GetError() << "\n";
        isRunning = false;
        return NULL;
    }
    // Release surface
    SDL_FreeSurface(bg_sur);

    return bg_tex;
}

void Framework::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;

    case SDL_KEYDOWN:
        handleKeyDownEvent(event);
        break;

    case SDL_KEYUP:
        handleKeyUpEvent(event);
        break;

    default:
        break;
    }
}

void Framework::handleKeyDownEvent(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
        case SDLK_LEFT: case SDLK_a:
            player->setXVel(-1);
            break;

        case SDLK_RIGHT: case SDLK_d:
            player->setXVel(1);
            break;

        case SDLK_UP: case SDLK_w:
            player->setYVel(-1);
            break;

        case SDLK_DOWN: case SDLK_s:
            player->setYVel(1);
            break;
        
        default:
            break;
    }
}

void Framework::handleKeyUpEvent(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
        case SDLK_LEFT: case SDLK_a:
            player->setXVel(0);
            break;
        case SDLK_RIGHT: case SDLK_d:
            player->setXVel(0);
            break;
        case SDLK_UP: case SDLK_w:
            player->setYVel(0);
            break;
        case SDLK_DOWN: case SDLK_s:
            player->setYVel(0);
            break;
        
        default:
            break;
    }
}
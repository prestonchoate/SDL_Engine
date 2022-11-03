#pragma once
#include <vector>
#include "gameObject.h"

class GameManager
{
    private:
        GameManager();
        ~GameManager();
        static SDL_Renderer _ren;
        std::vector<GameObject> gameObjects;
        void addObjectToList(GameObject *_object);

    public:
        std::vector<GameObject> getGameObjects();
        void updateGameObjects();
        void renderGameObjects();
        void createGameObject();
        static SDL_Renderer getRenderer();
};
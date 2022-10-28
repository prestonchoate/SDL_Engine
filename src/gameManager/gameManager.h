#pragma once
#include <vector>
#include <gameObject/gameObject.h>

class GameManager
{
    private:
        GameManager();
        ~GameManager();
        //TODO: Create GameObject class and use that class here instead
        std::vector<GameObject> gameObjects;

    public:
        std::vector<GameObject> getGameObjects();
        void updateGameObjects();
        void renderGameObjects();
};
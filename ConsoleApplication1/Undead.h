#pragma once
#include "Enemy.h"
#include <iostream>

class Undead : public Enemy
{
public:
    Undead() : Enemy("Undead", 70) {}

    void TauntPlayer() override
    {
        std::cout << enemyName << " whispers eerie threats to the player!" << std::endl;
    }
};
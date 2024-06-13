#pragma once
#include "Enemy.h"
#include <iostream>

class Orc : public Enemy
{
public:
    Orc() : Enemy("Orc", 80) {}

    void TauntPlayer() override
    {
        std::cout << enemyName << " growls menacingly at the player!" << std::endl;
    }
};
#pragma once
#include "Player.h"
#include <iostream>

class Wizard : public Player
{
public:
    Wizard(std::string name) : Player(name, 100) {}

    void SpecialAttack() override
    {
        std::cout << playerName << " performs a special magical attack!" << std::endl;
    }
};
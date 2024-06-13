#pragma once
#include "Player.h"
#include <iostream>

class Knight : public Player
{
public:
    Knight(std::string name) : Player(name, 120) {}

    void SpecialAttack() override
    {
        std::cout << playerName << " performs a special sword attack!" << std::endl;
    }
};
#pragma once
#include "GameObject.h"
#include <string>
#include <iostream>

class Player : public GameObject
{
protected:
    std::string playerName;
    int health;

public:
    Player(std::string name, int hp) : playerName(name), health(hp) {}

    void NormalAttack() override
    {
        std::cout << playerName << " performs a normal attack!" << std::endl;
    }

    virtual void SpecialAttack() = 0; // Pure virtual function for special attack

    std::string GetName() const { return playerName; }
    int GetHealth() const { return health; }
};
#pragma once
#include "GameObject.h"
#include <string>
#include <iostream>

class Enemy : public GameObject
{
protected:
    std::string enemyName;
    int health;

public:
    Enemy(std::string name, int hp) : enemyName(name), health(hp) {}

    void NormalAttack() override
    {
        std::cout << enemyName << " performs a normal attack!" << std::endl;
    }

    virtual void TauntPlayer() = 0; // Pure virtual function for taunting the player

    std::string GetName() const { return enemyName; }
    int GetHealth() const { return health; }
};
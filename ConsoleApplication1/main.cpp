#include "pch.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Wizard.h"
#include "Knight.h"
#include "Orc.h"
#include "Undead.h"

using namespace winrt;
using namespace Windows::Foundation; // ??

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str()); // ??

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    std::cout << "Welcome to the RPG Battle Simulator!" << std::endl;

    std::string playerName;
    std::string playerType;

    std::cout << "Enter your character name: ";
    std::cin >> playerName;

    std::cout << "Choose your character type (Wizard/Knight): ";
    std::cin >> playerType;

    std::unique_ptr<Player> player;

    if (playerType == "Wizard")
    {
        player = std::make_unique<Wizard>(playerName);
    }
    else if (playerType == "Knight")
    {
        player = std::make_unique<Knight>(playerName);
    }
    else
    {
        std::cerr << "Invalid player type!" << std::endl;
        return -1;
    }

    std::cout << "Player Type: " << playerType << std::endl;
    std::cout << "Player Name: " << player->GetName() << std::endl;
    std::cout << "Default Health: " << player->GetHealth() << std::endl;

    std::string response;
    std::cout << "Are you ready to witness a battle? (yes/no): ";
    std::cin >> response;

    if (response != "yes")
    {
        std::cout << "Goodbye!" << std::endl;
        return 0;
    }

    std::unique_ptr<Enemy> enemy;
    if (rand() % 2 == 0)
    {
        enemy = std::make_unique<Orc>();
    }
    else
    {
        enemy = std::make_unique<Undead>();
    }

    std::cout << "An enemy appears!" << std::endl;
    std::cout << "Enemy Type: " << enemy->GetName() << std::endl;
    std::cout << "Enemy Health: " << enemy->GetHealth() << std::endl;

    enemy->TauntPlayer();
    player->NormalAttack();
    enemy->TauntPlayer();
    player->SpecialAttack();
    enemy->NormalAttack();
    enemy->NormalAttack();
    player->SpecialAttack();
    enemy->TauntPlayer();
    player->SpecialAttack();

    std::cout << "Enemy dies." << std::endl;
    std::cout << "You win!" << std::endl;

    return 0;


}

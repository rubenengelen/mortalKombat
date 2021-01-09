#include "boss.h"

boss::boss(std::string name, int health, int attackMax, int blockMax)
{
    this->name = name;
    this->health = health;
    this->attackMax = attackMax;
    this->blockMax = blockMax;
}

//Functie die bepaalt hoeveel damage er gedaan wordt bij een aanval
int boss::attack()
{
    return std::rand() % this->attackMax;
}

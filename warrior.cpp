#include "warrior.h"

warrior::warrior(std::string name, int health, int attackMax, int blockMax, int genezen, int aantalHeals) : boss(name, health, attackMax, blockMax)
{
    this->name = name;
    this->health = health;
    this->attackMax = attackMax;
    this->blockMax = blockMax;
    this->genezen = genezen;
    this->aantalHeals = aantalHeals;
}

//Functie die bepaalt hoeveel damage er gedaan wordt bij een aanval
//int warrior::attack()
//{
//    return std::rand() % this->attackMax;
//}

//Functie die bepaalt hoeveel damage de speler blockt
int warrior::block()
{
    return std::rand() % this->blockMax;
}

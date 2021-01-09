#ifndef WARRIOR_H
#define WARRIOR_H
#include "boss.h"


class warrior : public boss
{
private:
    int attackMax;
    int blockMax;
public:
    std::string name;
    int health;
    int genezen;
    int aantalHeals;
    warrior(std::string name, int health, int attackMax, int blockMax, int genezen, int aantalHeals);
    int block();
};

#endif // WARRIOR_H

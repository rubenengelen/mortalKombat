#ifndef WARRIOR_H
#define WARRIOR_H
#include "boss.h"


class warrior : public boss
{
public:
    int genezen;
    int aantalHeals;
    warrior(std::string name, int health, int attackMax, int blockMax, int genezen, int aantalHeals);
    int block();
    warrior(); //11
    ~warrior(); //14
};

#endif // WARRIOR_H

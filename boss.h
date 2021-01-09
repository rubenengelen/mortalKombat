#ifndef BOSS_H
#define BOSS_H
#include <string>


class boss
{
private:
    int attackMax;
    int blockMax;
public:
    std::string name;
    int health;
    boss(std::string name, int health, int attackMax, int blockMax);
    int attack();
};

#endif // BOSS_H

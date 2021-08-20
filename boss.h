#ifndef BOSS_H
#define BOSS_H
#include <string>


class boss
{
private:
    int block = 1; //3, 17, 18
public:
    int attackMax;
    int blockMax = block; //3, 16
    std::string name;
    int health;
    boss(std::string name, int health, int attackMax, int blockMax);
    int attack();
    boss(); //11
    ~boss(); //14
};

#endif // BOSS_H

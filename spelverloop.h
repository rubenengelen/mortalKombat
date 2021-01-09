#ifndef SPELVERLOOP_H
#define SPELVERLOOP_H
#include "battle.h"
#include "warrior.h"
#include "keuzes.h"

std::string bosskeuze(warrior& speler);

//Belangrijkste functie, deze maakt de speler als object aan en roept de bosskeuze functie op
void spel()
{
    std::string naam;
    switch(strijder())
    {
    case 1:
    {
        warrior player("Thor", 100, 10, 15, 20, 3);
        printf("U heeft %s gekozen!\n", player.name.c_str());
        bosskeuze(player);
    }
        break;
    case 2:
    {
        warrior player("Hulk" , 135, 12, 25, 27, 5);
        printf("U heeft %s gekozen!\n", player.name.c_str());
        bosskeuze(player);
    }
        break;
    case 3:
    {
        warrior player("Iron Man", 125, 15, 13, 24, 2);
        printf("U heeft %s gekozen!\n", player.name.c_str());
        bosskeuze(player);
    }
        break;
    }
}

//Deze functie maakt de gekozen baas aan en start het gevecht
std::string bosskeuze(warrior& speler)
{
    switch(baas())
    {
    case 1:
    {
        boss baas("Loki", 150, 10, 1);
        printf("Gevecht tussen %s en %s\n", speler.name.c_str(), baas.name.c_str());
        battle::startFight(speler, baas);
        return baas.name;
        break;
    }
    case 2:
    {
        boss baas("Thanos", 180, 14, 1);
        printf("Gevecht tussen %s en %s\n", speler.name.c_str(), baas.name.c_str());
        battle::startFight(speler, baas);
        return baas.name;
        break;
    }
    case 3:
        boss baas("Magneto", 120, 8, 1);
        printf("Gevecht tussen %s en %s\n", speler.name.c_str(), baas.name.c_str());
        battle::startFight(speler, baas);
        return baas.name;
        break;
    }
    return "";
}
#endif // SPELVERLOOP_H

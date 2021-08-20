#ifndef KEUZES_H
#define KEUZES_H
#include <string>
#include <iostream>
using namespace std;

// functie die speler zijn karakter laat kiezen
int strijder()
{
    std::string warriorKeuze; //26
    int strijder;
    for(;;)
    {
        printf("U kan kiezen tussen: Thor, Hulk en Iron Man\n");
        printf("Keuze warrior: ");
        getline(cin, warriorKeuze);
        if(warriorKeuze == "Thor" || warriorKeuze == "thor")
        {
            strijder = 1;
            break;
        }else if(warriorKeuze == "Hulk" || warriorKeuze == "hulk")
        {
            strijder = 2;
            break;
        }else if(warriorKeuze == "Iron Man" || warriorKeuze == "iron man" || warriorKeuze == "Iron man" || warriorKeuze == "iron Man")
        {
            strijder = 3;
            break;
        }
        else
        {
            printf("Oeps! Warrior niet gevonden, probeer opnieuw.\n");
        }
    }

    return strijder;
}

//Functie die speler zijn tegenstander laat kiezen
int baas()
{
    printf("U kan kiezen tussen: Loki, Thanos en Magneto\n");
    int bossKeuze;
    std::string bossInput;
    for(;;)
    {
        printf("Keuze boss: ");
        getline(cin, bossInput);
        if(bossInput == "Loki" || bossInput == "loki")
        {
            bossKeuze = 1;
            break;
        }else if(bossInput == "Thanos" || bossInput == "thanos")
        {
            bossKeuze = 2;
            break;
        }else if(bossInput == "Magneto" || bossInput == "magneto")
        {
            bossKeuze = 3;
            break;
        }
        else
        {
            printf("Oeps! Boss niet gevonden, probeer opnieuw\n");
        }
    }
    return bossKeuze;

}

std::string actie()
{
    std::string actieKeuze;

    printf("Wilt u aanvallen (a) of genezen(g)? ");
    getline(cin, actieKeuze);
    return actieKeuze;
}

#endif // KEUZES_H

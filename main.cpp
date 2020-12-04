//15 = mijn
//-37 = 219 = vakje
//70 = 'F' = Flag

#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "grid.h"
#include "welkom.h"
#include "veld.h"

int main()
{
    char check;
    welkomp();
    printf("Wilt u doorgaan? Druk Enter!");
    scanf("%c", &check);
    system("cls");
    veld();

    return 0;
}

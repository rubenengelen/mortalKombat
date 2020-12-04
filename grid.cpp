#include "grid.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

grid::grid()
{
    int i, j, i1, j1, aantalMijnen = 0;
    char veld[6][6];
    int gridn[6][6] = {0};

//Random mijnen plaatsen
    srand(time(NULL));
    for(;;)
    {
        i=rand()%6;
        j=rand()%6;
        if(veld[i][j]!=15)
            veld[i][j]=15;
        else
        continue;
        aantalMijnen++;
        if(aantalMijnen==9)
            break;
    }

    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(veld[i][j]!=15)
            {
                for(i1=i-1;i1<=i+1;i1++)
                {
                    for(j1=j-1;j1<=j+1;j1++)
                    {
                        if(veld[i1][j1]==15 && 0<=i1 && 0<=j1 &&i1<=5 && j1<=5)
                            gridn[i][j]++;
                    }
                }
                veld[i][j]=gridn[i][j] + 48;

            }
        }
    }

////oplossing
//    for(i=0;i<6;i++)
//    {
//        for(j=0;j<50;j++)
//            printf(" ");
//        for(j=0;j<6;j++)
//            printf("%c ",veld[i][j]);
//        printf("\n\n");
//    }
}

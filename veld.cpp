#include "veld.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>

veld::veld()
{
    int i, j, startx, starty, aantalMijnen = 0, i1, j1, aantalVlaggen = 0, flagged = 0, x, y, vakjes;
    char mode[2];

    printf("met hoeveel vakjes wilt u spelen? (max 15)");
    scanf("%d", &vakjes);

    int gridn[16][16] = {0};
    char veld[16][16], grid[16][16];

    //veld maken
    for(i=0;i<vakjes;i++)
    {
        for(j=0;j<vakjes;j++)
            veld[i][j]=-37;
    }

    //veld tekenen
    for(i=0;i<vakjes;i++)
    {
        for(j=0;j<30;j++)
            printf(" ");
        for(j=0;j<vakjes;j++)
            printf("%c ",veld[i][j]);
        printf("\n\n");
    }

    for(;;)
    {
        printf("Open het startvak.\nx: ");
        scanf("%d", &startx);
        printf("y: ");
        scanf("%d", &starty);
        if(startx>vakjes || starty >vakjes || startx<1 || starty<1)
        {
            printf("Kan rij of kolom niet vinden, probeer opnieuw.\n");
        }
        else break;
    }
    startx = startx -1;
    starty = starty -1;

    srand(time(NULL));
    //mijnen plaatsen
    for(;;)
    {
        i=rand()%vakjes;
        j=rand()%vakjes;
        if(grid[i][j]!=15 && i!=startx && j!=starty)
            grid[i][j]=15;
        else
        continue;
        aantalMijnen++;
        if(aantalMijnen==vakjes+vakjes/2)
            break;
    }
    aantalVlaggen = aantalMijnen;

    //Telt omringende mijnen en add aan oplossingsgrid
    for(i=0;i<vakjes;i++)
    {
        for(j=0;j<vakjes;j++)
        {
            if(grid[i][j]!=15)
            {
                for(i1=i-1;i1<=i+1;i1++)
                {
                    for(j1=j-1;j1<=j+1;j1++)
                    {
                        if(grid[i1][j1]==15 && 0<=i1 && 0<=j1 &&i1<=vakjes-1 && j1<=vakjes-1)
                            gridn[i][j]++;
                    }
                }
                grid[i][j]=gridn[i][j] + 48;

            }
        }
    }
    //stelt vakjes gelijk aan cijfers op veld + opent beginvak
    for(i=startx-1;i<=startx+1;i++)
    {
        for(j=starty-1;j<=starty+1;j++)
        {
            if(grid[i][j]!=15)
                veld[i][j]=grid[i][j];
        }
    }
    x=startx;
    y=starty;
    for(;;)
    {
        system("cls");

        for(i=0;i<vakjes;i++);
        {
            for(j=0;j<vakjes;j++)
                printf("%c ",grid[i][j]);
            printf("\n\n");
        }

        //print veld
        for(i=0;i<vakjes;i++)
        {
            for(j=0;j<30;j++)
                printf(" ");
            for(j=0;j<vakjes;j++)
                printf("%c ", veld[i][j]);
            printf("\n\n");
        }
        printf("Aantal vlaggen: %d\n", aantalVlaggen);

        if(grid[x][y]==15 && strcmp(mode, "o")==0 || aantalVlaggen<0)
        {
            printf("Game over\n");
            break;
        }

        for(i=0;i<vakjes;i++)
        {
            for(j=0;j<vakjes;j++);
            {
                if(grid[i][j]==15 && veld[i][j]==70)
                {
                    flagged++;
                }
            }
        }

        if(flagged == aantalMijnen)
        {
            printf("Proficiat, u heeft gewonnen!\n");
            break;
        }
        flagged=0;

        printf("mode:");
        scanf("%s",&mode);
        printf("x:");
        scanf("%d",&x);
        printf("y:");
        scanf("%d",&y);
        x=x-1;
        y=y-1;
        if(strcmp(mode,"o")==0)
            veld[x][y]=grid[x][y];
        if(strcmp(mode,"f")==0 && veld[x][y]!='F' && veld[x][y]==-37)
        {veld[x][y]=70;
            aantalVlaggen--;}
        if(strcmp(mode,"r")==0)
        {
            if(veld[x][y]==70)
            {
                veld[x][y]=-37;
                aantalVlaggen++;
            }
        }

        if(grid[x][y]==15 && strcmp(mode,"o")==0)
        {
            for(i=0;i<vakjes;i++)
            {
                for(j=0;j<vakjes;j++)
                {
                    if(grid[i][j]==15)
                    {
                        veld[i][j]=grid[i][j];
                    }
                }
            }
        }

    }
}

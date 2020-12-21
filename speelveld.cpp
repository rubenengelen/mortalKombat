#include "speelveld.h"


speelveld::speelveld()
{
    vakje vak[36];
    char field[6][6], grid[6][6], mode[2];
    char gridn[6][6] = {{0}};
    int nummer = 0, aantalMijnen = 0, bom = 0, x, y, aantalVlaggen, xstart, ystart;

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j <6; j++)
        {
            vak[nummer].x = i;
            vak[nummer].y = j;
            nummer++;
        }
    }
    for(;;)
    {
        {
            printf("\nOpen het startvak, neem geen coordinaat op de rand van het veld.\nx:");
            scanf("%d",&xstart);
            printf("y:");
            scanf("%d", &ystart);
            xstart = xstart - 1;
            ystart = ystart - 1;
            if(xstart >= 5 || ystart >= 5 || xstart <= 0 || ystart <= 0)
            {
                printf("Kan rij of kolom niet vinden. Probeer opnieuw\n");
                continue;
            }
            else break;
        }
    }
    srand(time(NULL));
    for(;;)
    {
        bom = rand()%36;
        vak[bom].isBom = true;
        vak[bom].x = rand()%6;
        vak[bom].y = rand()%6;
        if(grid[vak[bom].x][vak[bom].y] != 15)//&& vak[bom].x != xstart && vak[bom].y != ystart
        {
            grid[vak[bom].x][vak[bom].y] = 15;
            aantalMijnen++;
        }
        printf("aantalmijnen is %d \n", aantalMijnen);
        if(aantalMijnen == 9)
        {
            break;
        }
    }
    aantalVlaggen = aantalMijnen;
//    for(int i = 0; i < 36; i++)
//    {
//        int k = vak[i].isBom;
//        printf("Vak nummer %i is %d\n", i, k);
//    }

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
            field[i][j]=-37;
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<30;j++)
            printf(" ");
        for(int j=0;j<6;j++)
            printf("%c ",field[i][j]);
        printf("\n\n");
    }
    printf("\n\n");

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(grid[i][j] != 15)
            {
                for(int i1 = i - 1; i1 <= i + 1; i1++)
                {
                    for(int j1 = j - 1; j1 <= j + 1; j1++)
                    {
                        if(grid[i1][j1] == 15 && 0 <= i1 && 0 <= j1 && i1 <= 5 && j1 <= 5)
                            gridn[i][j]++;
                    }
                }
                grid[i][j] = gridn[i][j] + 48;

            }
        }
    }

    for(int i=xstart-1;i<=xstart+1;i++)
    {
        for(int j=ystart-1;j<=ystart+1;j++)
        {
            if(grid[i][j]!=15)
                field[i][j]=grid[i][j];
        }
    }

    for(;;)
    {
        system("cls");
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<30;j++)
                printf(" ");
            for(int j=0;j<6;j++)
                printf("%c ", field[i][j]);
            printf("\n\n");
        }
        printf("no of flags: %d\n", aantalVlaggen);

        printf("mode:");
        scanf("%s",&mode);
        printf("x:");
        scanf("%d",&x);
        printf("y:");
        scanf("%d",&y);
        x=x-1;
        y=y-1;
        if(strcmp(mode,"o")==0)
            field[x][y]=grid[x][y];
        if(strcmp(mode,"f")==0 && field[x][y]!=70 && field[x][y]==-37)
        {field[x][y]=70;
            aantalVlaggen--;}
        if(strcmp(mode,"r")==0)
        {
            if(field[x][y]==70)
            {
                field[x][y]=-37;
                aantalVlaggen++;
            }
        }

        if(grid[x][y] == 15 && strcmp(mode, "o")==0)
        {
            printf("\nGame Over\n");
            break;
        }
    }

//SHOW BOMBS

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<30;j++)
            printf(" ");
        for(int j=0;j<6;j++)
            printf("%c ",grid[i][j]);
        printf("\n\n");
    }
}

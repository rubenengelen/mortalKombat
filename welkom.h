#ifndef WELKOM_H
#define WELKOM_H
#include <stdio.h>
#include <windows.h>

void welkomprint()
{
    char check;
    printf("\\\\              //   |||||||   ||        ||  //   |||||||   ||\\\\    //||\n");
    printf(" \\\\            //    ||        ||        || //    ||   ||   || \\\\  // ||\n");
    printf("  \\\\    /\\    //     ||        ||        ||//     ||   ||   ||  \\\\//  ||\n");
    printf("   \\\\  //\\\\  //      |||||     ||        ||\\\\     ||   ||   ||   \\/   ||  \n");
    printf("    \\\\//  \\\\//       ||        ||        || \\\\    ||   ||   ||        ||  \n");
    printf("     \\/    \\/        |||||||   |||||||   ||  \\\\   |||||||   ||        || \n");
    printf("Wilt u doorgaan? Druk Enter!");
    scanf("%c", &check);
    system("cls");
}

#endif // WELKOM_H

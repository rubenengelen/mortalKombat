#include "vakje.h"
#include <string.h>
#include <stdio.h>

vakje::vakje()
{
    x = y = 0;
    isBom = false;
    flagged = false;
    buren = 0;
    geheim = true;
}

vakje::vakje(int xcord, int ycord, bool heeftBom): x{xcord},y{ycord},isBom{heeftBom}
{
    flagged = false;
    buren = 0;
    geheim = true;
    ontploft = false;
}

void vakje::actie(char type)
{
    if(type == '1')
    {
        if(geheim == true)
        {
            geheim = false;
            flagged = false;
            if(isBom == true)
            {
                ontploft = true;
            }
        }
    }
    if(type == 'r')
    {
        if(geheim == true)
        {
            flagged = !flagged;
        }
    }
}

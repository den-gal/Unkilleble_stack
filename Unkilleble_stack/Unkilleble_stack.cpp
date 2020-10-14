// Denis Galanin 327 group of CMC MSU

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "Templates.h"


int main()
{
    bool constr = true, destr = true, erase=true;
    Template_(Stack, int) stack;
    constr = Template_(StackConstr, int) (&stack,30);
    Template_(Push, int)(&stack, 10);
    int i = Template_(Pop, int)(&stack);
    erase = (i = 10);
    destr = Template_(StackDestr, int)(&stack);
    if (destr && constr && erase)
        printf("Stack with int type works correctly");
}


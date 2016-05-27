#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"
#define QTY 100

int main()
{
    eMovie billboard[QTY];

    initBillboard(billboard,QTY);

    readrBinary(billboard,QTY);

    //test(billboard);

    menu(billboard,QTY);

    return 0;
}

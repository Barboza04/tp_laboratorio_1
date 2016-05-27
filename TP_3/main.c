/********************************************************************
*Programa: TP 3- Cartelera de cine
*
*Objetivo:
          Realizar un programa que permita agregar, borrar y modificar
          peliculas en un archivo binario
*
*Versión 1.0 27/05/2016
*Autor: Alejandro Barboza
*
********************************************************************/
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

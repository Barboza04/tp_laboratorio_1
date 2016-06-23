/********************************************************************
*Programa: TP 4- Implementacion de Arraylist
*
*Objetivo:
*         Realizar un programa que permita el uso de todas las
*         funciones del Arraylist en un caso real
*
*Versión 1.0 22/06/2016
*Autor: Alejandro Barboza
*
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "lib.h"
#include "Employee.h"
#define QTY 50

int main()
{
    ArrayList* pList;

    ArrayList* pBackupList;

    pList=al_newArrayList();

    pBackupList=al_newArrayList();

    readBinary(pList);

    readBackUpBinary(pBackupList);

    menu(pList,pBackupList);

    return 0;
}

/**
Puntero void casteado a puntero Employee ((Employee*)(pList->pElements+pList->size))->id
Comparacion de valores a travez de un puntero ((Employee*)*(pList->pElements+i))->id==id
**/

/********************************************************************
*Programa: TP 2- Lista
*
*Objetivo:
          Realizar una lista de un maximo de 20 personas e imprimir
          una lista ordenada por nombre y un grafico con tres rangos
          de edades.
*
*Versión 1.0 27/04/2016
*Autor: Alejandro Barboza
*
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LENGTH 20

int main()
{
    ePerson list[LENGTH];
    ePerson auxList;
    int option=0;
    int auxName,auxAge,auxDni;
    int counter18less=0;
    int counter18_35=0;
    int counter35plus=0;

    initPersons(list,LENGTH);
    auxList.status=0;

    do
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        getInt(&option,"Elija una opcion ","Solo debe ingresar numeros\n","Opcion invalida\n",1,5);

        switch(option)
        {
            case 1:
                auxName=getString(auxList.name,"Ingrese nombre: ","El largo debe ser entre 2 y 50\n",2,50);
                if(auxName!=0)
                {
                    break;
                }
                auxAge=getInt(&auxList.age,"Ingrese edad ","Solo debe ingresar numeros\n","Rango valido 1 - 100\n",1,100);
                if(auxAge!=0)
                {
                    break;
                }
                auxDni=getInt(&auxList.dni,"Ingrese DNI ","Solo debe ingresar numeros\n","Rango valido 1.000.000 - 99.999.999\n",1000000,99999999);
                if(auxDni!=0)
                {
                    break;
                }
                if(auxName!=-1&&auxAge!=-1&&auxDni!=-1)
                {
                    addPerson(list,LENGTH,auxList.name,auxList.age,auxList.dni);
                }
                break;
            case 2:
                auxDni=getInt(&auxList.dni,"Ingrese DNI ","Solo debe ingresar numeros\n","Rango valido 1.000.000 - 99.999.999\n",1000000,99999999);
                if(auxDni!=0)
                {
                    break;
                }
                else
                {
                    removePerson(list,LENGTH,auxList.dni);
                }
                break;
            case 3:
                sortPersonsByName(list,LENGTH);
                printPersons(list,LENGTH);
                break;
            case 4:
                getRanges(list,LENGTH,&counter18less,&counter18_35,&counter35plus);
                printRanges(counter18less,counter18_35,counter35plus);
                break;
            case 5:
                break;
        }
    }while(option!=5);

    return 0;
}

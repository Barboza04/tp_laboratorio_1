#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int main()
{
    int opcion=0;

    do
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }while(opcion!=5);

    return 0;
}

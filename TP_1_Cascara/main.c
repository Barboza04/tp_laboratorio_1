#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    signed int x=0;
    signed int y=0;
    int factorialFinal;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A=%i)\n",x);
        printf("2- Ingresar 2do operando (B=%i)\n",y);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    system("cls");
                    do
                    {
                        printf("Ingrese el 1er operando ");
                        setbuf(stdin, NULL);
                    } while(scanf("%d", &x) != 1);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    do
                    {
                        printf("Ingrese el 2do operando ");
                        setbuf(stdin, NULL);
                    } while(scanf("%d", &y) != 1);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    suma(x,y);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    resta(x,y);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    division(x,y);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    multiplicacion(x,y);
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    factorialFinal=factorial(x);
                    printf("El factorial de %d es: %d\n",x,factorialFinal);
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    suma(x,y);
                    resta(x,y);
                    division(x,y);
                    multiplicacion(x,y);
                    factorial(x);
                    system("pause");
                    break;
                case 9:
                    seguir = 'n';
                    break;
            }

    }
    return 0;
}

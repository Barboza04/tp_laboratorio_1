/******************************************************************
*Programa: TP 1- Calculadora
*
*Objetivo:
        Realizar cinco operaciones matematicas, suma, resta, division, multipilcacion
        y factorial, de los números ingresados por el usuario
*
*Versión 1.0 06/04/2016
*Autor: Alejandro Barboza
*
*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char keepGoing;
    int option=0;
    int x;
    int y;
    int finalFactorial;
    int flag_op_1=0;
    int flag_op_2=0;

    do
    {
        system("cls");
        if(flag_op_1==0)
        {
            printf("1- Ingresar 1er operando (A= sin definir)\n");
        }
        else
        {
            printf("1- 1er operando ingresado (A= %d)\n",x);
        }
        if(flag_op_2==0)
        {
            printf("2- Ingresar 2do operando (B= sin definir)\n");
        }
        else
        {
            printf("2- 2do operando ingresado (B= %d)\n",y);
        }
        printf("3- Calcular la suma (A+B)\n"
               "4- Calcular la resta (A-B)\n"
               "5- Calcular la division (A/B)\n"
               "6- Calcular la multiplicacion (A*B)\n"
               "7- Calcular el factorial(A!)\n"
               "8- Calcular todas las operacione\n9- Salir\n");
        do
        {
            printf("\nSeleccione una opcion\n");
            setbuf(stdin, NULL);
        } while(scanf("%d",&option)!= 1);
            switch(option)
            {
                case 1:
                    system("cls");
                    do
                    {
                        printf("Ingrese el 1er operando ");
                        setbuf(stdin, NULL);
                    } while(scanf("%d",&x)!= 1);
                    flag_op_1=1;
                    break;
                case 2:
                    system("cls");
                    do
                    {
                        printf("Ingrese el 2do operando ");
                        setbuf(stdin, NULL);
                    } while(scanf("%d",&y)!= 1);
                    flag_op_2=1;
                    break;
                case 3:
                    system("cls");
                    addition(x,y, flag_op_1, flag_op_2);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    subtraction(x,y, flag_op_1, flag_op_2);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    division(x,y, flag_op_1, flag_op_2);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    multiplication(x,y, flag_op_1, flag_op_2);
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    if(flag_op_1)
                    {
                        finalFactorial=factorial(x);
                        printf("%d! = %d\n",x,finalFactorial);
                        system("pause");
                    }
                    else
                    {
                        printf("Falta el operando realizar el calculo\n");
                        system("pause");
                    }
                    break;
                case 8:
                    system("cls");
                    addition(x,y, flag_op_1, flag_op_2);
                    subtraction(x,y, flag_op_1, flag_op_2);
                    division(x,y, flag_op_1, flag_op_2);
                    multiplication(x,y, flag_op_1, flag_op_2);
                    if(flag_op_1)
                    {
                        finalFactorial=factorial(x);
                        printf("%d! = %d\n",x,finalFactorial);
                    }
                    else
                    {
                        printf("Falta el operando para realizar el calculo\n");
                    }
                    system("pause");
                    break;
                case 9:
                    keepGoing='n';
                    break;
                default:
                    printf("La opcion ingresada no es valida\n");
                    system("pause");
                    break;
            }

    }while(keepGoing!='n');
    return 0;
}

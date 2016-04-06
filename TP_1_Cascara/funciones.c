#include <stdio.h>
#include <stdlib.h>

/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las suma
 *
 * \param x es la primer variable ingresada
 * \param y es la segunda variable ingresada
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param addition guarda el resultado de la operacion
 *
 */
void addition(int x, int y, int a, int b)
{
    if(a&&b)
    {
        int addition;
        addition=x+y;
        printf("%d+%d = %d\n",x,y,addition);
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos para realizar el calculo\n");
        }
    }
}
/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las resta
 *
 * \param x es la primer variable ingresada
 * \param y es la segunda variable ingresada
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param subtraction guarda el resultado de la operacion
 *
 */
void subtraction(int x, int y, int a, int b)
{
    if(a&&b)
    {
        int subtraction;
        subtraction=x-y;
        printf("%d-%d = %d\n",x,y,subtraction);
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos realizar el calculo\n");
        }
    }
}
/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las divide
 *
 * \param x es la primer variable ingresada
 * \param y es la segunda variable ingresada
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param division guarda el resultado de la operacion
 *
 */
void division(int x, int y, int a, int b)
{
    if(a&&b)
    {
        float division;
        division=(float)x/y;
        printf("%d/%d = %.2f\n",x,y,division);
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos realizar el calculo\n");
        }
    }
}
/** \brief Recibe dos variables int, verifica que hayan sido ingresadas y las multiplica
 *
 * \param x es la primer variable ingresada
 * \param y es la segunda variable ingresada
 * \param a es la variable de control del ingreso de la variable x
 * \param b es la variable de control del ingreso de la variable y
 * \param multiplication guarda el resultado de la operacion
 *
 */
void multiplication(int x, int y, int a, int b)
{
    if(a&&b)
    {
        int multiplication;
        multiplication=x*y;
        printf("%d*%d = %d\n",x, y,multiplication);
    }
    else
    {
        if(a==0||b==0)
        {
            printf("Faltan operandos realizar el calculo\n");
        }
    }
}
/** \brief Recibe una variable int, verifica que haya sido ingresada y calcula su factorial
 *
 * \param x es la variable ingresada
 * \param result guarda el resultado de la operacion
 * \return retorna el producto del factoreo
 *
 */
int factorial(int x)
{
    int result;
    if(x>1)
    {
        result=x*factorial(x-1);
    }
    else
    {
        result=1;
    }
    return result;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Solicita una cadena de caracteres al usuario y la valida
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mìnima de la cadena
 * \param hiLimit Longitud màxima de la cadena
 * \return Si obtuvo la cadena retorna 0 si no -1
 *
 */
int getString(char* input,char message[],char eMessage[],int lowLimit, int hiLimit)
 {
     int value=-1;
     int length;
     int i;
     int isLetter;
     char auxString[100];
     puts(message);
     setbuf(stdin,NULL);
     gets(auxString);
     length=strlen(auxString);
     for(i=0;i<length;i++)
     {
         isLetter=isalpha(auxString[i]);
         if(isLetter==0)
         {
             break;
         }
     }
     if(isLetter==0||(length<lowLimit||length>hiLimit))
     {
         puts(eMessage);
     }
     else
     {
         strcpy(input,auxString);
         value=0;
     }
     return value;
 }

 /** \brief Solicita un nùmero al usuario y lo valida
 * \param input Se carga el nùmero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage1 Es el mensaje a ser mostrado en caso de ingreso erroneo del dato
 * \param eMessage2 Es el mensaje a ser mostrado en caso de que el dato este fuera del rango
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero retorna 0 si no -1
 *
 */
int getInt(int* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit)
 {
     int value=-1;
     int auxInt;
     puts(message);
     setbuf(stdin,NULL);
     if(scanf("%d",&auxInt)!=1)
     {
         puts(eMessage1);
     }
     else if(auxInt<lowLimit||auxInt>hiLimit)
     {
        puts(eMessage2);
     }
     else
     {
         *input=auxInt;
        value=0;
     }
     return value;
 }

/** \brief  Para indicar que todas las posiciones del array estan vacias
 *          esta funcion inicializa el campo isEmpty en 1
 * \param ePerson* pPerson Puntero al array de personas
 * \param int length Largo del array
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int initPersons(ePerson* pPerson, int length)
{
    int value=-1;
    int i;
    if(pPerson!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            pPerson[i].isEmpty=1;
        }
        value=0;
    }
    return value;
}

/** \brief Busca la primer posicion libre del array
 *
 * \param ePerson person Vector de personas donde busca el espacio libre
 * \param int length largo del array
 * \return int index devuelve -1 en caso de no encontrar una posicion libre y el indice de esa posicion en caso contrario
 *
 */

int findEmpty(ePerson person[], int length)
{
    int index=-1,i;
    for(i=0;i<length;i++)
    {
        if(person[i].isEmpty==-1)
        {
            index=i;
            break;
        }
    }
    return index;
}

/** \brief Agrega en una lista de personas los valores recividos como parametros
 *
 * \param ePerson* pPerson Puntero al array de personas
 * \param int length Largo del array
 * \param char name[] nombre de la persona a ingresar en la lista
 * \param int age edad de la persona a ingresar en la lista
 * \param int dni dni de la persona a ingresar en la lista
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int addPerson(ePerson* pPerson, int length, int index, char name[], int age, int dni)
{
    int value=-1;
    if(pPerson!=NULL&&length>0)
    {
        if(index!=-1)
        {
            strcpy(pPerson[index].name,name);
            pPerson[index].age=age;
            pPerson[index].dni=dni;
            pPerson[index].isEmpty=0;
            value=0;
        }
    }
    return value;
}

/** \brief Ecuentra una persona por su dni
 *
 * \param ePerson* pPerson Puntero al array de personas
 * \param int length Largo del array
 * \param int dni dni de la persona a buscar en la lista
 * \return ePerson* Retorna un puntero a una persona si no hay error y un puntero NULL si hay error [largo invalido o puntero NULL recivido o persona no encontrada]
 *
 */
ePerson* findByDni(ePerson* pPerson, int length,int dni)
{
    int i;
    ePerson* value=NULL;
    if(pPerson!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(!pPerson[i].isEmpty&&pPerson[i].dni==dni)
            {
                value=&pPerson[i];
                break;
            }
        }
    }
    return value;
}

/** \brief Borra una persona de la lista por su dni
 *         (cambia el valor de la bandera isEmpty a 1)
 *
 * \param ePerson* pPerson Puntero al array de personas
 * \param int length Largo del array
 * \param int dni dni de la persona a borrar de la lista
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL o si no puede encontrar a la persona] y 0 si no hay error
 *
 */
int removePerson(ePerson* pPerson, int length, int dni)
{
    int value=-1;
    ePerson* auxPerson=NULL;
    auxPerson=findByDni(pPerson,length,dni);
    if(auxPerson!=NULL)
    {
        auxPerson->isEmpty=1;
        value=0;
    }
    return value;
}

/** \brief Ordena los elementos del aray por nombre
 *
 * \param ePerson* pPerson Puntero al array de personas
 * \param int length Largo del array
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int sortPersonsByName(ePerson* pPerson, int length)
{
    int i;
    int j;
    ePerson auxiliar;
    int value=-1;
    if(pPerson!=NULL&&length>0)
    {
        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(strcmp(pPerson[i].name,pPerson[j].name)>0)
                {
                    auxiliar=pPerson[i];
                    pPerson[i]=pPerson[j];
                    pPerson[j]=auxiliar;
                    value=0;
                }
            }
        }
    }
    return value;
}

/** \brief Imprime los elementos del array
 *
 * \param ePerson* pPerson Puntero al array de personas
 * \param int length Largo del array
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int printPersons(ePerson* pPerson, int length)
{
    int i;
    int value=-1;
    printf("\n\nName\t  \tAge\t \tDNI\n");
    if(pPerson!=NULL&&length>0)
    {
        for(i=0; i<length; i++)
        {
            if(!pPerson[i].isEmpty)
            {
                printf("\n%s  \t%d\t \t%d\n\n",pPerson[i].name,pPerson[i].age,pPerson[i].dni);
            }
        }
        value=0;
    }
    return value;
}

/** \brief Calcula el maximo entre tres enteros
 *
 * \param int x primer entero recivido
 * \param int y segundo entero recivido
 * \param int z tercer entero recivido
 * \return int maxNumber devuelve el numero maximo
 *
 */

int calculateMax(int x, int y, int z)
{
    int maxNumber;
    if(x>y && x>z)
    {
        maxNumber=x;
    }
    else
    {
        if(y>=x && y>z)
        {
            maxNumber=y;
        }
        else
        {
            maxNumber=z;
        }
    }
    return maxNumber;
}

/** \brief Cuenta cuantos elementos del array estan dentro de cada rango
 *
 * \param ePerson* pPerson Puntero al array de personas
 * \param int length Largo del array
 * \param int* x puntero al contador del primer rango
 * \param int* y puntero al contador del segundo rango
 * \param int* z puntero al contador del tercer rango
 * \return int value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */

int getRanges(ePerson* pPerson, int length, int* x, int* y, int* z)
{
    int i;
    int value=-1;
    int range1=0;
    int range2=0;
    int range3=0;
    if(pPerson!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(pPerson[i].age<18&&!pPerson[i].isEmpty)
            {
                range1++;
                *x=range1;
            }
            else
            {
                if(pPerson[i].age>17&&pPerson[i].age<36&&!pPerson[i].isEmpty)
                {
                    range2++;
                    *y=range2;
                }
                else if(pPerson[i].age>35&&!pPerson[i].isEmpty)
                {
                    range3++;
                    *z=range3;
                }
            }
        }
        value=0;
    }
    return value;
}

/** \brief Imprime un grafico de los rangos
 *
 * \param int x contador del primer rango
 * \param int y contador del segundo rango
 * \param int z contador del tercer rango
 * \return void
 *
 */

void printRanges(int x, int y, int z)
{
    int mayor;
    int i;
    int j;
    int vec[]={x,y,z};
    mayor=calculateMax(x,y,z);
    char matriz[mayor][3];
    for(j=0;j<mayor;j++)
    {
        for(i=0;i<3;i++)
        {
            if(vec[i]>j)
            {
                matriz[j][i]='*';
            }
            else
            {
                matriz[j][i]=' ';
            }
        }
    }
    for(j=mayor-1;j>=0;j--)
    {
        printf(" %c    %c    %c\n",matriz[j][0],matriz[j][1],matriz[j][2]);
    }
    printf("<18 18-35 >35\n");
}


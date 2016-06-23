#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lib.h"

/** \brief Solicita un nùmero al usuario y lo valida
 * \param input Se carga el nùmero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage1 Es el mensaje a ser mostrado en caso de ingreso erroneo del dato
 * \param eMessage2 Es el mensaje a ser mostrado en caso de que el dato este fuera del rango
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero retorna 0 sino -1
 *
 */
int getInt(int* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit)
{
    int value=-1;
    int auxInt;
    printf("%s",message);
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

/** \brief Pide una cadena de caracteres y valida su longitud y que solo sean numeros
  *
  * \param input Puntero al vector de caracteres
  * \param message Mensage para solicitar la cadena
  * \param eMessage1 Mensaje que informa si algun caracter no es numerico
  * \param eMessage2 Mensaje que informa si el largo de la cadena esta fuera de rango
  * \param lowLimit Valor minimo del rango de la cadena
  * \param hiLimit Vlor maximo del rango de la cadena
  * \return Si obtuvo la cadena numerica devuelve 0 sino -1
  *
  */
int getNumberString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit)
{
    int value=-1;
    int i;
    int length;
    int isNumber;
    char auxString[4096];
    printf("%s",message);
    setbuf(stdin,NULL);
    gets(auxString);
    length=strlen(auxString);
    if(length>=lowLimit&&length<=hiLimit)
    {
        for(i=0;i<length;i++)
        {
            isNumber=isdigit(auxString[i]);
            if(isNumber==0)
            {
                puts(eMessage1);
                break;
            }
            else
            {
                strcpy(input,auxString);
                value=0;
            }
        }
    }
    else
    {
        puts(eMessage2);
    }
    return value;
}

/** \brief Solicita una cadena de caracteres al usuario y valida su longitud
 *
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a mostrar para pedir la cedna
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Longitud mìnima de la cadena
 * \param hiLimit Longitud màxima de la cadena
 * \return Si obtuvo la cadena retorna 0 sino -1
 *
 */
int getString(char* input,char message[],char eMessage[],int lowLimit,int hiLimit)
{
    int value=-1;
    int length;
    char auxString[4096];
    printf("%s",message);
    setbuf(stdin,NULL);
    gets(auxString);
    length=strlen(auxString);
    if(length>=lowLimit&&length<=hiLimit)
    {
        strcpy(input,auxString);
        value=0;
    }
    else
    {
        puts(eMessage);
    }
    return value;
}

/** \brief Solicita una cadena de caracteres al usuario valida su longitud y que solo sean letras
 *
 * \param input Se carga el string ingresado
 * \param message Es el mensaje a mostrar para pedir la cedna
 * \param eMessage1 Es el mensaje a ser mostrado si se ingresan caracteres invalidos
 * \param eMessage2 Es el mensaje a ser mostrado en caso que la longitud este fuera del rango
 * \param lowLimit Longitud mìnima de la cadena
 * \param hiLimit Longitud màxima de la cadena
 * \return Si obtuvo la cadena retorna 0 sino -1
 *
 */
int getLetterString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit)
{
    int value=-1;
    int length;
    int i;
    int isLetter;
    char auxString[4096];
    printf("%s",message);
    setbuf(stdin,NULL);
    gets(auxString);
    length=strlen(auxString);
    if(length>=lowLimit&&length<=hiLimit)
    {
        for(i=0; i<length; i++)
        {
            isLetter=isalpha(auxString[i]);
            if(!isLetter&&(auxString[i]!=' '||auxString[i]!='.'))
            {
                puts(eMessage1);
                break;
            }
        }
        strcpy(input,auxString);
        value=0;
    }
    else
    {
        puts(eMessage2);
    }
    return value;
}

/**
 *\brief Solicita una cadena de texto y valida que solo sean numeros y letras
 *
 *\param  char* input Puntero char donde se guardara la cadena
 *\param char message Mensage para solicitar la cadena
 *\param char eMessage1 Mensaje de error si el largo de la cadena esta fuera de rango
 *\param char eMessage2 Mensaje de error si se ingresa un caracter invalido
 *\param int lowLimit Longitud minima de la cadena
 *\param int hiLimit Longitud maxima la cadena
 *\return value devuelve -1 en caso de error y 0 si no hay error
 */
int getAlNum(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit)
{
    int value=-1;
    int i;
    int getFlag=0;
    int length;
    int isAlphaNumeric;
    char auxChar[4096];

    if(input!=NULL&&lowLimit>0)
    {
        setbuf(stdin,NULL);
        getFlag=getString(auxChar,message,eMessage1,lowLimit, hiLimit);
        length=strlen(auxChar);
        if(getFlag==0)
        {
            for(i=0;i<length;i++)
            {
                isAlphaNumeric=isalnum(auxChar[i]);
                if(!isAlphaNumeric&&auxChar[i]!=' ')
                {
                    puts(eMessage2);
                }
                else
                {
                    strcpy(input,auxChar);
                    value=0;
                }
            }
        }
        else
        {
            printf("%s",eMessage1);
        }
    }
    return value;
}

/** \brief Solicita un nùmero al usuario y lo valida
 * \param input Se carga el nùmero ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el numero [0] si no [-1]
 *
 */
 int getFloat(float* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit)
 {
     int value=-1;
     float auxFloat;
     printf(message);
     setbuf(stdin,NULL);
     if(scanf("%f",&auxFloat)!=1)
    {
        puts(eMessage1);
    }
    else if(auxFloat<lowLimit||auxFloat>hiLimit)
    {
        puts(eMessage2);
    }
    else
    {
        *input=auxFloat;
        value=0;
    }
     return value;
 }

 /** \brief Solicita un caracter al usuario y lo valida
 * \param input Se carga el caracter ingresado
 * \param message Es el mensaje a ser mostrado
 * \param eMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit Limite inferior a validar
 * \param hiLimit Limite superior a validar
 * \return Si obtuvo el caracter [0] si no [-1]
 *
 */
int getChar(char* input,char message[],char eMessage[],char lowLimit,char hiLimit)
{
    int value=-1;
    char auxChar;
    printf(message);
    setbuf(stdin,NULL);
    scanf("%c",&auxChar);
    if(auxChar<lowLimit||auxChar>hiLimit)
    {
       puts(eMessage);
    }
    else
    {
        *input=auxChar;
        value=0;
    }
    return value;
}

/** \brief Recibe una cadena de caracteres y convierte la primer letra en mayuscula
 *
 * \param str Puntero a la cadena
 * \param isName Cuando el string tiene espacios indica si es un nombre (1) o no(0)
 * \return Devuelve 0 si formateo la cadena y -1 si no pudo
 *
 */
int firstCharUpper(char* str,int isName)
{
    int i;
    int retorno=-1;
    int length;
    if(str!=NULL)
    {
        length=strlen(str);
        strlwr(str);
        for(i=0; i<length; i++)
        {
            if(i==0)
            {
                str[i]=toupper(str[i]);
            }
            if(isName&&str[i]==' ')
            {
                str[i+1]=toupper(str[i+1]);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Muestra el menu de opciones y llama a las funciones segun la opcion elegida
 *
 * \param pList Puntero al Arraylist
 * \param pBackupList Puntero al Arraylist de respaldo
 * \return void
 *
 */
void menu(ArrayList* pList,ArrayList* pBackupList)
{
    int option=10;
    if(pList!=NULL)
    {
        do
        {
            system("cls");
            printf("\n*****************Menu************************\n\n"
            "1- Alta empleado\n"
            "2- Alta en posicion especifica\n"
            "3- Modificar empleado\n"
            "4- Baja empleado\n"
            "5- Baja con respaldo\n"
            "6- Opciones de respaldo\n"
            "7- Informes\n"
            "8- Vaciar listado\n"
            "9- Actualizar fichero\n"
            "0- Salir\n"
            "\n****************************************************\n\n");

            getInt(&option,"Elija una opcion: ","Solo debe ingresar numeros","Opcion invalida, debe ser un numero entre 0 y 9",0,9);

            switch(option)
            {
            case 1:
                addEmployee(pList,pBackupList);
                break;
            case 2:
                addInSpecific(pList,pBackupList);
                break;
            case 3:
                modifyEmployee(pList);
                break;
            case 4:
                removeEmployee(pList);
                break;
            case 5:
                removeWithBuckup(pList,pBackupList);
                break;
            case 6:
                backup(pList,pBackupList);
                break;
            case 7:
                inform(pList);
                break;
            case 8:
                clearList(pList);
                break;
            case 9:
                saveBinary(pList);
                break;
            case 0:
                exit(0);
            }
            system("pause");
        }while(1);
    }
}

/** \brief Guarda los datos del vector recibido en un archivo binario
 *
 * \param pList Puntero al arraylist
 * \return void
 *
 */
void saveBinary(ArrayList *pList)
{
    int i;
    if(pList!=NULL)
    {
        FILE *f;
        f=fopen("bin.dat", "r+b");
        if(f==NULL)
        {
            f=fopen("bin.dat","w+b");
            if(f==NULL)
            {
                exit(1);
            }
        }
        else
        {
            //printf("%d len",pList->len(pList));
            for(i=0;i<pList->len(pList);i++)
            {
                fwrite(*(pList->pElements+i),sizeof(Employee),1,f);
                //printf("OK");
            }
            printf("\nFichero guardado con exito\n");
        }
        fclose(f);
    }
}

/** \brief Guarda los datos del vector recibido en un archivo binario
 *
 * \param pList Puntero al arraylist
 * \return void
 *
 */
void saveBackUpBinary(ArrayList *pList)
{
    int i;
    if(pList!=NULL)
    {
        FILE *f;
        f=fopen("backup_bin.dat", "r+b");
        if(f==NULL)
        {
            f=fopen("backup_bin.dat","w+b");
            if(f==NULL)
            {
                exit(1);
            }
        }
        else
        {
            printf("%d len",pList->len(pList));
            for(i=0;i<pList->len(pList);i++)
            {
                fwrite(*(pList->pElements+i),sizeof(Employee),1,f);
                printf("OK");
            }
            printf("\nFichero guardado con exito\n");
        }
        fclose(f);
    }
}

/** \brief Carga los datos en el vector desde un archivo binario
 *
 * \param pList Puntero al vector
 * \return void
 *
 */
void readBinary(ArrayList* pList)
{
    Employee* auxEmp;
    void* pEmployee;
	FILE *f;
	if(pList!=NULL)
    {
        auxEmp=(Employee*)malloc(sizeof(Employee));
        f=fopen("bin.dat","rb");
        if(f!=NULL&&auxEmp!=NULL)
        {
            while(!feof(f))
            {
                fread(auxEmp,sizeof(Employee),1,f);
                pEmployee=newEmployee(auxEmp->id,auxEmp->name,auxEmp->lastName,auxEmp->salary,auxEmp->sector);
                if(!feof(f))
                {
                    pList->add(pList,pEmployee);
                }
            }
            //puts("Fichero cargado con exito");
            fclose(f);
            free(auxEmp);
            free(pEmployee);
        }
        else
        {
            puts("Fichero no encontrado");
        }
        //system("pause");
    }
}

/** \brief Carga los datos en el vector desde un archivo binario
 *
 * \param pList Puntero al vector
 * \return void
 *
 */
void readBackUpBinary(ArrayList* pList)
{
    Employee* auxEmp;
    void* pEmployee;
	FILE *f;
	if(pList!=NULL)
    {
        auxEmp=(Employee*)malloc(sizeof(Employee));
        f=fopen("backup_bin.dat","rb");
        if(f!=NULL&&auxEmp!=NULL)
        {
            while(!feof(f))
            {
                fread(auxEmp,sizeof(Employee),1,f);
                pEmployee=newEmployee(auxEmp->id,auxEmp->name,auxEmp->lastName,auxEmp->salary,auxEmp->sector);
                if(!feof(f))
                {
                    pList->add(pList,pEmployee);
                }
            }
            //puts("Fichero cargado con exito");
            fclose(f);
            free(auxEmp);
            free(pEmployee);
        }
        else
        {
            puts("Fichero no encontrado");
        }
        //system("pause");
    }
}

/** \brief Configura el Arraylist recibido como recien creado
 *
 * \param pList Puntero al Arraylist
 * \return void
 *
 */
void clearList(ArrayList* pList)
{
    int clear=0;
    if(pList!=NULL)
    {
        if(pList->len(pList)>0)
        {
            getInt(&clear,"Esta seguro que desea vaciar?[0-No/1-Si] ","Solo debe ingresar numeros","Opcion invalida[0-1]",0,1);
            if(clear)
            {
                pList->clear(pList);
                puts("Listado vaciado");
            }
        }
        else
        {
            puts("El listado ya esta vacio");
        }
    }
}

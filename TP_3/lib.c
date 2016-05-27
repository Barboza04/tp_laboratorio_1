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

/** \brief Recibe una cadena de caracteres y convierte la primera letra de cada palabra en mayuscula
 *
 * \param str Puntero a la cadena
 * \param cant Cantidad de caracteres de la cadena
 * \return Devuelve 0 si formateo la cadena y -1 si no pudo
 *
 */

int firstCharUpper(char* str,int cant)
{
    int i;
    int retorno=-1;

    if(str!=NULL&&cant>0)
    {
        strlwr(str);
        for(i=0; i<cant; i++)
        {
            if(i==0)
            {
                str[i]=toupper(str[i]);
            }
            if(str[i]==' ')
            {
                str[i+1]=toupper(str[i+1]);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief  Para indicar que todas las posiciones del vector estan vacias
 *          esta funcion inicializa el campo isEmpty en 1
 * \param pList Puntero al vector de peliculas
 * \param length Largo del vector de peliculas
 * \return value devuelve -1 en caso de error [Largo invalido o puntero NULL] y 0 si no hay error
 *
 */
int initBillboard(eMovie* pList, int length)
{
    int value=-1;
    int i;
    if(pList!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            pList[i].isEmpty=1;
        }
        value=0;
    }
    return value;
}

/** \brief Muestra el menu de opciones y llama a las funciones segun la opcion elegida
 *
 * \param pList Puntero al vector de peliculas
 * \param length Longitud del vector
 * \return void
 *
 */
void menu(eMovie *pList,int length)
{
    int option=0;

    do
    {
        system("cls");
        printf("\n*****************Menu*****************\n\n"
        "1- Agregar pelicula\n"
        "2- Modificar pelicula\n"
        "3- Borrar pelicula\n"
        "4- Generar pagina web\n"
        "5- Salir\n"
        "\n**************************************\n\n");

        getInt(&option,"Elija una opcion: ","Opcion invalida, solo debe ingresar numeros","Opcion invalida, debe estar entre 1 y 5",1,5);

        switch(option)
        {
        case 1:
            addMovie(pList,length);
            break;
        case 2:
            modifyMovie(pList,length);
            break;
        case 3:
            removeMovie(pList,length);
            break;
        case 4:
            generatePage(pList,length);
            break;
        case 5:
            saveBinary(pList,length);
            break;
        }
    }while(option!=5);
}

/** \brief Busca la primer posicion libre del vector de ppeliculas
 *
 * \param pList Vector donde busca el espacio libre
 * \param length largo del vector
 * \return int index devuelve -1 en caso de no encontrar una posicion libre y el indice de esa posicion en caso contrario
 *
 */

int findEmpty(eMovie *pList,int length)
{
    int index=-1;
    int i;
    for(i=0;i<length;i++)
    {
        if(pList[i].isEmpty)
        {
            index=i;
            break;
        }
    }
    return index;
}

/** \brief Guarda los datos del vector recibido en un archivo binario
 *
 * \param pList Puntero al vector
 * \param length Longitud del vector
 * \return void
 *
 */

void saveBinary(eMovie *pList,int length)
{
	FILE *f;
	f=fopen("bin.dat", "wb");
	if(f==NULL)
	{
		printf("No se pudo generar el fichero");
		exit(1);
	}

	fwrite(pList,sizeof(eMovie),length,f);


	printf("\nFichero guardado con exito\n");

	fclose(f);
}

/** \brief Carga los datos en el vector desde un archivo binario
 *
 * \param pList Puntero al vector
 * \param length Longitud del vector
 * \return void
 *
 */

void readrBinary(eMovie *pList,int length)
{
	FILE *f;
	f=fopen("bin.dat", "rb");
	if(f==NULL)
	{
		printf("Fichero no encontrado\n");
	}
	else
    {
        if(fread(pList,sizeof(eMovie),length,f))
        {
            printf("\nFichero cargado con exito\n\n");
            fclose(f);
        }

    }
	system("pause");

	fclose(f);
}

/** \brief Verifica si esta registrada la pelicula recibida por parametro
 *
 * \param pList Puntero al array
 * \param length Largo del array
 * \param title Titulo a verificar
 * \return value Retorna el indice si encuentra el titulo ingresado, sino -1
 *
 */
int checkByString(eMovie* pList,int length,char title[])
{
    int i;
    int value=-1;
    if(pList!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(!pList[i].isEmpty&&strcmp(pList[i].title,title)==0)
            {
                value=i;
                break;
            }
        }
    }
    return value;
}

/** \brief Agrega una pelicula al vector
 *
 * \param pList Puntero al vector de peliculas
 * \param length Puntero al entero del largo del vector
 * \return value Retorna 0 si agrego la pelicula y -1 si no pudo
 *
 */

int addMovie(eMovie *pList,int length)
{
    int value=-1;
    int index;
    char auxChar[4096];

    if(pList!=NULL&&length>0)
    {
        index=findEmpty(pList,length);
        puts("Datos de la palicula");
        if(index!=-1&&getAlNum(auxChar,"Titulo: ","Largo invalido","Caracter invalido",1,4095)!=-1)
        {
            if(checkByString(pList,length,auxChar)==-1||(checkByString(pList,length,auxChar)!=-1&&pList[checkByString(pList,length,auxChar)].isEmpty==1))
            {
                firstCharUpper(auxChar,strlen(auxChar));
                strcpy(pList[index].title,auxChar);
                if(!getString(auxChar,"Genero: ","Largo invalido, debe tener 30 caracteres como maximo",1,30)&&
                        !getNumberString(pList[index].duration,"Duracion(minutos): ","Solo debe ingresar numeros","Error, no puede ingresar numeros negativos",0,300)&&
                        !getString(pList[index].description,"Descripcion: ","Largo invalido, debe tener 600 caracteres como maximo",0,600)&&
                        !getInt(&pList[index].points,"Puntaje(1-100): ","Solo debe ingresar numeros","Debe ingresar numeros entre 1 y 100",1,100)&&
                        !getString(pList[index].imageLink,"Link de imagen: ","Largo invalido, debe tener 150 caracteres maximo",1,150))
                {
                    firstCharUpper(auxChar,strlen(auxChar));
                    strcat(pList[index].duration," min.");
                    strcpy(pList[index].genre,auxChar);
                    pList[index].isEmpty=0;
                    printf("Carga completada con exito\n");
                    system("pause");
                    value=0;
                }
            }
            else
            {
                printf("Pelicula ya cargada\n");
            }

        }
        else
        {
            printf("No hay lugares libres\n");
        }
    }
    return value;
}

/** \brief Busca una pelicula por su titulo y realiza un borrado logico
 *
 * \param pList Puntero al vector de peliculas
 * \param length Longitud del vector de peliculas
 * \return value Retorna 0 si pudo borrar la pelicula y -1 si no pudo
 *
 */

int removeMovie(eMovie *pList,int length)
{
    int value=-1;
    int index=-1;
    FILE* html;
    char title[31];
    if(pList!=NULL&&length>0)
    {
        if(movieCounter(pList,length))
        {
            if(!getAlNum(title,"Ingrese el titulo de la pelicula: ","Largo invalido","Caracter invalido",1,30))
            {
                firstCharUpper(title,strlen(title));
                index=checkByString(pList,length,title);
                if(index!=-1)
                {
                    pList[index].isEmpty=1;
                    if(!movieCounter(pList,length))
                    {
                        html=fopen("movies.html","w");
                        if(html!=NULL)
                        {
                            fprintf(html,"\n<!DOCTYPE html>"
                            "\n<!-- Template by Quackit.com -->"
                            "\n<html lang='en'>"
                            "\n<head>"
                            "\n    <meta charset='utf-8'>"
                            "\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                            "\n    <meta name='viewport' content='width=device-width, initial-scale=1'>"
                            "\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
                            "\n    <title>Listado de peliculas</title>"
                            "\n    <!-- Bootstrap Core CSS -->"
                            "\n    <link href='css/bootstrap.min.css' rel='stylesheet'>"
                            "\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
                            "\n    <link href='css/custom.css' rel='stylesheet'>"
                            "\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
                            "\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
                            "\n    <!--[if lt IE 9]>"
                            "\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
                            "\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
                            "\n    <![endif]-->"
                            "\n</head>"
                            "\n<body>"
                            "\n    <div class='container'>"
                            "\n        <div class='row'>");
                            fprintf(html,"\n                <h1>"
                            "\n                    <a href='#'><DIV ALIGN=center><U>No hay peliculas registradas</U></DIV></a>"
                            "\n                </h1>");
                            fprintf(html,"    </div>"
                            "        <!-- /.row -->"
                            "    </div>"
                            "    <!-- /.container -->"
                            "    <!-- jQuery -->"
                            "    <script src='js/jquery-1.11.3.min.js'></script>"
                            "    <!-- Bootstrap Core JavaScript -->"
                            "    <script src='js/bootstrap.min.js'></script>"
                            "	<!-- IE10 viewport bug workaround -->"
                            "	<script src='js/ie10-viewport-bug-workaround.js'></script>"
                            "	<!-- Placeholder Images -->"
                            "	<script src='js/holder.min.js'></script>"
                            "</body>"
                            "</html>");
                        }
                        fclose(html);
                    }
                    printf("Pelicula borrada\n");
                }
                else
                {
                    printf("El titulo no coincide con ninguna pelicula registrada\n");
                }
            }
        }
        else
        {
            puts("No hay peliculas registradas");
        }
        system("pause");
    }
    return value;
}

/** \brief Busca una pelicula del vector y ofrece opciones para modificar
 *
 * \param pList Puntero al vector de peliculas
 * \param length Longitud del vector de peliculas
 * \return void
 *
 */
void modifyMovie(eMovie* pList,int length)
{
    int option=0;
    int index=-1;
    eMovie auxList;
    int stringLen;
    if(pList!=NULL&&length>0)
    {
        if(movieCounter(pList,length))
        {
            getAlNum(auxList.title,"Pelicula a modificar: ","Largo invalido","Caracter invalido",1,4095);
            firstCharUpper(auxList.title,strlen(auxList.title));
            index=checkByString(pList,length,auxList.title);
            if(index!=-1)
            {
                do
                {
                    printf("\n*****************Opciones de modificacion*****************\n\n"
                    "1- Modificar titulo\n"
                    "2- Modificar genero\n"
                    "3- Modificar duracion\n"
                    "4- Modoficar descripcion\n"
                    "5- Modificar puntaje\n"
                    "6- Modificar link\n"
                    "7- Finalizar modificaciones\n"
                    "\n**********************************************************\n\n");
                    getInt(&option,"Elija una opcion: ","Solo debe ingresar numeros\n","Laopcion debe estar entre 1 y 7\n",1,7);

                    switch(option)
                    {
                    case 1:
                        getAlNum(auxList.title,"Nuevo titulo: ","Largo invalido","Caracter invalido",1,4095);
                        stringLen=strlen(auxList.title);
                        firstCharUpper(auxList.title,stringLen);
                        strcpy(pList[index].title,auxList.title);
                        break;
                    case 2:
                        getString(auxList.genre,"Genero: ","Largo invalido, debe tener 30 caracteres como maximo",1,30);
                        stringLen=strlen(auxList.genre);
                        firstCharUpper(auxList.genre,stringLen);
                        strcpy(pList[index].genre,auxList.genre);
                        break;
                    case 3:
                        getNumberString(auxList.duration,"Nueva duracion(minutos): ","Solo debe ingresar numeros","Error, no puede ingresar numeros negativos",0,300);
                        strcat(auxList.duration," min.");
                        break;
                    case 4:
                        getString(auxList.description,"Nueva descripcion: ","Largo invalido, debe tener 500 caracteres como maximo",0,600);
                        break;
                    case 5:
                        getInt(&auxList.points,"Nuevo puntaje: ","Solo debe ingresar numeros","Debe ingresar numeros entre 1 y 10",1,10);
                        break;
                    case 6:
                        getString(auxList.imageLink,"Nuevo link de imagen: ","Largo invalido, debe tener 150 caracteres maximo",1,150);
                        break;
                    case 7:
                        break;
                    }
                }
                while(option!=7);
            }
            else
            {
                puts("Pelicula no encontrada");
            }
            pList[index].isEmpty=0;
        }
        else
        {
            puts("No hay peliculas registradas");
        }
    }
    system("pause");
}

 /** \brief Genera un archivo html con los datos de un vector
  *
  * \param pList Puntero al vector
  * \param length Longitud del vector
  * \return void
  *
  */
void generatePage(eMovie *pList,int length)
{
    int i;
    FILE* html;
    if(pList!=NULL&&length>0)
    {
        if(movieCounter(pList,length))
        {
            html=fopen("movies.html","w");
            if(html!=NULL)
            {
                fprintf(html,"\n<!DOCTYPE html>"
                "\n<!-- Template by Quackit.com -->"
                "\n<html lang='en'>"
                "\n<head>"
                "\n    <meta charset='utf-8'>"
                "\n    <meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                "\n    <meta name='viewport' content='width=device-width, initial-scale=1'>"
                "\n    <!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
                "\n    <title>Lista peliculas</title>"
                "\n    <!-- Bootstrap Core CSS -->"
                "\n    <link href='css/bootstrap.min.css' rel='stylesheet'>"
                "\n    <!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
                "\n    <link href='css/custom.css' rel='stylesheet'>"
                "\n    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
                "\n    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
                "\n    <!--[if lt IE 9]>"
                "\n        <script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
                "\n        <script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
                "\n    <![endif]-->"
                "\n</head>"
                "\n<body>"
                "\n    <div class='container'>"
                "\n        <div class='row'>");
                for(i=0; i<length; i++)
                {
                    if(!pList[i].isEmpty)
                    {
                        fprintf(html,"\n			<!-- Repetir esto para cada pelicula -->"
                        "\n            <article class='col-md-4 article-intro'>"
                        "\n                <a href='#'>"
                        "\n                    <img class='img-responsive img-rounded' src='%s' alt=''>",pList[i].imageLink);
                        fprintf(html,"\n                </a>"
                        "\n                <h3>"
                        "\n                    <a href='#'>%s</a>",pList[i].title);
                        fprintf(html,"\n                </h3>"
                        "\n				<ul>");
                        fprintf(html,"\n					<li>Genero: %s</li>",pList[i].genre);
                        fprintf(html,"\n					<li>Puntaje: %d</li>",pList[i].points);
                        fprintf(html,"\n					<li>Duracion: %s</li>	",pList[i].duration);
                        fprintf(html,"\n				</ul>"
                        "\n                <p> %s</p>",pList[i].description);
                        fprintf(html," \n          </article>"
                        "	\n		<!-- Repetir esto para cada pelicula -->");
                    }
                }
                fprintf(html,"    </div>"
                "        <!-- /.row -->"
                "    </div>"
                "    <!-- /.container -->"
                "    <!-- jQuery -->"
                "    <script src='js/jquery-1.11.3.min.js'></script>"
                "    <!-- Bootstrap Core JavaScript -->"
                "    <script src='js/bootstrap.min.js'></script>"
                "	<!-- IE10 viewport bug workaround -->"
                "	<script src='js/ie10-viewport-bug-workaround.js'></script>"
                "	<!-- Placeholder Images -->"
                "	<script src='js/holder.min.js'></script>"
                "</body>"
                "</html>");
            }
            fclose(html);
            puts("Pagina  generada con exito");
        }
        else
        {
            puts("No hay peliculas registradas");
        }
    }
    system("pause");
}

/** \brief Cuenta la cantidad de peliculas cargadas en el vector
 *
 * \param pList puntero al vector
 * \param length Longitud del vector
 * \return movies Cantidad de peliculas
 *
 */
int movieCounter(eMovie *pList,int length)
{
    int i;
    int movies=0;
    if(pList!=NULL&&length>0)
    {
        for(i=0;i<length;i++)
        {
            if(!pList[i].isEmpty)
            {
                movies++;
            }
        }
    }
    return movies;
}

/** \brief Carga datos de tres estructuras para prueba de funciones
 *
 * \param pList Puntero al vector de peliculas
 * \return void
 *
 */

void test(eMovie* pList)
{
    eMovie prueba[3]={{"Batman","Action, Adventure","126 min.","The Dark Knight of Gotham City begins his war on crime with his first major enemy being the clownishly homicidal Joker.",
    72,"http://ia.media-imdb.com/images/M/MV5BMTYwNjAyODIyMF5BMl5BanBnXkFtZTYwNDMwMDk2._V1_SX640_SY720_.jpg",0},
    {"V For Vendetta","Action, Drama, Thriller","132 min.","In a future British tyranny, a shadowy freedom fighter, known only by the alias of 'V', plots to overthrow it with the help of a young"
    "woman.",82,"http://ia.media-imdb.com/images/M/MV5BOTI5ODc3NzExNV5BMl5BanBnXkFtZTcwNzYxNzQzMw@@._V1_SX640_SY720_.jpg",0},
    {"Watchmen","Action, Adventure, Mystery","162 min.","In an alternate 1985 where former superheroes exist, the murder of a colleague sends active vigilante Rorschach into his own sprawling"
    " investigation, uncovering something that could completely change the course of history as we know it.",76,"http://ia.media-imdb.com/images/M/MV5BMTc0NjI2OTYxMF5BMl5BanBnXkFtZTcwMTcxMjkyMg@@._V1_SX640_SY720_.jpg",0}};

    int i;
    for (i=0; i<3; i++)
    {
        pList[i]=prueba[i];
    }
    puts("Vector cargado");
}

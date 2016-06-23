#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "lib.h"

/** \brief Pide los datos y crea un empleado
 *
 * \param pList Puntero al Arraylist
 * \param pBackupList Puntero al Arraylist de respaldo
 * \return void
 *
 */
void addEmployee(ArrayList* pList,ArrayList* pBackupList)
{
    int i;
    int auxId=pList->len(pList)+1;
    Employee auxEmployee;
    if(pList!=NULL)
    {
        if(!getLetterString(auxEmployee.name,"Ingrese nombre: ","Solo debe ingresar letras","Debe tener 50 caracteres como maximo",1,50)&&
           !getLetterString(auxEmployee.lastName,"Ingrese apellido: ","Solo debe ingresar letras","Debe tener 50 caracteres como maximo",1,50)&&
           !getFloat(&auxEmployee.salary,"Ingrese salario: ","Solo debe ingresar numeros","El salario debe estar entre 1000 y 5000",1000.00,5000.00)&&
           !getInt(&auxEmployee.sector,"Ingrese sector(1-5): ","Solo debe ingresar numeros","El sector debe estar entre 1 y 5",1,5))
        {
            firstCharUpper(auxEmployee.name,1);
            firstCharUpper(auxEmployee.lastName,1);
            for(i=0;i<pBackupList->len(pBackupList);i++)
            {
                if(((Employee*)*(pBackupList->pElements+i))->id==auxId)
                {
                    auxId++;
                }
                else
                {
                    break;
                }
            }
            if(!pList->add(pList,newEmployee(auxId,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector)))
            {
                printEmployee(pList->get(pList,pList->len(pList)-1));
            }
        }
    }
}

/** \brief Pide los datos y crea un empleado en la posicion especificada
 *
 * \param pList Puntero al Arraylist
 * \param pBackupList Puntero al Arraylist de respaldo
 * \return void
 *
 */
void addInSpecific(ArrayList* pList,ArrayList* pBackupList)
{
    int i;
    int option=0;
    int index;
    int auxId=pList->len(pList)+1;
    Employee auxEmployee;
    if(pList!=NULL)
    {
        if(!getInt(&index,"Posicion: ","Solo debe ingresar numeros","Opcion fuera de rango",0,pList->len(pList))&&
           !getLetterString(auxEmployee.name,"Ingrese nombre: ","Solo debe ingresar letras","Debe tener 50 caracteres como maximo",1,50)&&
           !getLetterString(auxEmployee.lastName,"Ingrese apellido: ","Solo debe ingresar letras","Debe tener 50 caracteres como maximo",1,50)&&
           !getFloat(&auxEmployee.salary,"Ingrese salario: ","Solo debe ingresar numeros","El salario debe estar entre 1000 y 5000",1000.00,5000.00)&&
           !getInt(&auxEmployee.sector,"Ingrese sector(1-5): ","Solo debe ingresar numeros","El sector debe estar entre 1 y 5",1,5))
        {
            firstCharUpper(auxEmployee.name,1);
            firstCharUpper(auxEmployee.lastName,1);
            for(i=0;i<pBackupList->len(pBackupList);i++)
            {
                if(((Employee*)*(pBackupList->pElements+i))->id==auxId)
                {
                    auxId++;
                }
                else
                {
                    break;
                }
            }
            if(index<pList->len(pList))
            {
                printf("La posicion ya esta ocupada\n");
                printEmployee(pList->get(pList,index));
                getInt(&option,"\nDesea sobreescribrla?[1-Si/2-No]","Solo debe ingresar numeros","Opcion invalida[1-2]",1,2);
                if(option==1)
                {
                    pList->set(pList,index,newEmployee(auxId,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector));
                    printEmployee(pList->get(pList,index));
                }
                else if(option==2)
                {
                    pList->push(pList,index,newEmployee(auxId,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector));
                    printEmployee(pList->get(pList,index));
                }
            }
            else
            {
                pList->add(pList,newEmployee(auxId,auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector));
                printEmployee(pList->get(pList,pList->len(pList)-1));
            }
        }
    }
}

/** \brief Remueve un empleado del Arraylist
 *
 * \param pList Puntero al Arraylist
 * \return void
 *
 */

void removeEmployee(ArrayList* pList)
{
    int auxId;
    int remove=0;
    if(pList!=NULL)
    {
        if(!pList->isEmpty(pList))
        {
            getInt(&auxId,"Id a dar de baja: ","Solo debe ingresar numeros","Valor fuera de rango",1,pList->len(pList));
            if(checkById(pList,auxId)!=-1)
            {
                printf("Empleado encontrado\n");
                printEmployee(pList->get(pList,checkById(pList,auxId)));
                printf("1- Si\n"
                       "2- No\n");
                getInt(&remove,"Seguro que desea darlo de baja?","Solo debe ingresar numeros","Opcion fuera de rango [1-2]",1,2);
                if(remove==1)
                {
                    pList->remove(pList,checkById(pList,auxId));
                    puts("Baja completa\nEs necesario actualizar los ficheros");
                }
            }
        }
        else
        {
            puts("Listado vacio");
        }
    }
}

/** \brief Remueve en empleado del Arraylist y lo agrega al respaldo
 *
 * \param plist Puntero al Arraylist
 * \param pBackupList Puntero al Arraylist de respaldo
 * \return void
 *
 */

void removeWithBuckup(ArrayList* pList,ArrayList* pBackupList)
{
    int auxId;
    int remove=0;
    if(pList!=NULL)
    {
        if(!pList->isEmpty(pList))
        {
            getInt(&auxId,"Id a dar de baja: ","Solo debe ingresar numeros","Valor fuera de rango",1,pList->len(pList));
            if(checkById(pList,auxId)!=-1&&checkById(pList,auxId)==-1)
            {
                printf("Empleado encontrado\n");
                printEmployee(pList->get(pList,checkById(pList,auxId)));
                printf("1- Si\n"
                       "2- No\n");
                getInt(&remove,"Seguro que desea darlo de baja?","Solo debe ingresar numeros","Opcion fuera de rango [1-2]",1,2);
                if(remove==1)
                {
                    pList->push(pBackupList,pBackupList->len(pBackupList),pList->get(pList,checkById(pList,auxId)));
                    pList->remove(pList,checkById(pList,auxId));
                    puts("Baja completa\nEs necesario actualizar los ficheros");
                }
            }
            else if(checkById(pList,auxId)!=-1&&checkById(pList,auxId)!=-1)
            {
                puts("El empleado ya existe en el listado de respaldo");
                printEmployee(pBackupList->get(pBackupList,checkById(pBackupList,auxId)));
                printf("1- Si\n"
                       "2- No\n");
                getInt(&remove,"Seguro que desea darlo de baja?","Solo debe ingresar numeros","Opcion fuera de rango [1-2]",1,2);
                if(remove==1)
                {
                    pList->remove(pList,checkById(pList,auxId));
                    puts("Baja completa\nEs necesario actualizar los ficheros");
                }
            }
            else
            {
                puts("Empleado no encontrado");
            }
        }
        else
        {
            puts("Listado vacio");
        }
    }
}

 /** \brief Muestra un menu de informes
 *
 * \param pList Puntero al arraylist
 * \return void
 *
 */
void inform(ArrayList* pList)
{
    int option=0;
    int order;
    int from;
    int to;
    ArrayList* subList;
    if(pList!=NULL&&!pList->isEmpty(pList))
    {
        do
        {
            system("cls");
            printf("\n***********Menu de infromes***********\n\n"
            "1- Mostrar listado\n"
            "2- Ordenar listado\n"
            "3- Mostrar sublista\n"
            "4- Menu principal\n\n"
            "\n**************************************\n\n");

            getInt(&option,"Elija una opcion: ","Solo debe ingresar numeros","Opcion invalida, debe ser un numero entre 1 y 4",1,4);

            switch(option)
            {
            case 1:
                printArrayListEmployee(pList);
                break;
            case 2:
                do
                {
                    printf("\n***********Menu de sublista***********\n\n"
                    "1- Ordenar por id\n"
                    "2- Ordenar por nombre\n"
                    "3- Ordenar por apellido\n"
                    "4- Ordenar por salario\n"
                    "5- Ordenar por sector\n"
                    "6- Volver al menu de informes\n\n"
                    "\n**************************************\n\n");
                    getInt(&option,"Elija una opcion: ","Solo debe ingresar numeros","Opcion fuera de rango [1-6]",1,6);
                    switch(option)
                    {
                    case 1:
                        getInt(&order,"Ascendente (1) Descendente (0): ","Solo debe ingresar numeros","Opcion invalida, debe ser un numero entre 0 y 1",0,1);
                        if(!pList->sort(pList,compareId,order))
                        {
                            puts("Listado ordenado");
                        }
                        break;
                    case 2:
                        getInt(&order,"Ascendente (1) Descendente (0): ","Solo debe ingresar numeros","Opcion invalida, debe ser un numero entre 0 y 1",0,1);
                        if(!pList->sort(pList,compareName,order))
                        {
                            puts("Listado ordenado");
                        }
                        break;
                    case 3:
                        getInt(&order,"Ascendente (1) Descendente (0): ","Solo debe ingresar numeros","Opcion invalida, debe ser un numero entre 0 y 1",0,1);
                        if(!pList->sort(pList,compareSureame,order))
                        {
                            puts("Listado ordenado");
                        }
                        break;
                    case 4:
                        getInt(&order,"Ascendente (1) Descendente (0): ","Solo debe ingresar numeros","Opcion invalida, debe ser un numero entre 0 y 1",0,1);
                        if(!pList->sort(pList,compareSalary,order))
                        {
                            puts("Listado ordenado");
                        }
                        break;
                    case 5:
                        getInt(&order,"Ascendente (1) Descendente (0): ","Solo debe ingresar numeros","Opcion invalida, debe ser un numero entre 0 y 1",0,1);
                        if(!pList->sort(pList,compareSector,order))
                        {
                            puts("Listado ordenado");
                        }
                        break;
                    }
                }while(option!=6);
                break;
            case 3:
                if(!getInt(&from,"Desde (Indice incluyente): ","Solo debe ingresar numeros","Indice fuera de rango",0,pList->len(pList))&&
                !getInt(&to,"Hasta (Indice excluyente): ","Solo debe ingresar numeros","Indice fuera de rango",0,pList->len(pList)))
                {
                    subList=pList->subList(pList,from,to);
                    printArrayListEmployee(subList);
                }
                break;
            }
            system("pause");
        }while(option!=4);
    }
    else
    {
        puts("Listado vacio");
    }
}

/** \brief Imprime los datos de un empleado
 *
 * \param p Puntero a el empleado
 * \return void
 *
 */

void printEmployee(Employee* p)
{
    printf("Id:%d\nNombre:%s\nApellido:%s\nSalario:%.2f\nSector:%d\n",p->id,p->name,p->lastName,p->salary,p->sector);
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }
    return returnAux;
}

/** \brief Verifica si esta registrado el id
 *
 * \param pList Puntero al arraylist
 * \param id Id a verificar
 * \return value Retorna el indice si encuentra el id ingresado, sino -1
 *
 */
int checkById(ArrayList* pList,int id)
{
    int i;
    int value=-1;
    if(pList!=NULL&&id>0&&id<=pList->len(pList))
    {
        for(i=0;i<pList->len(pList);i++)
        {
            if(((Employee*)*(pList->pElements+i))->id==id)
            {
                value=i;
                break;
            }
        }
    }
    return value;
}

/** \brief Busca un empleado y ofrece opciones de modificacion
 *
 * \param pList Puntero al Arraylist
 * \return void
 *
 */
void modifyEmployee(ArrayList* pList)
{
    int option=0;
    int auxId;
    int index;
    Employee* auxEmployee;
    if(pList!=NULL)
    {
        if(!pList->isEmpty(pList))
        {
            getInt(&auxId,"Id del empleado a modificar: ","Solo debe ingresar numeros","Valor fuera de rango",1,pList->len(pList));
            index=checkById(pList,auxId);
            auxEmployee=pList->get(pList,index);
            if(auxEmployee!=NULL)
            {
                do
                {
                    system("cls");
                    printf("\n*****************Opciones de modificacion*****************\n\n"
                    "1- Nombre: %s/Modificar\n"
                    "2- Apellido: %s/Modificar\n"
                    "3- Salario: %.2f/Modificar\n"
                    "4- Sector: %d/Modoficar\n"
                    "5- Menu principal\n\n"
                    "\n**********************************************************\n\n",
                    (((Employee*)*(pList->pElements+index))->name),(((Employee*)*(pList->pElements+index))->lastName),(((Employee*)*(pList->pElements+index))->salary),(((Employee*)*(pList->pElements+index))->sector));
                    getInt(&option,"Elija una opcion: ","Solo debe ingresar numeros\n","La opcion debe estar entre 1 y 7\n",1,7);

                    switch(option)
                    {
                    case 1:
                        getLetterString(auxEmployee->name,"Nombre nuevo: ","Solo debe ingresar letras","Debe tener 50 caracteres como maximo",1,50);
                        firstCharUpper(auxEmployee->name,1);
                        break;
                    case 2:
                        getLetterString(auxEmployee->lastName,"Apellido nuevo: ","Solo debe ingresar letras","Debe tener 50 caracteres como maximo",1,50);
                        firstCharUpper(auxEmployee->lastName,1);
                        break;
                    case 3:
                        getFloat(&auxEmployee->salary,"Nuevo salario: ","Solo debe ingresar numeros","El salario debe estar entre 1000 y 5000",1000.00,5000.00);
                        break;
                    case 4:
                        getInt(&auxEmployee->sector,"Nuevo sector(1-5)","Solo debe ingresar numeros","El sector debe estar entre 1 y 5",1,5);
                        break;
                    }
                    printEmployee(auxEmployee);
                    system("pause");
                }
                while(option!=5);
            }
            else
            {
                puts("Empleado no encontrado");
            }
        }
        else
        {
            puts("Listado vacio");
        }
    }
}

/** \brief Compara dos elementos por el campo nombre
 *
 * \param pEmployeeA Puntero al primer empleado
 * \param pEmployeeB Puntero al segundo empleado
 * \return int Devuelve 1 si A es mayor que B
 *                     -1 si A es menor que B
 *                      0 si son iguales
 *
 */
int compareName(void* pEmployeeA,void* pEmployeeB)
{
    if(strcmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)>0)
    {
        return 1;
    }
    if(strcmp(((Employee*)pEmployeeA)->name,((Employee*)pEmployeeB)->name)<0)
    {
        return -1;
    }
    return 0;
}

/** \brief Compara dos elementos por el campo apellido
 *
 * \param pEmployeeA Puntero al primer empleado
 * \param pEmployeeB Puntero al segundo empleado
 * \return int Devuelve 1 si A es mayor que B
 *                     -1 si A es menor que B
 *                      0 si son iguales
 *
 */
int compareSureame(void* pEmployeeA,void* pEmployeeB)
{
    if(strcmp(((Employee*)pEmployeeA)->lastName,((Employee*)pEmployeeB)->lastName)>0)
    {
        return 1;
    }
    if(strcmp(((Employee*)pEmployeeA)->lastName,((Employee*)pEmployeeB)->lastName)<0)
    {
        return -1;
    }
    return 0;
}

/** \brief Compara dos elementos por el campo salario
 *
 * \param pEmployeeA Puntero al primer empleado
 * \param pEmployeeB Puntero al segundo empleado
 * \return int Devuelve 1 si A es mayor que B
 *                     -1 si A es menor que B
 *                      0 si son iguales
 *
 */
int compareSalary(void* pEmployeeA,void* pEmployeeB)
{
    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;
}

/** \brief Compara dos elementos por el campo id
 *
 * \param pEmployeeA Puntero al primer empleado
 * \param pEmployeeB Puntero al segundo empleado
 * \return int Devuelve 1 si A es mayor que B
 *                     -1 si A es menor que B
 *                      0 si son iguales
 *
 */
int compareId(void* pEmployeeA,void* pEmployeeB)
{
    if(((Employee*)pEmployeeA)->id > ((Employee*)pEmployeeB)->id)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->id < ((Employee*)pEmployeeB)->id)
    {
        return -1;
    }
    return 0;
}

/** \brief Compara dos elementos por el campo sector
 *
 * \param pEmployeeA Puntero al primer empleado
 * \param pEmployeeB Puntero al segundo empleado
 * \return int Devuelve 1 si A es mayor que B
 *                     -1 si A es menor que B
 *                      0 si son iguales
 *
 */
int compareSector(void* pEmployeeA,void* pEmployeeB)
{
    if(((Employee*)pEmployeeA)->sector > ((Employee*)pEmployeeB)->sector)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->sector < ((Employee*)pEmployeeB)->sector)
    {
        return -1;
    }
    return 0;
}

/** \brief Imprime todos los empleados del Arraylist
 *
 * \param lista Puntero al Arraylist
 * \return void
 *
 */
void printArrayListEmployee(ArrayList* lista)
{
  int i;
  for(i=0;i<lista->len(lista);i++)
  {
      Employee* pAux = lista->get(lista,i);
      printEmployee(pAux);
      if(i>0&&i%30==0)
      {
          system("pause");
      }
  }
}

/** \brief Muestra un menu de opciones y llama a las funciones segun la opcion elegida
 *
 * \param pList Puntero al Arraylist
 * \param pBackupList
 * \return
 *
 */
void backup(ArrayList* pList,ArrayList* pBackupList)
{
    int option=0;
    int auxId;
    int index;
    ArrayList* auxBackup=NULL;
    ArrayList* restoreList=NULL;
    if(pList!=NULL&&pBackupList!=NULL&&!pList->isEmpty(pList))
    {
        do
        {
            system("cls");
            printf("\n*******************Opciones de respaldo*******************\n\n"
            "1- Crear listado de respaldo\n"
            "2- Buscar empleado en listado de resplado\n"
            "3- Restaurar listado de respaldo\n"
            "4- Borrar listado de respaldo\n"
            "5- Menu principal\n\n"
            "\n**********************************************************\n\n");
            getInt(&option,"Elija una opcion: ","Solo debe ingresar numeros\n","La opcion debe estar entre 1 y 5\n",1,5);

            switch(option)
            {
            case 1:
                if(!pBackupList->isEmpty(pBackupList))
                {
                    auxBackup=pList->clone(pList);
                    if(auxBackup!=NULL)
                    {
                        pBackupList=auxBackup;
                        saveBackUpBinary(pBackupList);
                        puts("Respaldo creado con exito");
                    }
                    else
                    {
                        puts("Error al crear el respaldo");
                    }
                }
                else
                {
                    do
                    {
                        puts("Ya existe un listado de respaldo");
                        printf("\n**********************************************************\n"
                               "1- Sobreescribir\n"
                               "2- Comparar con litado actual\n"
                               "3- Menu de respaldo\n"
                               "\n**********************************************************\n\n");
                        getInt(&option,"Elija una opcion: ","Solo debe ingresar numeros\n","La opcion debe estar entre 1 y 3\n",1,3);
                        switch(option)
                        {
                        case 1:
                            auxBackup=pList->clone(pList);
                            if(auxBackup!=NULL)
                            {
                                pBackupList=auxBackup;
                                saveBackUpBinary(pBackupList);
                                puts("Sobreescritura completa");
                            }
                            else
                            {
                                puts("Error al sobreescribir");
                            }
                            break;
                        case 2:
                            if(!pBackupList->isEmpty(pBackupList))
                            {
                                if(!pList->containsAll(pBackupList,pList))
                                {
                                    puts("Listados diferentes");
                                }
                                else if(pList->containsAll(pBackupList,pList))
                                {
                                    puts("Listados iguales");
                                }
                            }
                            else
                            {
                                puts("Listado de respaldo no encontrado");
                            }
                            break;
                        }
                    }
                    while(option!=3);
                }
                break;
            case 2:
                if(!pBackupList->isEmpty(pBackupList))
                {
                    getInt(&auxId,"Id a buscar: ","Solo debe ingresar numeros","Id fuera de rango",0,pList->len(pList));
                    index=pList->indexOf(pBackupList,pList->get(pList,checkById(pList,auxId)));
                    if(index!=-1)
                    {
                        printEmployee(pList->get(pList,index));
                    }
                    else
                    {
                        puts("Empleado no encontrado");
                    }
                }
                else
                {
                    puts("Listado de respaldo no encontrado");
                }
                break;
            case 3:
                if(!pBackupList->isEmpty(pBackupList))
                {
                    restoreList=pBackupList->clone(pBackupList);
                    if(restoreList!=NULL)
                    {
                        pList=restoreList;
                        pList->clear(restoreList);
                    }
                }
                else
                {
                    puts("Listado de respaldo no encontrado");
                }
                break;
            case 4:
                if(!pBackupList->isEmpty(pBackupList))
                {
                    if(!pList->deleteArrayList(pBackupList))
                    {
                        puts("Respaldo borrado");
                    }
                }
                else
                {
                    puts("Listado de respaldo no encontrado");
                }
                break;
            }
            system("pause");
        }
        while(option!=5);
    }
    else
    {
        puts("Listado vacio");
    }
    pList->deleteArrayList(pBackupList);
    pList->deleteArrayList(restoreList);
}

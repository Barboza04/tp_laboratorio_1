#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#endif // FUNCIONES_H_INCLUDED

typedef struct
{

    char name[51];
    int age;
    int dni;
    int isEmpty;

}ePerson;
int getString(char* input,char message[],char eMessage[],int lowLimit, int hiLimit);
int getInt(int* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit);
int initPersons(ePerson* pPerson, int length);
int addPerson(ePerson* pPerson, int length, char name[], int age, int dni);
ePerson* findByDni(ePerson* pPerson, int length,int id);
int removePerson(ePerson* pPerson, int length, int dni);
int sortPersonsByName(ePerson* pPerson, int length);
int printPersons(ePerson* pPerson, int length);
int calculateMax(int x, int y, int z);
int getRanges(ePerson* pPerson, int length, int* x, int* y, int* z);
void printRanges(int x, int y, int z);

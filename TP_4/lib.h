#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED



#endif // LIB_H_INCLUDED
#include "ArrayList.h"
#include "Employee.h"

void clearList(ArrayList* pList);
int getInt(int* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit);
int getString(char* input,char message[],char eMessage[],int lowLimit,int hiLimit);
int getLetterString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit);
int getAlNum(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit);
int getNumberString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit);
int getFloat(float* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit);
int getChar(char* input,char message[],char eMessage[],char lowLimit,char hiLimit);
void saveBinary(ArrayList *pList);
void saveBackUpBinary(ArrayList *pList);
void readBinary(ArrayList* pList);
void readBackUpBinary(ArrayList* pList);
void menu(ArrayList* pList,ArrayList* pBackupList);
int firstCharUpper(char* str,int cant);

#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED



#endif // LIB_H_INCLUDED

typedef struct
{
    char title[31];
    char genre[31];
    char duration[10];
    char description[601];
    int points;
    char imageLink[151];
    int isEmpty;
}eMovie;

int getInt(int* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit);
int getString(char* input,char message[],char eMessage[],int lowLimit,int hiLimit);
int getLetterString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit);
int getAlNum(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit,int hiLimit);
int getNumberString(char* input,char message[],char eMessage1[],char eMessage2[],int lowLimit, int hiLimit);
int initBillboard(eMovie* pList, int length);
void saveBinary(eMovie *pList,int length);
void readrBinary(eMovie *pList,int length);
void showBillboard(eMovie *pList,int length);
void menu(eMovie *pList,int length);
int findEmpty(eMovie *pList,int length);
int checkByString(eMovie* pList,int length,char title[]);
int addMovie(eMovie *pList,int length);
void modifyMovie(eMovie* pList,int length);
int removeMovie(eMovie *pList,int length);
void generatePage(eMovie *pList,int length);
int movieCounter(eMovie *pList,int length);
int firstCharUpper(char* str,int cant);
void test(eMovie* pList);

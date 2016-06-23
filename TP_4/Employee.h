/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "ArrayList.h"
#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;
#endif // __EMPLOYEE

void addEmployee(ArrayList* pList,ArrayList* pBackupList);
void addInSpecific(ArrayList* pList,ArrayList* pBackupList);
int compareId(void* pEmployeeA,void* pEmployeeB);
int compareName(void* pEmployeeA,void* pEmployeeB);
int compareSalary(void* pEmployeeA,void* pEmployeeB);
int compareSector(void* pEmployeeA,void* pEmployeeB);
int compareSureame(void* pEmployeeA,void* pEmployeeB);
int checkById(ArrayList* pList,int id);
void modifyEmployee(ArrayList* pList);
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector);
int parser(FILE* f,ArrayList* x);
void printArrayListEmployee(ArrayList* lista);
void printEmployee(Employee* p);
void removeEmployee(ArrayList* pList);
void removeWithBuckup(ArrayList* pList,ArrayList* pBackupList);
void inform(ArrayList* pList);
void backup(ArrayList* pList,ArrayList* pBackupList);

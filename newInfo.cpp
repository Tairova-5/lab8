#define _CRT_SECURE_NO_WARNINGS
#define LC_ALL 0

#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

//#include "Header.h"
using namespace std;

struct Student
{
    char* name; //»м€
    int number; // номер зачетки
    float srMark; //—редн€€ оценка за сессию
    int scholarship; // это стипенди€: 0 - нет стипухи, 1 - обычна€, 2 - 50%, 3 - 100%
    int year;
};

int newinfo(int leng, Student** temp) //вычисл€емое поле
{
    if (temp[leng]->srMark == 5.0)
        return 4;
    if (temp[leng]->srMark < 5.0 && temp[leng]->srMark >= 4.5)
        return 3;
    if (temp[leng]->srMark < 4.5 && temp[leng]->srMark >= 4.0)
        return 2;
    if (temp[leng]->srMark < 4.0)
        return 1;
}
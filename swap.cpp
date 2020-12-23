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

Student** arr = nullptr;

void swaper(Student**& arr, int i, int j) //смена позиций в сортировке
{
    Student* temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

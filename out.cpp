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
    char* name; //Имя
    int number; // номер зачетки
    float srMark; //Средняя оценка за сессию
    int scholarship; // это стипендия: 0 - нет стипухи, 1 - обычная, 2 - 50%, 3 - 100%
    int year;
};

void out(Student** arr, int leng)  //вывод на экран
{
    for (int i = 0; i < leng; i++)
    {
        cout << "Студент " << i + 1 << ":\n";
        cout << "ФИО: " << arr[i]->name << "\n";
        cout << "Номер зачётки: " << arr[i]->number << "\n";
        cout << "Год рождения: " << arr[i]->year << "\n";
        cout << "Средний балл за последнюю сессию: " << arr[i]->srMark << "\n";
        cout << "Размер стипендии: ";
        if (arr[i]->scholarship == 1)
            cout << "не платится\n\n";
        if (arr[i]->scholarship == 2)
            cout << "обычная\n\n";
        if (arr[i]->scholarship == 3)
            cout << "+50%\n\n";
        if (arr[i]->scholarship == 4)
            cout << "+100%\n\n";
    }
}
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
#include "Header.h"
using namespace std;

struct Student
{
    char* name; //Имя
    int number; // номер зачетки
    float srMark; //Средняя оценка за сессию
    int scholarship; // это стипендия: 0 - нет стипухи, 1 - обычная, 2 - 50%, 3 - 100%
    int year;
};

void deletSt(Student**& arr, int& leng) //удаление студента
{
    Student** temp = new Student * [leng - 1];
    int perebor = 0;
    int extra = 0;
    cout << "Имеется информация о " << leng << " студентах. Введите номер подлежащего удалению.\n";
    while (true)
    {
        extra = static_cast<int> (test(1));
        if (extra >= 1 && extra <= leng)
            break;
        else
            cout << "Пожалуйста, выберете существующий вариант.\n";
    }
    extra--;
    for (int i = 0; i < leng; i++)
    {
        if (i == extra)
        {
            delete[] arr[extra]->name;
            delete[] arr[extra];
        }
        else
        {
            temp[perebor] = arr[i];
            perebor++;
        }
    }
    cout << "Информация о студенте удалена.\n";
    leng--;
    delete[] arr;
    arr = temp;
}
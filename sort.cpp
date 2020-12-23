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
#include "6+.cpp"

using namespace std;

struct Student
{
    char* name; //Имя
    int number; // номер зачетки
    float srMark; //Средняя оценка за сессию
    int scholarship; // это стипендия: 0 - нет стипухи, 1 - обычная, 2 - 50%, 3 - 100%
    int year;
};

void sort(Student**& arr, int leng)  //сортировка
{
    printf("1- сортировка по имени.\n");
    printf("2- сортировка по номеру зачётки.\n");
    printf("3- сортировка по году рождения.\n");
    printf("4- сортировка по среднему баллу за последнюю сессию.\n");
    printf("5- сортировка по размеру стипендии.\n");
    int m;
    while (true)
    {
        m = static_cast<int> (test(1));
        if (m >= 1 && m <= 5)
            break;
        else
            cout << "Пожалуйста, выберете существующий вариант.\n";
    }
    for (int i = 0; i < leng - 1; i++)
        for (int j = i + 1; j < leng; j++)
        {
            if (m == 1 && strcmp(arr[i]->name, arr[j]->name) > 0)
                swaper(arr, i, j);
            if (m == 2 && arr[i]->number > arr[j]->number)
                swaper(arr, i, j);
            if (m == 3 && arr[i]->year > arr[j]->year)
                swaper(arr, i, j);
            if (m == 4 && arr[i]->srMark > arr[j]->srMark)
                swaper(arr, i, j);
            if (m == 5 && arr[i]->scholarship > arr[j]->scholarship)
                swaper(arr, i, j);
            cout << "Информация о студентах отсортирована.\n";
        }
}
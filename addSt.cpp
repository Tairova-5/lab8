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
    char* name; //»м€
    int number; // номер зачетки
    float srMark; //—редн€€ оценка за сессию
    int scholarship; // это стипенди€: 0 - нет стипухи, 1 - обычна€, 2 - 50%, 3 - 100%
    int year;
};

void addSt(Student**& arr, int& leng) //добавление с клавы
{
    Student** temp = new Student * [leng + 1];
    for (int i = 0; i < leng; i++)  //копируем что есть
    {
        temp[i] = arr[i];
    }
    delete arr;
    //а теперь ввод нового
    temp[leng] = new Student;
    cout << "¬ведите ‘»ќ студента:\n";
    temp[leng]->name = inputName();
    cout << "¬ведите номер зачЄтной книжки студента:\n";
    temp[leng]->number = static_cast<int> (test(1));
    cout << "¬ведите год рождени€ студента:\n";
    temp[leng]->year = static_cast<int> (test(1));
    cout << "¬ведите средний балл студента за последнюю сессию:\n";
    temp[leng]->srMark = test(2);
    //вычисл€емое поле
    temp[leng]->scholarship = newinfo(leng, temp);
    arr = temp;
    cout << "Ёлемент добавлен.\n";
    leng++;
}
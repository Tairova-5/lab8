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

float test(int mod);
char* inputName();
int newinfo(int leng, Student** temp);
void addSt(Student**& arr, int& leng);
void swaper(Student**& arr, int i, int j);
void sort(Student**& arr, int leng);
char* readName(FILE* file);

void readFl(FILE* file, Student**& readarr, int& lengadd);
void printFl(FILE* file1, Student** arr, int leng);

void out(Student** arr, int leng);
void deletSt(Student**& arr, int& leng);


Student* readSt(FILE* file) //чтение инфы о студенте
{
    Student* temp = new Student;
    temp->name = readName(file);
    fscanf(file, "%d;\n", &temp->number);
    fscanf(file, "%d;\n", &temp->year);
    fscanf(file, "%f;\n", &temp->srMark);
    if (temp->scholarship == 5.0)
        temp->scholarship = 4;
    if (temp->srMark < 5.0 && temp->srMark >= 4.5)
        temp->scholarship = 3;
    if (temp->srMark < 4.5 && temp->srMark >= 4.0)
        temp->scholarship = 2;
    if (temp->srMark < 4.0)
        temp->scholarship = 1;
    return temp;
}

int main()
{

    setlocale(LC_ALL, "RUS");
    bool w = true;
    int menu;
    int c1 = 0;
    Student** arr = nullptr;
    int leng = 0;
    int lengadd = 0;
    while (w == true)
    {
        cout << "----------МЕНЮ----------\n";
        cout << "1- добавление стуента.\n";
        cout << "2- удаление студента.\n";
        cout << "3- сортировка информации о студентах.\n";
        cout << "4- вывод информации о студентах.\n";
        cout << "5- запись данных в файл.\n";
        cout << "6- выход.\n";
        cout << "------------------------\n";

        while (true)
        {
            menu = static_cast<int> (test(1));
            if (menu <= 6 && menu >= 1)
                break;
            else
                cout << "Пожалуйста, выберете существующий вариант.\n";
        }
        switch (menu)
        {
        case 1: //добавление элемента
        {
            cout << "1- ввести данные с клавиатуры.\n";
            cout << "2- считать данные из файла.\n";
            while (true)
            {
                c1 = static_cast<int> (test(1));
                if (c1 == 1 || c1 == 2)
                    break;
                else
                    cout << "Пожалуйста, выберете существующий вариант.\n";
            }
            if (c1 == 1) //ручной ввод
                addSt(arr, leng);
            if (c1 == 2) //чтение из файла
            {
                FILE* file = fopen("C:\\Users\\79293\\Desktop\\project\\6 laba\\input.txt", "r");
                if (file == NULL)
                    cout << "Файла не существует.\n";
                else
                {
                    Student** readarr = nullptr;
                    readFl(file, readarr, lengadd);
                    fclose(file);
                    Student** tmp = new Student * [leng + lengadd];
                    int p = 0;
                    for (int i = 0; i < leng; i++)
                    {
                        tmp[i] = arr[i];
                    }
                    for (int i = leng; i < leng + lengadd + 1; i++)
                    {
                        tmp[i] = readarr[p];
                        p++;
                    }
                    delete[] arr;

                    arr = new Student * [leng + lengadd];
                    for (int i = 0; i <= leng + lengadd; i++)
                    {
                        arr[i] = tmp[i];
                    }
                    leng = leng + lengadd;

                    delete[] readarr;
                    delete[] tmp;
                    cout << "Данные считаны.\n";
                }
            }
            break;
        }
        case 2: //удаление
        {
            if (leng != 0)
                deletSt(arr, leng);
            else
                cout << "Информация о студентах ещё не была добавлена.\n";

            break;
        }
        case 3: //сортирвка
        {
            if (leng != 0)
            {
                if (leng == 1)
                    cout << "Недостаточно данных о студентах для сортировки.\n";
                else

                    sort(arr, leng);
            }
            else
                cout << "Информация о студентах ещё не была добавлена.\n";

            break;
        }
        case 4: //вывод
        {
            if (leng != 0)
                out(arr, leng);
            else
                cout << "Информация о студентах ещё не была добавлена.\n";

            break;
        }
        case 5: //запись в файд
        {
            if (leng != 0)
            {
                FILE* file1 = fopen("C:\\Users\\79293\\Desktop\\project\\6 laba\\finish.txt", "w");
                printFl(file1, arr, leng);
                fclose(file1);
                cout << "Данные записаны в файл.\n";
            }
            else
                cout << "Информация о студентах ещё не была добавлена.\n";

            break;
        }
        case 6: //выход
        {
            w = false;
            break;
        }
        }
    }
    for (int i = 0; i < leng; i++)
    {
        delete[] arr[i]->name;
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
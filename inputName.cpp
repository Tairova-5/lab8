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

char* inputName()  //ввод имени
{
    int ln = 1;
    char* tmp = NULL;
    char* str = new char[ln];
    while (true)
    {
        str[ln - 1] = _getch();
        if (str[ln - 1] == 13)
        {
            str[ln - 1] = '\0';
            break;
        }
        if (str[ln - 1] == '\0')
            continue;
        if (str[ln - 1] == '\b' && (ln - 1) != 0)
        {
            cout << str[ln - 1];
            cout << ' ';
            cout << str[ln - 1];
            tmp = new char[ln - 1];
            for (int i = 0; i < ln - 2; i++)
                tmp[i] = str[i];
            delete[] str;
            str = tmp;
            ln--;
        }
        else
        {
            if ((ln - 1) == 0 && str[ln - 1] == '\b')
                continue;
            cout << str[ln - 1];
            tmp = new char[ln + 1];
            for (int i = 0; i < ln; i++)
                tmp[i] = str[i];
            delete[] str;
            str = tmp;
            ln++;
        }
    }
    cout << endl;
    return str;
}
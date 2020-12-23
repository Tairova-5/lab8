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

float test(int mod)
{
    float x;
    if (mod == 1) //для целых
    {
        int z;
        while (true)  //фильтр абракадабры
        {
            if (cin >> z)
            {
                if (z < 0)
                    cout << "Невозможное значение. Попробуйте снова.\n";
                else
                    break;
            }
            else
            {
                cout << "Невозможное значение. Попробуйте снова.\n";
                cin.clear();
                while (getchar() != '\n');
            }
        }
        x = static_cast<float>(z);
    }
    else //специально отдельный для среднего балла
    {
        while (true)
        {
            if (cin >> x)
            {
                if (x < 0 || x > 5)
                    cout << "Невозможное значение. Попробуйте снова.\n";
                else
                    break;
            }
            else
            {
                cout << "Невозможное значение. Попробуйте снова.\n";
                cin.clear();
                while (getchar() != '\n');
            }
        }
    }
    return x;
}
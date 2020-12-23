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

char* readName(FILE* file) //чтение имени
{

    char* str = new char[1];
    char symbol = '\0';
    int symbolCount = 0;
    while (symbol != ';')
    {
        fscanf(file, "%c", &symbol);
        if (symbol == ';')
        {
            break;
        }

        char* tmpStr = new char[symbolCount + 2];
        for (int i = 0; i < symbolCount; i++)
        {
            tmpStr[i] = str[i];
        }
        tmpStr[symbolCount] = symbol;
        delete[] str;
        str = tmpStr;
        symbolCount++;
    }
    str[symbolCount] = '\0';
    return str;
}
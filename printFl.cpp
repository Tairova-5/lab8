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
    char* name; //���
    int number; // ����� �������
    float srMark; //������� ������ �� ������
    int scholarship; // ��� ���������: 0 - ��� �������, 1 - �������, 2 - 50%, 3 - 100%
    int year;
};

void printFl(FILE* file1, Student** arr, int leng) //������ � ����
{
    for (int i = 0; i < leng; i++)
    {
        fprintf(file1, "%s;%d;%d;%f;\n", arr[i]->name, arr[i]->number, arr[i]->year, arr[i]->srMark);
    }
}
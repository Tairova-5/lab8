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
    char* name; //���
    int number; // ����� �������
    float srMark; //������� ������ �� ������
    int scholarship; // ��� ���������: 0 - ��� �������, 1 - �������, 2 - 50%, 3 - 100%
    int year;
};

void readFl(FILE* file, Student**& readarr, int& lengadd)  //������ �����
{
    int size = 0;
    while (!feof(file))
    {
        Student** temp = new Student * [size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = readarr[i];
        }
        temp[size] = readSt(file);
        delete[] readarr;
        readarr = temp;
        size++;
    }

    lengadd = size;
}
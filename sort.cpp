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
    char* name; //���
    int number; // ����� �������
    float srMark; //������� ������ �� ������
    int scholarship; // ��� ���������: 0 - ��� �������, 1 - �������, 2 - 50%, 3 - 100%
    int year;
};

void sort(Student**& arr, int leng)  //����������
{
    printf("1- ���������� �� �����.\n");
    printf("2- ���������� �� ������ �������.\n");
    printf("3- ���������� �� ���� ��������.\n");
    printf("4- ���������� �� �������� ����� �� ��������� ������.\n");
    printf("5- ���������� �� ������� ���������.\n");
    int m;
    while (true)
    {
        m = static_cast<int> (test(1));
        if (m >= 1 && m <= 5)
            break;
        else
            cout << "����������, �������� ������������ �������.\n";
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
            cout << "���������� � ��������� �������������.\n";
        }
}
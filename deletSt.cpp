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

void deletSt(Student**& arr, int& leng) //�������� ��������
{
    Student** temp = new Student * [leng - 1];
    int perebor = 0;
    int extra = 0;
    cout << "������� ���������� � " << leng << " ���������. ������� ����� ����������� ��������.\n";
    while (true)
    {
        extra = static_cast<int> (test(1));
        if (extra >= 1 && extra <= leng)
            break;
        else
            cout << "����������, �������� ������������ �������.\n";
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
    cout << "���������� � �������� �������.\n";
    leng--;
    delete[] arr;
    arr = temp;
}
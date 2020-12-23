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

void addSt(Student**& arr, int& leng) //���������� � �����
{
    Student** temp = new Student * [leng + 1];
    for (int i = 0; i < leng; i++)  //�������� ��� ����
    {
        temp[i] = arr[i];
    }
    delete arr;
    //� ������ ���� ������
    temp[leng] = new Student;
    cout << "������� ��� ��������:\n";
    temp[leng]->name = inputName();
    cout << "������� ����� �������� ������ ��������:\n";
    temp[leng]->number = static_cast<int> (test(1));
    cout << "������� ��� �������� ��������:\n";
    temp[leng]->year = static_cast<int> (test(1));
    cout << "������� ������� ���� �������� �� ��������� ������:\n";
    temp[leng]->srMark = test(2);
    //����������� ����
    temp[leng]->scholarship = newinfo(leng, temp);
    arr = temp;
    cout << "������� ��������.\n";
    leng++;
}
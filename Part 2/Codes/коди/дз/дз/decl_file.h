//decl_file.h - ������������ ����

#pragma once
#include<iostream>
#include<string.h>
#include <Windows.h>
#pragma warning(disable:4996) /* ��������� ��� ��������� ��������� ���������� */
using namespace std;

//��������� �����
struct Fraction
{
	int numerator, denominator; /* ��������� � ��������� */
	void EnterFraction(); /* �������� ����� */
	void PrintFraction(); /* ���� ����� */
};

//�������
int EnterNumber(); /* �������� �����*/
void EnterArrayFraction(Fraction*, int); /* �������� ������ */
void PrintArrayFraction(Fraction*, int); /* ���� ������ */
void SearchArrayFraction(Fraction*, int); /* ����� ����� ���������� ���� � ��������� ������� */
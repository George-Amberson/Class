#pragma once
#define _CRT_SECURE_NO_WARNINGS //����� �������� �� ������� 
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

class People
{
private:
	string Surname;
	string lifeplace;
	int birthyear;

public:
	People():Surname(""),lifeplace(""),birthyear(0){} // ����������� �� ��������� (���������� ������ �������������)
	People(const string& _surname, const string& _lifeplace, const int& _by); //����������� �� ����������
	string get_surname(); // ������ �������
	string get_lifeplace(); //������ ���������������
	int get_birthyear();// ������ ���� ��������
	void set_surname(const string& _surname); //������ �������
	void set_lifeplace(const string& _lp); //������ ���������������
	void set_birthyear(const int& _by); //������ ���� ��������
};

void read_from_file(People*& _array); //������� ��������� �� �����

void output_array_data(People* _array); //������� ������ ������

void correction_array_data(int num, People* _array); //������� ������������� ������

double middle_age(People* _array); //������� ������� �������� ��������

int output_into_file_array_data(People* _array, string& output); //������� ������ � ����


#pragma once
#define _CRT_SECURE_NO_WARNINGS //чтобы работала си функция 
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
	People() :Surname(""), lifeplace(""), birthyear(0) {} // конструктор по умолчанию (используем список инициализации)
	People(const string& _surname, const string& _lifeplace, const int& _by); //конструктор от параметров
	string get_surname(); // геттер фамилии
	string get_lifeplace(); //геттер местажительства
	int get_birthyear();// геттер даты раждения
	void set_surname(const string& _surname); //сеттер фамилии
	void set_lifeplace(const string& _lp); //сеттер местажительства
	void set_birthyear(const int& _by); //сеттер даты рождения
};

void read_from_file(People*& _array); //функция счтывания из файла

void output_array_data(People* _array); //функция вывода данных

void correction_array_data(int num, People* _array); //функция корректировки данных

double middle_age(People* _array); //функция посчета среднего возраста

int output_into_file_array_data(People* _array, string& output); //функция вывода в файл


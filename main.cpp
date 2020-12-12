﻿#include <iostream>
#include <string>
#include "People.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian"); //для работы с кирилицей

	People p1; //
	People p2("Goldshtein", "Moscow", 1999);//
	p1.set_surname("Smirmoff");
	p2.set_lifeplace("Paris");
	p1.set_birthyear(1989);
	cout << p1.get_surname() << " " << p1.get_lifeplace() << " " << p1.get_birthyear() << endl;
	cout << p2.get_surname() << " " << p2.get_lifeplace() << " " << p2.get_birthyear() << endl;
	People* _persons = nullptr;
	string output; // для ввода имени файла вывода или пути к нему
	People* PeopleArray = nullptr; // указатель на будущий массив структур
	int Numberofcummand = -1; // номер выбраной комманды
	int sumcommand = 0; //специальная сумма с помощью которой отслеживается что 
	//cчитывание из файла не производится больше 1 раза
	cout << "Меню:\n1-Вывести данные для проверки\n" <<
		"2-Корректировать данные для нужной строки\n3-Вычислить средний возраст по текущим данным\n"
		<< "4-Вывести данные в файл\n\n";
	try { // оборачиваем в тру чтобы если что ловить исключения из функций

		read_from_file(PeopleArray);//единственный раз вызываем функцию считывания из файла, больше к ней нет доступа

		while (sumcommand != 2) //sumcommand ==2 когда выполнены первая и последняя команда, то есть работа программы закончена
		{
			cin >> Numberofcummand; //считываем номер комманды
			switch (Numberofcummand) // классический свитч по номеру введеной команды, в зависимости от выбранной команды, вызывается та или иная функция
			{
			case 1:
				output_array_data(PeopleArray);//функция вывода данных
				break;
			case 2:
				int strnum;
				cout << "Введите пожалуйста номер строки данные в которой хотите редактировать (от 1 до 5)\n";
				cin >> strnum;
				correction_array_data(strnum, PeopleArray);//функция корректировки строки
				break;
			case 3:
				cout << "Средний возраст: " << middle_age(PeopleArray) << endl << endl;//функция посчета среднего возраста
				break;
			case 4:
				cout << "Введите имя файла для вывода\n";
				cin >> output;
				sumcommand += output_into_file_array_data(PeopleArray, output); //функция вывода в файл
				break;

			default:
				cout << "Вы ввели команду которой не существует. Пожалуйста выберете любую другую команду\n\n"; //дефолтная ветка в случае если введенный номер не соответствует ни одной из команд
			}
		}
	}
	catch (logic_error& e)// катч на логические ислючения
	{
		cout << e.what();//вывод текста исключения
	}

}
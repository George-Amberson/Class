#include <iostream>
#include <string>
#include "People.h"
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian"); //��� ������ � ���������

	People p1; //
	People p2("Goldshtein", "Moscow", 1999);//
	p1.set_surname("Smirmoff");
	p2.set_lifeplace("Paris");
	p1.set_birthyear(1989);
	cout << p1.get_surname() << " " << p1.get_lifeplace() << " " << p1.get_birthyear() << endl;
	cout << p2.get_surname() << " " << p2.get_lifeplace() << " " << p2.get_birthyear() << endl;
	People* _persons = nullptr;
	string output; // ��� ����� ����� ����� ������ ��� ���� � ����
	People* PeopleArray = nullptr; // ��������� �� ������� ������ ��������
	int Numberofcummand = -1; // ����� �������� ��������
	int sumcommand = 0; //����������� ����� � ������� ������� ������������� ��� 
	//c��������� �� ����� �� ������������ ������ 1 ����
	cout << "����:\n1-������� ������ ��� ��������\n" <<
		"2-�������������� ������ ��� ������ ������\n3-��������� ������� ������� �� ������� ������\n"
		<< "4-������� ������ � ����\n\n";
	try { // ����������� � ��� ����� ���� ��� ������ ���������� �� �������

		read_from_file(PeopleArray);//������������ ��� �������� ������� ���������� �� �����, ������ � ��� ��� �������

		while (sumcommand != 2) //sumcommand ==2 ����� ��������� ������ � ��������� �������, �� ���� ������ ��������� ���������
		{
			cin >> Numberofcummand; //��������� ����� ��������
			switch (Numberofcummand) // ������������ ����� �� ������ �������� �������, � ����������� �� ��������� �������, ���������� �� ��� ���� �������
			{
			case 1:
				output_array_data(PeopleArray);//������� ������ ������
				break;
			case 2:
				int strnum;
				cout << "������� ���������� ����� ������ ������ � ������� ������ ������������� (�� 1 �� 5)\n";
				cin >> strnum;
				correction_array_data(strnum, PeopleArray);//������� ������������� ������
				break;
			case 3:
				cout << "������� �������: " << middle_age(PeopleArray) << endl << endl;//������� ������� �������� ��������
				break;
			case 4:
				cout << "������� ��� ����� ��� ������\n";
				cin >> output;
				sumcommand += output_into_file_array_data(PeopleArray, output); //������� ������ � ����
				break;

			default:
				cout << "�� ����� ������� ������� �� ����������. ���������� �������� ����� ������ �������\n\n"; //��������� ����� � ������ ���� ��������� ����� �� ������������� �� ����� �� ������
			}
		}
	}
	catch (logic_error& e)// ���� �� ���������� ���������
	{
		cout << e.what();//����� ������ ����������
	}

}
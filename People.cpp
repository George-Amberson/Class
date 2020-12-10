#include "People.h"

People::People(const string& _surname, const string& _lifeplace, const int& _by)
{
		Surname = _surname;
		lifeplace = _lifeplace;
		birthyear = _by;
}
string People::get_surname()
{
	return(Surname);
}
string People::get_lifeplace()
{
	return(lifeplace);
}
int People::get_birthyear()
{
	return(birthyear);
}
void People::set_surname(const string& _surname)
{
	Surname = _surname;
}
void People::set_lifeplace(const string& _lp)
{
	lifeplace = _lp;
}
void People::set_birthyear(const int& _by)
{
	birthyear = _by;
}

void read_from_file(People*& _array)// �������� ������ �� ���������(���� ��������� ������ ���������, �� �� ���������� �� ��������, � ������ ����� � ������
{

	_array = new People[5]; //�������� ������ �� 5 ��������
	ifstream in; // ���������� ��� ���������� �� �����
	in.open("D:\\Structs\\inputfile.txt"); //��������� ���� ����� ���� � ����. ���� ����� ���� �����, ������� �� �������� ��� ����� ������ ������

	for (int i = 0; i < 5; i++)
	{
		string p1, p2;
		int p3;
		in >> p1 >> p2 >> p3;
		_array[i].set_surname(p1);
		_array[i].set_lifeplace(p2);
		_array[i].set_birthyear(p3);
	}
	cout << "��� ������ ��������." << "\n\n";
}

void output_array_data(People* _array)//������� ������ ������ �� �����
{
	if (_array == nullptr) throw logic_error("empty pointer"); //��������� �� �������� �� ��� ������� ���������
	for (int i = 0; i < 5; i++)
	{
		cout << _array[i].get_surname() << " " << _array[i].get_lifeplace()
			<< " " << _array[i].get_birthyear() << "\n";
	}
	cout << endl << endl;
}

void correction_array_data(int num, People* _array)//������� ������������� ������ � ������ ������
{
	if (_array == nullptr) throw logic_error("empty pointer"); //��������� �� �������� �� ��� ������� ���������
	if ((num < 1) || (num > 5)) throw logic_error("Number of string out of range");//��������� ���������� �� ����� ������ ��� ��������
	cout << "������� ���������� ����� ������ ���������� �������, ����� �������� � ��� ��������\n"; //���������� ����� �������� � �������� �� 1 �� 5 ��� �� 0 �� 4 ������� � ������ ������ ��� �� ������ ������������
	string ns, nl;
	int nb;
	cin >> ns >> nl >> nb;//��������� ����� ������
	_array[num].set_surname(ns);
	_array[num].set_lifeplace(nl);
	_array[num].set_birthyear(nb);
	cout << "��� ���������������\n\n";
}
double middle_age(People* _array)// ������� �������� �������� ��������
{
	if (_array == nullptr) throw logic_error("empty pointer");//��������� �� �������� �� ��� ������� ���������
	time_t rw = time(0);// ���������� ������ ��� ������ ������� localtime, ���� �� ���� �� �����.
	double middle_age = (localtime(&rw)->tm_year + 1900) * 5;//������� localtime ���������� ����� ����� ��������� � 1900. �� 5 �������� ����� ����� �� ����� ������������ �������� ���� � ����� �������� �� 5
	for (int i = 0; i < 5; i++) middle_age -= _array[i].get_birthyear();
	return (middle_age / 5);
}
int output_into_file_array_data(People* _array, string& output)//������� ������ � �������� ����
{
	if (_array == nullptr) throw logic_error("empty pointer");
	if (output.empty())throw logic_error("way is empty");//��������� ��� ��� �� �������� ������ ���/������ ������

	ofstream out(output);//������� ��������� ��� ������ � ����
	for (int i = 0; i < 5; i++)
	{
		out << _array[i].get_surname() << " " << _array[i].get_lifeplace() << " " << _array[i].get_birthyear() << "\n";
	}
	cout << "��� ������ ��������� ��������. ������ ��������� ���������.\n";
	return 2;
}

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

void read_from_file(People*& _array)// передаем ссылку на указатель(если передадим просто указатель, то он передастся по значению, и память уйдет в никуда
{

	_array = new People[5]; //выделили память на 5 элеметов
	ifstream in; // переменная для считывания из файла
	in.open("D:\\Structs\\inputfile.txt"); //открываем файл через путь к нему. Путь может быть любым, главное не забывать два слеша вместо одного

	for (int i = 0; i < 5; i++)
	{
		string p1, p2;
		int p3;
		in >> p1 >> p2 >> p3;
		_array[i].set_surname(p1);
		_array[i].set_lifeplace(p2);
		_array[i].set_birthyear(p3);
	}
	cout << "Все данные записаны." << "\n\n";
}

void output_array_data(People* _array)//функция вывода данных на экран
{
	if (_array == nullptr) throw logic_error("empty pointer"); //проверяем не передали ли нам нулевой указатель
	for (int i = 0; i < 5; i++)
	{
		cout << _array[i].get_surname() << " " << _array[i].get_lifeplace()
			<< " " << _array[i].get_birthyear() << "\n";
	}
	cout << endl << endl;
}

void correction_array_data(int num, People* _array)//функция корректировки данных в нужной строке
{
	if (_array == nullptr) throw logic_error("empty pointer"); //проверяем не передали ли нам нулевой указатель
	if ((num < 1) || (num > 5)) throw logic_error("Number of string out of range");//проверяем корректный ли номер строки нам передали
	cout << "Введите пожалуйста через пробел корректную фамилию, город рождения и год рождения\n"; //интуитивно проще работать с номерами от 1 до 5 чем от 0 до 4 поэтому я сделал именно так на уровне пользователя
	string ns, nl;
	int nb;
	cin >> ns >> nl >> nb;//считываем новые данные
	_array[num].set_surname(ns);
	_array[num].set_lifeplace(nl);
	_array[num].set_birthyear(nb);
	cout << "Все отредактировано\n\n";
}
double middle_age(People* _array)// функция подсчета среднего возраста
{
	if (_array == nullptr) throw logic_error("empty pointer");//проверяем не передали ли нам нулевой указатель
	time_t rw = time(0);// переменная нужная для работы функции localtime, сама по себе не нужна.
	double middle_age = (localtime(&rw)->tm_year + 1900) * 5;//функция localtime возвращает число годов прошелших с 1900. На 5 умнажаем чтобы сразу из этого произведения вычитать года и потом поделить на 5
	for (int i = 0; i < 5; i++) middle_age -= _array[i].get_birthyear();
	return (middle_age / 5);
}
int output_into_file_array_data(People* _array, string& output)//функция вывода в заданный файл
{
	if (_array == nullptr) throw logic_error("empty pointer");
	if (output.empty())throw logic_error("way is empty");//проверяем что нам не передали пустое имя/пустую строку

	ofstream out(output);//создаем перменную для вывода в файл
	for (int i = 0; i < 5; i++)
	{
		out << _array[i].get_surname() << " " << _array[i].get_lifeplace() << " " << _array[i].get_birthyear() << "\n";
	}
	cout << "Все данные корректно записаны. Работа программы завершена.\n";
	return 2;
}

// PracticalWork7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <wtypes.h>
#include <string>

using namespace std;

class PersonException
{
private:
	string message;

public:
	PersonException(const string& message) : message(message) {}

	const char* what() const throw() {
		return message.c_str();
	}
};

class Person
{
private:
	int id, age;
	string name;

public:
	Person(int id, const string& name, int age) : name(name), age(age), id(id)
	{
		if (age < 0 || age > 110)
		{
			throw PersonException("Invalid person age");
		}
		else if (id < 0 || id > 10000)
		{
			throw PersonException("Invalid person id");
		}
		else if (name.length() == 0 || name.length() > 15)
		{
			throw PersonException("Invalid person name");
		}
	}

	void displayInfo() {
		cout << endl;
		cout << "Имя: " << name << endl;
		cout << "ID: " << id << endl;
		cout << "Возраст: " << age << endl;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {

		try
		{
			int id, age;
			string name;

			cout << "Введите имя: ";
			getline(cin, name);

			cout << "Введите идентификатор: ";
			cin >> id;

			cout << "Введите возраст: ";
			cin >> age;

			unique_ptr<Person> person(new Person(id, name, age));
			person->displayInfo();
		}
		catch (const PersonException& ex)
		{
			cout << "Person Exception: " << ex.what() << endl;
		}
	}
	catch (const exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.dfs









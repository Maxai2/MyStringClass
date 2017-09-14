#include <iostream>
#include <string>

using namespace std;

class MyString
{
	char* symbols;
	int _length = 0;

public:
	MyString();
	MyString(char *str);
	MyString(string str);
	//Конструктор копирования
	MyString(MyString &str);
	//Деструктор
	~MyString() { delete[] symbols; }

	//Длинна строки
	int length();
	//Очистить строку
	void clear();
	//Пустая ли строка
	bool empty();
	//Вернуть char массив
	char* c_str();
	//Обменять значения двух строк
	void swap(MyString &str);
	//Вставить подстроку по индексу
	void insert(int index, MyString str);
	//Удалить символы
	void erase(int start, int count);
	//Заменить символы
	void replace(int start, int finish, MyString str);
	//Найти подстроку в строке и вернуть ее индекс
	int find(MyString str);

	friend MyString operator+(const MyString &t1, const MyString &t2);
	friend MyString operator+(const MyString &t1, const char *t2);
	friend MyString operator+(const char *t2, const MyString &t1);
	friend istream& operator>>(istream& in, MyString &t1);
	friend ostream& operator<<(ostream& out, MyString &t1);
	friend bool operator==(const MyString &t1, const MyString &t2);
	friend bool operator!=(const MyString &t1, const MyString &t2);
	friend bool operator>(const MyString &t1, const MyString &t2);
	friend bool operator<(const MyString &t1, const MyString &t2);
	friend bool operator>=(const MyString &t1, const MyString &t2);
	friend bool operator<=(const MyString &t1, const MyString &t2);
	friend char operator[](const MyString &t);
};
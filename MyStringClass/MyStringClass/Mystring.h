#include <iostream>
#include <string>

#include "Exception.h"

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
	//Конструктор перемещения
	MyString(MyString &&str);
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
	friend istream& operator>>(istream& in, MyString &t);
	friend ostream& operator<<(ostream& out, MyString &t);
	friend bool operator==(const MyString &t1, const MyString &t2);
	friend bool operator!=(const MyString &t1, const MyString &t2);
	friend bool operator>(const MyString &t1, const MyString &t2);
	friend bool operator<(const MyString &t1, const MyString &t2);
	friend bool operator>=(const MyString &t1, const MyString &t2);
	friend bool operator<=(const MyString &t1, const MyString &t2);
	

	char& operator[](const int index)
	{
		if (index >= 0 && index < _length)
			return this->symbols[index];
		else
			throw IndexException("This index is not allowed", index);
	}

	MyString& operator=(const MyString &str)
	{
		this->_length = str._length;
		delete[] this->symbols;
		this->symbols = new char[str._length + 1];
		strcpy(this->symbols, str.symbols);
		return *this;
	}

	MyString& operator=(const MyString &&str)
	{
		delete this->symbols;
		symbols = new char;
		*symbols = *str.symbols;
		return *this;
	}
};
#include <iostream>
#include <string>
using namespace std;

class MyString
{
	char* symbols;
	int length = 0;

public:
	MyString();
	MyString(char *str);
	MyString(string str);
	//Конструктор копирования
	MyString(const MyString &str);
	//Деструктор
	~MyString() {}

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
	void insert(int index, const MyString str);
	//Удалить символы
	void erase(int start, int count);
	//Заменить символы
	void replace(int start, int finish, const MyString str);
	//Найти подстроку в строке и вернуть ее индекс
	int find(const MyString str);
};

void main()
{
	MyString str;
	MyString str2("text");
	MyString str3 = str2;
}
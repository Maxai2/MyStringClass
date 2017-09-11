#pragma once
#include <iostream>
#include <string>

class MyString
{
	char* symbols;
	int length = 0;

public:
	MyString();
	MyString(char *str);
	MyString(std::string str);
	//Конструктор копирования
	MyString(MyString &str);
	//Деструктор
	~MyString() {};

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
};
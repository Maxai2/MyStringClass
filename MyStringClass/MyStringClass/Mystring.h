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
	//����������� �����������
	MyString(MyString &str);
	//����������
	~MyString() {};

	//������ ������
	int length();
	//�������� ������
	void clear();
	//������ �� ������
	bool empty();
	//������� char ������
	char* c_str();
	//�������� �������� ���� �����
	void swap(MyString &str);
	//�������� ��������� �� �������
	void insert(int index, MyString str);
	//������� �������
	void erase(int start, int count);
	//�������� �������
	void replace(int start, int finish, MyString str);
	//����� ��������� � ������ � ������� �� ������
	int find(MyString str);
};
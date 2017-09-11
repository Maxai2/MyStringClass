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
	//����������� �����������
	MyString(const MyString &str);
	//����������
	~MyString();

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
	void insert(int index, const MyString str);
	//������� �������
	void erase(int start, int count);
	//�������� �������
	void replace(int start, int finish, const MyString str);
	//����� ��������� � ������ � ������� �� ������
	int find(const MyString str);
};

void main()
{
	MyString str;
	MyString str2("text");
	MyString str3 = str2;
}
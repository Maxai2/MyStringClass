#include "Mystring.h"

MyString::MyString()
{
	this->symbols = new char[this->_length];
}

MyString::MyString(char * str)
{
	int index = 0;

	while (str[index++] != '\0') {}

	this->symbols = new char[index];
	memcpy(this->symbols, str, sizeof(char) * index);
	index--;
	this->_length = index;
}

MyString::MyString(string str)
{
	int index = 0;

	while (str[index++] != '\0') {}

	for (int i = 0; i < index; i++)
		this->symbols[i] = str[i];
	index--;
	this->_length = index;
}

MyString::MyString(MyString & str)
{
	*this->symbols = *str.symbols;
	this->_length = str._length;
	memcpy(this->symbols, str.symbols, sizeof(str.symbols));
}

int MyString::length()
{
	int index = 0;

	while (this->symbols[index] != '\0') { index++; }

	return index;
}

void MyString::clear()
{
	delete[] this->symbols;

	this->_length = 0;
	this->symbols = new char[this->_length];
}

bool MyString::empty()
{
	if (_length == 0)
		return true;
	else
		return false;
}

char * MyString::c_str()
{
	return this->symbols;
}

void MyString::swap(MyString & str)
{
	//	int buffer = 0;
	char *temp = nullptr;
	temp = this->symbols;
	this->symbols = str.symbols;
	str.symbols = temp;

	//buffer = this->_length;
	//this->_length = str._length;
	//str._length = buffer;

	this->_length = this->_length ^ str._length;
	str._length = this->_length ^ str._length;
	this->_length = this->_length ^ str._length;
}

void MyString::insert(int index, MyString str)
{
	index--;
	int size = this->_length + str._length + 1;
	char *temp = new char[size];

	for (int i = 0; i < index; i++)
		temp[i] = this->symbols[i];

	for (int i = index; i < str._length; i++)
		temp[i] = str.symbols[i];

	for (int i = str._length; i < size; i++)
		temp[i] = str.symbols[i];

	temp[size] = '\0';//

	delete[] this->symbols;
	this->symbols = temp;
}

void MyString::erase(int start, int count)
{
	start--;
	int size = this->_length - count + 1;//
	char *temp = new char[size];

	for (int i = 0; i < start; i++)
		temp[i] = this->symbols[i];

	for (int i = start; i < size; i++)
		temp[i] = this->symbols[i + count + 1];

	temp[size] = '\0';//

	delete[] this->symbols;//
	this->symbols = temp;
}

void MyString::replace(int start, int finish, MyString str)
{
	start--; finish--;
	int size = this->_length + str._length - (finish - start) + 1, counter = 0;
	char *temp = new char[size];

	for (int i = 0; i < start; i++, counter++)
		temp[counter] = this->symbols[i];

	for (int i = 0; i < str._length; i++, counter++)
		temp[counter] = str.symbols[i];

	for (int i = finish + 1; i < size; i++, counter++)
		temp[counter] = this->symbols[i];

	temp[size] = '\0';

	delete[] this->symbols;
	this->symbols = temp;
}

int MyString::find(MyString str)
{
	for (int i = 0, counter = 0; i < this->_length; i++)
	{
		if (this->symbols[i] == str.symbols[counter])
		{
			int reserv = i;
			while (str.symbols[counter] != '\0')
			{
				if (this->symbols[i] == str.symbols[counter])
				{
					reserv++; counter++;
				}
				else
					break;
			}
		}
	}

	return 0;
}

MyString operator+(const MyString &t1, const MyString &t2)
{
	int size = t1._length + t2._length + 1;
	int counter = 0;
	char *temp = new char[size];

	for (int i = 0; i < t1._length; i++, counter++)
		temp[counter] = t1.symbols[i];

	for (int i = 0; i < t2._length; i++, counter++)
		temp[counter] = t2.symbols[i];

	temp[size] = '\0';

	return MyString(temp);
}

MyString operator+(const MyString &t1, const char *t2)
{
	int index = 0;

	while (t2[index++] != '\0') {}

	int size = t1._length + index + 1, counter = 0;

	char *temp = new char[size];

	for (int i = 0; i < t1._length; i++, counter++)
		temp[counter] = t1.symbols[i];

	for (int i = 0; i < index; i++, counter++)
		temp[counter] = t2[i];

	temp[size] = '\0';

	return MyString(temp);
}

MyString operator+(const char *t2, const MyString &t1)
{
	int index = 0;

	while (t2[index++] != '\0') {}

	int size = t1._length + index + 1, counter = 0;

	char *temp = new char[size];

	for (int i = 0; i < index; i++, counter++)
		temp[counter] = t2[i];

	for (int i = 0; i < t1._length; i++, counter++)
		temp[counter] = t1.symbols[i];

	temp[size] = '\0';

	return MyString(temp);
}

istream& operator>>(istream& in, MyString &t)
{
	char* temp = new char[1000];
	cin.getline(temp, 1000);
	int len = strlen(temp);
	t._length = len;
	t.symbols = new char[len + 1];
	strcpy(t.symbols, temp);
	delete[] temp;
	return in;
}

ostream& operator<<(ostream& out, MyString &t)
{
	out << t.symbols;

	return out;
}

bool operator==(const MyString &t1, const MyString &t2)
{
	int size = 0;
	if (t1._length <= t2._length)
		size = t1._length;
	else
		if (t1._length > t2._length)
			size = t2._length;

	bool check = true;
	for (int i = 0; i < size || check; i++)
	{
		if (t1.symbols[i] != t2.symbols[i])
			check = false;
	}

	if (check == true)
		return false;
	else
		return true;
}

bool operator!=(const MyString &t1, const MyString &t2)
{
	return !(t1 == t2);
}


bool operator>(const MyString &t1, const MyString &t2)
{
	int size = 0;
	if (t1._length <= t2._length)
		size = t1._length;
	else
		if (t1._length > t2._length)
			size = t2._length;

	bool check = true;
	for (int i = 0; i < size || check; i++)
	{
		if (t1.symbols[i] < t2.symbols[i])
			check = false;
	}

	if (check == true)
		return false;
	else
		return true;
}

bool operator<(const MyString &t1, const MyString &t2)
{
	return !(t1 > t2);
}


bool operator>=(const MyString &t1, const MyString &t2)
{
	int size = 0;
	if (t1._length <= t2._length)
		size = t1._length;
	else
		if (t1._length > t2._length)
			size = t2._length;

	bool check = true;
	for (int i = 0; i < size || check; i++)
	{
		if (t1.symbols[i] > t2.symbols[i] || t1.symbols[i] == t2.symbols[i])
			continue;
		else
			if (t1.symbols[i] < t2.symbols[i] || t1.symbols[i] != t2.symbols[i])
				check = false;
	}

	if (check == true)
		return false;
	else
		return true;
}

bool operator<=(const MyString & t1, const MyString & t2)
{
	return !(t1 >= t2);
}

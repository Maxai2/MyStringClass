#include "Mystring.h"

MyString::MyString()
{
	this->symbols = new char[this->length];
}

MyString::MyString(char * str)
{
	int index = 0;

	while (str[index] != '\0') { index++; }
	
	memcpy(this->symbols, str, sizeof(char) * index);
}

MyString::MyString(string str)
{
	string *p = &str;

}

MyString::MyString( MyString & str)
{
	*this->symbols = *str;
}

int MyString::length()
{
	int index = 0;

	while (this->symbols[index] != '\0') {index++;}
	
	return index;
}

void MyString::clear()
{

}

bool MyString::empty()
{
	if (this->symbols.length() == 0)
		return true;
	else
		return false;
}

char * MyString::c_str()
{
	return nullptr;
}

void MyString::swap(MyString & str)
{
	
}

void MyString::insert(int index, MyString str)
{

}

void MyString::erase(int start, int count)
{

}

void MyString::replace(int start, int finish, MyString str)
{

}

int MyString::find(MyString str)
{
	return 0;
}

#include "Mystring.h"

void main()
{
	MyString str;
	MyString str2("text");
	char s[1000] = "aweergerg";
	MyString str3(s);
	str = "asdf";
	cout << "Old string: " << str << endl << "Input new string: ";
	cin >> str;
	cout << str << " " << str2 << " " << str3 << " " << str3.length() << endl;
	str2.clear();
	cout << "Str2 cleaned!" << endl;
	cout << str << " " << str2 << " " << str3 << " " << str3.length() << endl;
	cout << "Check, str2 is empty?" << str2.empty() ? cout << ":yes" << endl : cout << ":no" << endl;
}
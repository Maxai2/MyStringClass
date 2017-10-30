#pragma once
#include <stdexcept>  
#include <string>
#include <time.h>

using namespace std;
//----------------------------------------------------------------------------------------------
class MyException : public exception
{
protected:
	string text;
	string errorTime;
public:
	MyException(string text = "") : text(text)
	{
		time_t now = time(0);
		tm* localtm = localtime(&now);
		errorTime = asctime(localtm);
	}
	const char * what() const { return text.c_str(); }
	string getErrorTime() const { return errorTime; }
	virtual string getExceptionInfo() const { return "Base exception\n"; };
};
//----------------------------------------------------------------------------------------------
class IndexException : public MyException
{
	int index;
public:
	IndexException(string text, int index) : MyException(text), index(index) {}
	int getIndex() const { return index; }
	string getExceptionInfo() const { return "Index Exception\n"; };
};
//----------------------------------------------------------------------------------------------
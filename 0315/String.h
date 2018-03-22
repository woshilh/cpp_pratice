#include <string.h>
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

class String
{
	public:
		String()
		: _pstr(new char[1])
		{}

		String(const char * pstr)
		: _pstr(new char[strlen(pstr) + 1])
		{
			cout << "String(const char * )" << endl;
			strcpy(_pstr,pstr);
		}

		String(const String & rhs)
		: _pstr(new char[strlen(rhs._pstr)] + 1)
		{
			cout << "String(const String &)" << endl;
			strcpy(_pstr,rhs._pstr);
		}

		String(String && rhs)
		: _pstr(rhs._pstr)
		{
			cout << "String(String&&)" << endl;
			rhs._pstr = NULL;
		}

		String & operator=(String && rhs)
		{
			cout << "String & operator=(String&&)" << endl;
			delete []_pstr;
			_pstr = rhs._pstr;
			rhs._pstr = NULL;
			return *this;
		}

		String & operator=(const String & rhs)
		{
			cout << "String & operator=(const String & rhs)" << endl;
			if(this != &rhs)
			{
				String tmp(rhs);
				char * p = _pstr;
				_pstr = tmp._pstr;
				tmp._pstr = p;
			}
			return *this;
		}

		~String()
		{
			cout << "~String()" << endl;
			delete []_pstr;
		}

		String & operator+=(const String & rhs)
		{
			char *ptmp = new char[strlen(_pstr) + strlen(rhs._pstr) + 1];
			strcpy(ptmp,_pstr);
			strcat(ptmp,rhs._pstr);
			delete []_pstr;
			_pstr = ptmp;
			return *this;
		}
		
		friend std::ostream & operator<<(std::ostream & os,const String & rhs);
	private:
		char *_pstr;

};


std::ostream & operator<<(std::ostream & os,const String & rhs)
{
	os << rhs._pstr;
	return os;
}

String operator+(const String &lhs,const String &rhs)
{
	String tmp(lhs);
	tmp += rhs;
	return tmp;
}



#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


template <typename T>
class Singleton
{
private:
	class AutoRelease
	{
	public:
		AutoRelease()
		{
			cout << "AutoRelease()" << endl;
		}

		~AutoRelease()
		{
			if(_pInstance) 
			{
				delete _pInstance;
				cout << "~AutoRelease()" << endl;
			}
		}
	};
public:
	static T * getInstance()
	{
		if(_pInstance == NULL)
		{
			_ar;//对于模板而言,必须要进行实例化
			_pInstance = new T;
		}
		return _pInstance;
	}
private:
	Singleton(){}
	~Singleton(){}

private:
	static T * _pInstance;
	static AutoRelease _ar;
};

template <typename T>
T * Singleton<T>::_pInstance = NULL;

template <typename T>
typename Singleton<T>::AutoRelease Singleton<T>::_ar;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
	int * p1 = Singleton<int>::getInstance();
	cout << "*p1 = " << *p1 << endl;

	Point * p2 = Singleton<Point>::getInstance(); 
	p2->print();
	Point * p3 = Singleton<Point>::getInstance(); 

	printf("p2 = %p\n", p2);
	printf("p3 = %p\n", p3);
	
	return 0;
}


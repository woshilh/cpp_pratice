#include "Producer.h"
#include "Buffer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using std::endl;
using std::cout;

namespace wd
{

	Producer::Producer(Buffer & buf)
	: _buf(buf)
	{}

	void Producer::run()
	{
		::srand(::time(NULL));
		while(1)
		{
			int number = ::rand() % 100;
			_buf.push(number);
			cout << "produce a number: " << number << endl;
			sleep(2);
		}
	}
}

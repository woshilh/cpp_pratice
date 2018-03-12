#ifndef _MYTASK_H
#define _MYTASK_H

#include "Task.h"
#include <iostream>

namespace wd
{
class MyTask : public wd::Task
{
	public:
		void execute()
		{
			::srand(::time(NULL));
			int number = ::rand() % 100;
			std::cout << "number" << number << std::endl;
		}
};
}

#endif

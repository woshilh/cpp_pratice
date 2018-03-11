#ifndef _BUFFER_H
#define _BUFFER_H

#include "MutexLock.h"
#include "Condition.h"

#include <queue>

namespace wd
{

class Buffer
{
	public:
		Buffer(size_t size);
		void push(int);
		int pop();

		bool empty();
		bool full();

	private:
		MutexLock _mutex;
		Condition _notFull;
		Condition _notEmpty;
		size_t _size;
		std::queue<int> _queue;
};
}

#endif

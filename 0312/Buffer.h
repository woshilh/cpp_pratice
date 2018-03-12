#ifndef _BUFFER_H
#define _BUFFER_H

#include "MutexLock.h"
#include "Condition.h"

#include <queue>

namespace wd
{

class Task;
typedef Task* ElemType;

class Buffer
{
	public:
		Buffer(size_t size);
		void push(ElemType elem);
		ElemType pop();

		bool empty();
		bool full();
		void wakeup();
	private:
		MutexLock _mutex;
		Condition _notFull;
		Condition _notEmpty;
		size_t _size;
		std::queue<ElemType> _queue;
		bool _flag;
};
}

#endif

#include "Buffer.h"
#include <iostream>

using std::endl;
using std::cout;

namespace wd
{
	Buffer::Buffer(size_t size)
	: _size(size)
	  ,_mutex()
	  ,_notFull(_mutex)
	  ,_notEmpty(_mutex)
	  ,_flag(true)
	{}

	bool Buffer::empty()
	{
		return _queue.size() == 0;
	}

	bool Buffer::full()
	{
		return _queue.size() == _size;
	}

	void Buffer::push(ElemType elem)
	{
		MutexLockGuard guard(_mutex);
		while(full())
		{
			_notFull.wait();
		}
		_queue.push(elem);
		_notEmpty.notify();
	}

	ElemType Buffer::pop()
	{
		MutexLockGuard guard(_mutex);
		while(_flag && empty())
		{
			_notEmpty.wait();
		}
		if(_flag)
		{	
			ElemType ret = _queue.front();
			_queue.pop();
			_notFull.notify();
			return ret;
		}else
			return NULL;
	}
	
	void Buffer::wakeup()
	{
		_flag = false;
		_notEmpty.notifyall();
	}
}

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
	{}

	bool Buffer::empty()
	{
		return _queue.size() == 0;
	}

	bool Buffer::full()
	{
		return _queue.size() == _size;
	}

	void Buffer::push(int number)
	{
		_mutex.lock();
		while(full())
		{
			_notFull.wait();
		}
		_queue.push(number);
		_notEmpty.notify();
		_mutex.unlock();
	}

	int Buffer::pop()
	{
		_mutex.lock();
		while(empty())
		{
			_notEmpty.wait();
		}
		int ret = _queue.front();
		_queue.pop();

		_notFull.notify();
		_mutex.unlock();
		return ret;
	}

}

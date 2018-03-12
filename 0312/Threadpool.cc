#include "Threadpool.h"
#include "WorkerThread.h"
#include "Task.h"
#include <unistd.h>

namespace wd
{
	Threadpool::Threadpool(size_t threadNum,size_t buffSize)
	: _isExit(false)
	  ,_threadNum(threadNum)
	  ,_buffSize(buffSize)
	  ,_buff(_buffSize)
	{
		_threads.reserve(_threadNum);
	}

	Threadpool::~Threadpool()
	{
		if(!_isExit)
			stop();
	}

	void Threadpool::start()
	{
		for(size_t idx = 0 ;idx != _threadNum; ++idx)
		{
			Thread * p = new WorkerThread(*this);
			shared_ptr<Thread> sp(p);
			_threads.push_back(sp);
			sp->start();
		}
	}

	void Threadpool::stop()
	{
		if(!_isExit)
		{
			while(!_buff.empty())
			{
				sleep(1);
			}
			_isExit = true;
			cout << "tab" << endl;
			_buff.wakeup();
			cout << " second" << endl;
			for(auto & item : _threads)
			{
				item->join();
				cout << "thread's use_count = " << item.use_count() << endl;

			}
			_threads.clear();
		}
	}
	
	void Threadpool::addTask(Task * ptask)
	{
		_buff.push(ptask);
	}
	Task * Threadpool::getTask()
	{
		return _buff.pop();
	}

	void Threadpool::processTask()
	{
		while(!_isExit)
		{
			Task * ptask = getTask();
			if(ptask)
				ptask->execute();
		}
	}
}

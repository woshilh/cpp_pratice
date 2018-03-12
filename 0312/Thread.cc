#include "Thread.h"
#include <iostream>

using std::endl;
using std::cout;

namespace wd
{
	Thread::Thread()
	:_pthid(0)
	,_isRunning(false)
	{}

	void Thread::start()
	{
		pthread_create(&_pthid,NULL,threadFunc,this);
		_isRunning = true;
	}

	void Thread::join()
	{
		if(_isRunning)
		{
			cout << " jfieo" << endl;
			pthread_join(_pthid,NULL);
			cout << " jjfeoiafff" << endl;
			_isRunning = false;

		}
	}
	void * Thread::threadFunc(void * arg)
	{
		Thread * p = static_cast<Thread*>(arg);
		if(p)
		{
			p->run();
		}
		return NULL;
	}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			pthread_detach(_pthid);
		}
	}
}

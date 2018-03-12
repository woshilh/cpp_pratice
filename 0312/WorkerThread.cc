#include "WorkerThread.h"
#include "Threadpool.h"

namespace wd
{
	WorkerThread::WorkerThread(Threadpool & threadpool)
	:_threadpool(threadpool)
	{}
	
	void WorkerThread::run()
	{
		_threadpool.processTask();
	}
}

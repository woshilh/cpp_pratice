#ifndef _THREADPOOL_H
#define _THREADPOOL_H

#include "Buffer.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

namespace wd
{
	class Thread;

	class Threadpool
	{
		friend class WorkerThread;
		public:
			Threadpool(size_t threadNum,size_t bufSize);
			~Threadpool();
			
			void start();
			void stop();

			void addTask(Task *);

		private:
			Task * getTask();
			void processTask();

		private:
			bool _isExit;
			size_t _threadNum;
			size_t _buffSize;
			Buffer _buff;
			vector<shared_ptr<Thread> > _threads; 
	};
}
#endif


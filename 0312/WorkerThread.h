#ifndef _WORKERTHREAD_H
#define _WORKERTHREAD_H

#include "Thread.h"
#include <iostream>

using std::endl;
using std::cout;

namespace wd
{
	class Threadpool;
	class WorkerThread : public Thread
	{
		public:
			WorkerThread(Threadpool & threadpool);
			void run();

			~WorkerThread()
			{
				cout << "~WorkerThread()" << endl;
			}

		private:
			Threadpool & _threadpool;
	};
}

#endif

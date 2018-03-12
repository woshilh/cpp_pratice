#ifndef _THREAD_H
#define _THREAD_H

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
class Thread
:Noncopyable
{
	private:
		pthread_t _pthid;
		bool _isRunning;
	public:
		Thread();
		virtual ~Thread();

		virtual void run()=0;

		void start();
		void join();

		static void * threadFunc(void *arg);
};
}

#endif

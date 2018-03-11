
#ifndef __MUTEX_H
#define __MUTEX_H

#include "Noncopyable.h"
#include <pthread.h>

namespace wd
{
	
class MutexLock
: Noncopyable
{
	public:
		MutexLock();
		~MutexLock();

		void lock();
		void unlock();

		pthread_mutex_t * getMutexPtr();

	private:
		pthread_mutex_t _mutex;
		bool _isLocking;
};
}

#endif

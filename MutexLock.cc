#include "MutexLock.h"

namespace wd
{
	MutexLock::MutexLock()
	: _isLocking(false)
	{
		pthread_mutex_init(&_mutex,NULL);
	}

	MutexLock::~MutexLock()
	{
		pthread_mutex_destroy(&_mutex);
	}

	void MutexLock::lock()
	{
		_isLocking = true;
		pthread_mutex_lock(&_mutex);
	}
	void MutexLock::unlock()
	{
		pthread_mutex_unlock(&_mutex);
		_isLocking = false;
	}

	pthread_mutex_t * MutexLock::getMutexPtr()
	{
		return &_mutex;
	}
}

#ifndef _CONSUMER_H
#define _CONSUMER_H

#include "Thread.h"

namespace wd
{
	class Buffer;
	class Consumer:public Thread
	{
		public:
			Consumer(Buffer & buf);
			virtual void run();
		private:
			Buffer & _buf;
	};
}

#endif

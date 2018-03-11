#ifndef _PRODUCER_H
#define _PRODECER_H

#include "Thread.h"

namespace wd
{

	class Buffer;

	class Producer:public Thread
	{
		public:
			Producer(Buffer &);
			virtual void run();
		private:
			Buffer & _buf;
	};
}

#endif

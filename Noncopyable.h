#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

namespace wd
{

	class Noncopyable
	{
		protected:
			Noncopyable(){}
			~Noncopyable(){}

		private:
			Noncopyable(const Noncopyable &);
			Noncopyable & operator=(const Noncopyable &);

	};
}

#endif

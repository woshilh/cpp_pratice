#include "Threadpool.h"
#include "MyTask.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using std::cout;
using std::endl;



int main(void)
{
	shared_ptr<wd::Task> sp(new wd::MyTask);
	
	wd::Threadpool threadpool(4,10);
	threadpool.start();
	int cnt = 5;
	while(cnt--)
	{
		threadpool.addTask(sp.get());
		sleep(1);
	}
	threadpool.stop();
	return 0;
}

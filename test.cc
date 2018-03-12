#include "Buffer.h"
#include "Producer.h"
#include "Consumer.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;

int main(void)
{
	wd::Buffer buffer(10);
	wd::Producer producer(buffer);
	wd::Consumer consumer(buffer);

	producer.start();
	consumer.start();

	producer.join();
	consumer.join();

	return 0;
}

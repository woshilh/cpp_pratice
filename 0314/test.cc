/*
#include "ReadConf.h"
#include <iostream>
#include <string>

int main(int args,char ** argv)
{
	if(args != 2)
	{
		std::cout << "error args" << std::endl;
	}
	std::string path_(argv[1]);
	MyConf conf(path_);
	bool flag = conf.init();
	if(false != flag)
		conf.show();
	return 0;
}

*/

#include "CountBytes.h"
#include <iostream>
#include <string.h>

using std::cin;
using std::endl;
using std::cout;
using ::countBytes;

int main()
{
	std::string line;
	while(getline(cin,line))
	{
		const char * cs = line.c_str();
		int len = line.length();
		for(int i=0;i != len;)
		{
			char c = cs[i];
			int j = countBytes(c);
			char *desc;
			strncpy(desc,cs+i,j);
			desc[j] = '/0';
			i += j;
			cout << str(desc) << ",";
		}
		cout << endl;
	}
	return 0;
}

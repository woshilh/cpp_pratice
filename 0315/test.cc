#include "String.h"

int main()
{
	String s1("hello");
	String s2(s1);
	String s3 = "world";
	cout << s1 << ":::" << s2 << ":::" << s3 << endl;
}

#include <stdio.h>

//void exit(int);

void f(int n)
{
	printf("%d\n", n);
	int i = n/(1000-n);
	f(n+1);
}
int main(int i)
{
//	printf("%d\n", i);
//	(main + ((int)exit - (int)main) * (i/1000))(i+1);
	f(1);
}

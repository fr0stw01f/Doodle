#include <iostream>
#include <cstdlib>

//void exit(int i);

typedef int(*PF)(int);

int main(int i)
{
	std::cout << i << std::endl;
	PF p;
	p =	reinterpret_cast<int(*)(int)>((long)main + ((long)exit - (long)main) * (i/200));
	p(i+1);
}

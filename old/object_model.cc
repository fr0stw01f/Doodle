#include <iostream>

class A {
public:
	void tell()
	{
		std::cout << "Hello" << i << std::endl;
	}
private:
	int i;
};

int main()
{
	A* pa = nullptr;
	pa->tell();
}

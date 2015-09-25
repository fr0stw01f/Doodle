#include <iostream>

template<int N>
struct NumberGenerator
{
	static void out(std::ostream& os)
	{
		NumberGenerator<N-1>::out(os);
		os << N << std::endl;
	}
};

template<>
struct NumberGenerator<1>
{
	static void out(std::ostream& os)
	{
		os << 1 << std::endl;
	}
};

int main()
{
	NumberGenerator<200>::out(std::cout);
}

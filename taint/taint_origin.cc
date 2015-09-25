#include <iostream>
#include <cstring>
#include <algorithm>
#include <random>
#include <functional>
#include <iterator>

using namespace std;

class DoubleGen {
public:
	double operator()()
	{
		return dis(dre);
	}
private:
	static random_device rd;
	static default_random_engine dre;
	static uniform_real_distribution<> dis;
};
random_device DoubleGen::rd;
default_random_engine DoubleGen::dre(rd());
uniform_real_distribution<> DoubleGen::dis(1, 1000);

DoubleGen dg;

template<typename T>
T abs(T d)
{
	return d < 0 ? -1 * d : d;
}

int len_random(char *s)
{
	return abs(strlen(s)- static_cast<int>(dg()));
}

int g(int i, double arr[])
{
	int ret = static_cast<int>(dg() + arr[i]);
	return ret;
}

int f(int i, double arr[])
{
	if (i > 0)
		return g(i, arr);
	return -1;
}

const int LEN = 1024;

int main(int argc, char* argv[])
{
	double arr[LEN];
	std::generate(arr, arr + LEN, dg);	// case 1: arr is tainted
	// std::copy(arr, arr + LEN, ostream_iterator<double>(cout, "\n"));

	if (argc < 2)
		return -1;

	auto d = arr[len_random(argv[1])];	// case 2: argv[1] is tainted (argument), d is tainted

	int num;
	// std::cin.operator>>(num);
	std::cin >> num;					// case 3: num is tainted (reference parameter)

	std::cout << arr[num];				// case 4: 

	std::cout << arr[abs(num)];			// case 5: contex-sensitivity

	if (num >= 0)
		std::cout << arr[num];			// case 6:

	if (num >= 0 && num < LEN)		
		std::cout << arr[num];			// case 7: what about arr[num]?

	std::cout << g(-10, arr);			// case 8: 

	std::cout << f(-10, arr);			// case 9: path-sensitivity

	auto d1{ 0.0 };
	auto& d2 = d1;
	*(&d1) = dg();						// case 10: d1 and d2 are tainted (alias)
	d2 = 23;							// case 11: d1 and d2 are not tainted
}
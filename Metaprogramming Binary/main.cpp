#include <iostream>

using std::cout;
using std::endl;

template <unsigned long N>
struct binary
{
	static unsigned const value = binary<N / 10>::value << 1 | N % 10;
};

template<>
struct binary<0>
{
	static unsigned const value = 0;
};

int main()
{
	unsigned const five = binary<101>::value;
	cout << five << endl;

	return 0;
}
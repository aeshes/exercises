#include <iostream>

template <int... Ints>
struct IntList;

template <int H, int... T>
struct IntList<H, T...>
{
	static const int Head = H;
	using Tail = IntList<T...>;
};

template<>
struct IntList<> {};

template <typename IL>
struct ILength
{
	static const int value = 1 + ILength<typename IL::Tail>::value;
};

template <>
struct ILength<IntList<>>
{
	static const int value = 0;
};


int main()
{
	using IL = IntList<1, 2, 3>;

	std::cout << ILength<IL>::value << std::endl;

	return 0;
}
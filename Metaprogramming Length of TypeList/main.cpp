#include <iostream>

template <typename... Types>
struct TypeList;

template <typename H, typename... T>
struct TypeList<H, T...>
{
	using Head = H;
	using Tail = TypeList<T...>;
};

template <>
struct TypeList<> {};

template <typename TL>
struct Length
{
	static const int value = 1 + Length<typename TL::Tail>::value;
};

template<>
struct Length<TypeList<>>
{
	static const int value = 0;
};


int main()
{
	using TL = TypeList<int, int, int>;
	
	std::cout << Length<TL>::value << std::endl;

	return 0;
}
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

template <typename H, typename TL>
struct Cons;

template <typename H, typename... Types>
struct Cons<H, TypeList<Types...>>
{
	using type = TypeList<H, Types...>;
};


int main()
{
	using TL = TypeList<int, int, int>;

	std::cout << Length<TL>::value << std::endl;
	using cons = Cons<double, TL>::type;
	std::cout << Length<cons>::value << std::endl;

	return 0;
}
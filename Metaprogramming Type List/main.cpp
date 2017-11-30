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

int main()
{
	using TL = TypeList<int, int, int>;

	return 0;
}
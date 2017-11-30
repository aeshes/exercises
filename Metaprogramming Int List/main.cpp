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

int main()
{
	using IL = IntList<1, 2, 3>;

	return 0;
}
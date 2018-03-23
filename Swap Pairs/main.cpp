#include <iostream>
#include <cstddef>

using std::cout;
using std::endl;

template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T, size_t N>
void swap_pairs(T(&arr)[N])
{
	bool is_odd = N % 2;
	size_t limit = is_odd ? N - 2 : N - 1;
	for (size_t i = 0; i < limit; i += 2)
	{
		swap(arr[i], arr[i + 1]);
	}
}

int main()
{
	int arr[7] = { 0, 1, 2, 3, 4, 5, 6 };
	swap_pairs(arr);
	for (size_t i = 0; i < 7; ++i)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
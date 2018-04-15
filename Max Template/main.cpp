#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <functional>

using std::cin;
using std::cout;
using std::endl;

template<typename T>
inline T const& max(T const& a, T const& b)
{
	return a < b ? b : a;
}

template<typename T>
inline T* const& max(T* const& a, T* const& b)
{
	return *a < *b ? b : a;
}

int main()
{
	int a = 2, b = 3;
	cout << max(a, b) << endl;
	cout << max(&a, &b) << endl;

	return 0;
}
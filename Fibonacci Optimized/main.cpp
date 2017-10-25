#include <iostream>
#include <unordered_map>
#include <vector>


long long fib(int n)
{
	if (n <= 1) return n;

	static std::unordered_map<int, long long> cache;
	auto &result = cache[n];

	if (result == 0)
	{
		result = fib(n - 2) + fib(n - 1);
	}
	return result;
}

long long fib2(int n)
{
	if (n == 0 || n == 1) return n;

	static std::unordered_map<int, long long> cache;
	if (!cache.count(n))
	{
		cache[n] = fib2(n - 1) + fib2(n - 2);
	}
	return cache[n];
}

long long fib_iter(unsigned n)
{
	if (n == 0 || n == 1) return n;

	static std::vector<long long> cache(n + 1);
	cache[0] = 0;
	cache[1] = 1;

	for (std::size_t i = 2; i <= n; ++i)
	{
		cache[i] = cache[i - 1] + cache[i - 2];
	}
	return cache[n];
}

long long fib_fast(int n)
{
	long long previous = 0;
	long long current  = 1;

	for (int i = 2; i <= n; ++i)
	{
		long long new_current = current + previous;
		previous = current;
		current  = new_current;
	}
	return current;
}

int main()
{
	std::cout << fib(47) << std::endl;
	std::cout << fib2(47) << std::endl;
	std::cout << fib_iter(47) << std::endl;
	std::cout << fib_fast(47) << std::endl;
}
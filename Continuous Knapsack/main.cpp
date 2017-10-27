#include <iostream>
#include <vector>
#include <algorithm>


struct item
{
	int value;
	int weight;
};

double get_item_profit(item const& it)
{
	return static_cast<double>(it.weight) / it.value;
}

double knapsack(std::vector<item> items, int capacity)
{
	std::sort(items.begin(), items.end(), [](item const& left, item const& right)
	{
		return get_item_profit(left) < get_item_profit(right);
	});

	double value = 0.0;
	for (const auto &curr : items)
	{
		if (capacity > curr.weight)
		{
			capacity -= curr.weight;
			value += curr.value;
		}
		else
		{
			value += curr.value * (static_cast<double>(capacity) / curr.weight);
			break;
		}
	}
	return value;
}



int main()
{
	std::vector<item> items =
	{
		{60, 20},
		{100, 50},
		{120, 30}
	};

	std::cout << knapsack(items, 50);
}
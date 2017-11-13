#include <tuple>

// t = (1, 2, 3, 4, 5)
// to_pair<2, 3>(t) = (2, 3)
template <size_t i, size_t j, typename T>
auto to_pair(T && t) -> decltype(std::make_pair(std::get<i>(t), std::get<j>(t)))
{
	return std::make_pair(std::get<i>(t), std::get<j>(t));
}
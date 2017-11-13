#include <iostream>
#include <typeinfo>

void print_values(std::ostream & os)
{

}

template <typename T>
void print_values(std::ostream & os, T value)
{
	os << typeid(value).name() << ": ";
	os << value << std::endl;
}

template <typename T, typename... Args>
void print_values(std::ostream & os, T value, Args... args)
{
	os << typeid(value).name() << ": ";
	os << value << std::endl;
	print_values(os, args...);
}

int main()
{
	print_values(std::cout, 0, 3.5, "Hello");
}
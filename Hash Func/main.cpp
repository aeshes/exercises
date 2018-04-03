#include <iostream>
#include <string>
#include <functional>

using std::cin;
using std::cout;
using std::endl;


class person
{
public:
	person(std::string const& s)
		: data(s) {}
	friend bool operator==(person const& lhs, person const& rhs);
	std::string name() const { return data; }
private:
	std::string data;
};

bool operator==(person const& lhs, person const& rhs)
{
	return lhs.data == rhs.data;
}

namespace std
{
	template<> struct std::hash<person>
	{
		size_t operator()(person const& p)
		{
			std::hash<std::string> h;
			return h(p.name());
		}
	};
}

int main()
{
	std::hash<std::string> h;
	cout << h("abc") << endl;

	person p("abc");
	std::hash<person> g;
	cout << g(p) << endl;

	return 0;
}
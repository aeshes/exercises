#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>


struct IClonable
{
	virtual IClonable * clone() const = 0;
};

class Base
{
public:
	virtual void send() = 0;
};

void Base::send()
{
	std::cout << "Base::send" << std::endl;
}

class Derived : public Base, IClonable
{
public:
	void send() override;
	Derived * clone() const override
	{
		return new Derived(*this);
	}
};

void Derived::send()
{
	Base::send();
	std::cout << "Derived::send" << std::endl;
}

int main()
{
	Derived d;
	Derived *c = d.clone();
	Base &bref = *c;
	bref.send();
}
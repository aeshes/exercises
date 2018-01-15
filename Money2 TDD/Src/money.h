#ifndef MONEY_H
#define MONEY_H

#include <memory>
#include <string>
#include <cassert>

using std::shared_ptr;
using std::make_shared;
using std::string;


class Dollar;

class Money
{
public:
	Money(int amount_, string currency_);
	static Money dollar(int amount);
	static Money franc(int amount);
	Money times(int value) const;
	bool equals(const Money& money) const;
	string currency() const;
protected:
	int amount;
	string currency_;
};

#endif

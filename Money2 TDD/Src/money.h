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
	static shared_ptr<Money> dollar(int amount);
	static shared_ptr<Money> franc(int amount);
	virtual shared_ptr<Money> times(int value) const
	{
		return make_shared<Money>(amount * value, currency_);
	}
	virtual bool equals(shared_ptr<Money> money) const
	{
		return amount == money->amount
			&& currency() == money->currency();
	}
	string currency() const
	{
		return currency_;
	}
protected:
	int amount;
	string currency_;
};

#endif

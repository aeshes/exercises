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
	shared_ptr<Money> times(int value) const;
	bool equals(shared_ptr<Money> money) const;
	string currency() const;
protected:
	int amount;
	string currency_;
};

#endif

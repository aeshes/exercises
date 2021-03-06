#ifndef MONEY_H
#define MONEY_H

#include <string>
#include <cassert>
#include <memory>
#include <map>

using std::string;
using std::unique_ptr;
using std::make_unique;
using std::pair;
using std::make_pair;

class Money;
class Bank;

class Expression
{
public:
	virtual unique_ptr<Money> reduce(const Bank& bank, const string& to) const
	{
		return nullptr;
	}
};

class Dollar;

class Money : public Expression
{
public:
	Money(int amount_, string currency_);

	static Money dollar(int amount);
	static Money franc(int amount);

	string currency() const;
	Money times(int value) const;
	unique_ptr<Money> reduce(const Bank& bank, const string& to) const;

	bool operator==(const Money& money) const;
	unique_ptr<Expression> operator+(const Money& right) const;
public:
	int amount;
	string currency_;
};

class Bank
{
public:
	unique_ptr<Money> reduce(const Expression& source, const string& to) const;
	void addRate(const string& from, const string& to, int rate);
	int rate(const string& from, const string& to) const;

private:
	std::map<pair<string, string>, int> rates;
};

struct Sum : Expression
{
	Sum(Money augend, Money addend)
		: augend(augend), addend(addend) {}
	unique_ptr<Money> reduce(const Bank& bank, const string& to) const;

	Money augend;
	Money addend;
};

#endif

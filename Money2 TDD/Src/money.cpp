#include "money.h"

#include <gmock\gmock.h>

Money::Money(int amount_, string currency_)
{
	this->amount = amount_;
	this->currency_ = currency_;
}

Money Money::dollar(int amount)
{
	return Money(amount, "USD");
}

Money Money::franc(int amount)
{
	return Money(amount, "CHF");
}

Money Money::times(int value) const
{
	return Money(amount * value, currency_);
}

bool Money::operator==(const Money& money) const
{
	return amount == money.amount
		&& currency() == money.currency();
}

unique_ptr<Expression> Money::operator+(const Money& right) const
{
	return make_unique<Sum>(*this, right);
}

string Money::currency() const
{
	return currency_;
}

unique_ptr<Money> Money::reduce(const Bank& bank, const string& to) const
{
	int rate = bank.rate(currency_, to);
	return make_unique<Money>(amount/rate, to);
}

unique_ptr<Money> Bank::reduce(const Expression& source, const string& to) const
{
	return source.reduce(*this, to);
}

unique_ptr<Money> Sum::reduce(const Bank& bank, const string& to) const
{
	int amount = augend.reduce(bank, to)->amount
		+ addend.reduce(bank, to)->amount;
	return make_unique<Money>(amount, to);
}

void Bank::addRate(const string& from, const string& to, int rate)
{
	rates.emplace(make_pair(from, to), rate);
}

int Bank::rate(const string& from, const string& to) const
{
	if (from == to) return 1;
	return rates.at(make_pair(from, to));
}


using ::testing::Eq;

TEST(Money, TestDollarMultiplication)
{
	Money five = Money::dollar(5);
	ASSERT_TRUE(five.times(2) == Money::dollar(10));
	ASSERT_TRUE(five.times(3) == Money::dollar(15));
}

TEST(Money, TestFrancMultiplication)
{
	Money five = Money::franc(5);
	ASSERT_TRUE(five.times(2) == Money::franc(10));
	ASSERT_TRUE(five.times(3) == Money::franc(15));
}

TEST(Money, TestCurrency)
{
	ASSERT_THAT(Money::dollar(1).currency(), Eq("USD"));
	ASSERT_THAT(Money::franc(1).currency(), Eq("CHF"));
}

TEST(Money, TestReduceMoney)
{
	Bank bank;
	unique_ptr<Money> result = bank.reduce(Money::dollar(1), "USD");
	ASSERT_THAT(Money::dollar(1), Eq(*result));
}

TEST(Money, DISABLED_TestSimpleAddition)
{
	Money five = Money::dollar(5);
	unique_ptr<Expression> sum = five + five;
	Bank bank;
	unique_ptr<Money> reduced = bank.reduce(*sum, "USD");
	ASSERT_THAT(*reduced, Eq(Money::dollar(10)));
}

TEST(Money, TestReduceMoneyDifferentCurrency)
{
	Bank bank;
	bank.addRate("CHF", "USD", 2);
	unique_ptr<Money> result = bank.reduce(Money::franc(2), "USD");
	ASSERT_THAT(Money::dollar(1), Eq(*result));
}

TEST(Money, TestIdentityRate)
{
	ASSERT_THAT(Bank().rate("USD", "USD"), Eq(1));
}

TEST(Money, TestMixedAddition)
{
	Money fiveBucks = Money::dollar(5);
	Money tenFrancs = Money::franc(10);
	Bank bank;
	bank.addRate("CHF", "USD", 2);
	unique_ptr<Money> result = bank.reduce(*(fiveBucks + tenFrancs), "USD");
	ASSERT_THAT(Money::dollar(10), Eq(*result));
}

/*TEST(Money, TestPlusReturnsSum)
{
	Money five = Money::dollar(5);
	Expression result = five + five;
	Sum sum = static_cast<Sum>(result);
	ASSERT_THAT(five, sum.augend);
	ASSERT_THAT(five, sum.addend);
}*/
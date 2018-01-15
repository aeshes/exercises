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

bool Money::equals(const Money& money) const
{
	return amount == money.amount
		&& currency() == money.currency();
}

string Money::currency() const
{
	return currency_;
}


using ::testing::Eq;

TEST(Money, TestDollarMultiplication)
{
	Money five = Money::dollar(5);
	ASSERT_TRUE(five.times(2).equals(Money::dollar(10)));
	ASSERT_TRUE(five.times(3).equals(Money::dollar(15)));
}

TEST(Money, TestFrancMultiplication)
{
	Money five = Money::franc(5);
	ASSERT_TRUE(five.times(2).equals(Money::franc(10)));
	ASSERT_TRUE(five.times(3).equals(Money::franc(15)));
}

TEST(Money, TestCurrency)
{
	ASSERT_THAT(Money::dollar(1).currency(), Eq("USD"));
	ASSERT_THAT(Money::franc(1).currency(), Eq("CHF"));
}

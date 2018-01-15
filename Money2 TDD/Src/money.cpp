#include "money.h"

#include <gmock\gmock.h>

Money::Money(int amount_, string currency_)
{
	this->amount = amount_;
	this->currency_ = currency_;
}

shared_ptr<Money> Money::dollar(int amount)
{
	return make_shared<Money>(amount, "USD");
}

shared_ptr<Money> Money::franc(int amount)
{
	return make_shared<Money>(amount, "CHF");
}


using ::testing::Eq;

TEST(Money, TestDollarMultiplication)
{
	shared_ptr<Money> five = Money::dollar(5);
	ASSERT_TRUE(five->times(2)->equals(Money::dollar(10)));
	ASSERT_TRUE(five->times(3)->equals(Money::dollar(15)));
}

TEST(Money, TestFrancMultiplication)
{
	shared_ptr<Money> five = Money::franc(5);
	ASSERT_TRUE(five->times(2)->equals(Money::franc(10)));
	ASSERT_TRUE(five->times(3)->equals(Money::franc(15)));
}

TEST(Money, TestCurrency)
{
	ASSERT_THAT(Money::dollar(1)->currency(), Eq("USD"));
	ASSERT_THAT(Money::franc(1)->currency(), Eq("CHF"));
}

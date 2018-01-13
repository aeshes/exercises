#include "money.h"

#include <gmock\gmock.h>

Dollar::Dollar(int amount)
{
	this->amount = amount;
}

Dollar Dollar::times(int value) const
{
	return Dollar(amount * value);
}

bool Dollar::operator==(const Dollar& dollar) const
{
	return amount == dollar.amount;
}

Franc::Franc(int amount)
{
	this->amount = amount;
}

Franc Franc::times(int value) const
{
	return Franc(amount * value);
}

bool Franc::operator==(const Franc& franc) const
{
	return amount == franc.amount;
}


using ::testing::Eq;

TEST(Money, TestDollarMultiplication)
{
	const Dollar five(5);
	ASSERT_TRUE(five.times(2) == Dollar(10));
	ASSERT_TRUE(five.times(3) == Dollar(15));
}

TEST(Money, TestFrancMultiplication)
{
	const Franc five(5);
	ASSERT_TRUE(five.times(2) == Franc(10));
	ASSERT_TRUE(five.times(3) == Franc(15));
}
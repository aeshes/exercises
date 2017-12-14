#include <iostream>
#include <string>

#include "gmock\gmock.h"
#include "retweet.h"

#pragma comment(lib, "gmock.lib")


using namespace ::testing;

class ARetweetCollection : public Test
{
public:
	RetweetCollection collection;
};

TEST_F(ARetweetCollection, IsEmptyWhenCreated)
{
	ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeZeroWhenCreated)
{
	ASSERT_THAT(collection.size(), Eq(0u));
}

TEST_F(ARetweetCollection, IsNoLongerEmptyAfterTweetAdded)
{
	collection.add(Tweet());
	ASSERT_FALSE(collection.isEmpty());
}

TEST_F(ARetweetCollection, HasSizeOfOneAfterTweetAdded)
{
	collection.add(Tweet());
	ASSERT_THAT(collection.size(), Eq(1u));
}

TEST_F(ARetweetCollection, IsEmptyWhenItsSizeIsZero)
{
	ASSERT_THAT(collection.size(), Eq(0u));
	ASSERT_TRUE(collection.isEmpty());
}

TEST_F(ARetweetCollection, IsNotEmptyWhenItsSizeIsNonZero)
{
	collection.add(Tweet());
	ASSERT_THAT(collection.size(), Gt(0u));
	ASSERT_FALSE(collection.isEmpty());
}

int main(int argc, char **argv)
{
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}
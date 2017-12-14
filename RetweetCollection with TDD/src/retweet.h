#pragma once

class Tweet {};

class RetweetCollection
{
public:
	RetweetCollection()
		: _size(0)
	{

	}

	unsigned size() const
	{
		return _size;
	}

	bool isEmpty() const
	{
		return 0 == size();
	}

	void add(Tweet const& tweet)
	{
		_size = 1;
	}

	void remove(Tweet const& tweet)
	{
		_size = 0;
	}

private:
	unsigned _size;
};
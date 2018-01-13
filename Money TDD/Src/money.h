#ifndef MONEY_H
#define MONEY_H

class Money
{
protected:
	int amount;
};

class Dollar : public Money
{
public:
	Dollar(int amount);
	Dollar times(int value) const;
	bool operator==(const Dollar& dollar) const;
};

class Franc : public Money
{
public:
	Franc(int amount);
	Franc times(int value) const;
	bool operator==(const Franc& franc) const;
};

#endif

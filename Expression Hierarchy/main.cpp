#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>

#include "expression.h"


int main()
{
	BinaryOperation *numerator   = new BinaryOperation(new Number(5), '-', new Number(3));
	BinaryOperation *denominator = new BinaryOperation(new Number(1), '-', new Number(1));
	BinaryOperation *division    = new BinaryOperation(numerator, '/', denominator);
	PrintVisitor visitor;

	division->visit(&visitor);
}
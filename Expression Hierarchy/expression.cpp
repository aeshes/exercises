#include "expression.h"

#include <iostream>


Number::Number(double value) : value(value)
{

}

double Number::evaluate() const
{
	return value;
}

double Number::getValue() const
{
	return value;
}

void Number::visit(Visitor * visitor) const
{
	visitor->visitNumber(this);
}

BinaryOperation::BinaryOperation(Expression const * left, char op, Expression const * right)
	: left(left), op(op), right(right)
{

}

BinaryOperation::~BinaryOperation()
{
	delete left;
	delete right;
}

double BinaryOperation::evaluate() const
{
	switch (op)
	{
	case '+': return left->evaluate() + right->evaluate();
	case '-': return left->evaluate() - right->evaluate();
	case '*': return left->evaluate() * right->evaluate();
	case '/': return left->evaluate() / right->evaluate();
	default: return 0;
	}
}

Expression const * BinaryOperation::getLeft() const
{
	return left;
}

Expression const * BinaryOperation::getRight() const
{
	return right;
}

char BinaryOperation::getOp() const
{
	return op;
}

void BinaryOperation::visit(Visitor * visitor) const
{
	visitor->visitBinaryOperation(this);
}

void PrintVisitor::visitNumber(Number const * number)
{
	std::cout << number->getValue();
}

void PrintVisitor::visitBinaryOperation(BinaryOperation const * op)
{
	if (op->getOp() == '*' || op->getOp() == '/')
		std::cout << '(';

	std::cout << '(';
	op->getLeft()->visit(this);
	std::cout << ')';

	std::cout << op->getOp();

	std::cout << '(';
	op->getRight()->visit(this);
	std::cout << ')';

	if (op->getOp() == '*' || op->getOp() == '/')
		std::cout << ')';
}


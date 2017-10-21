#pragma once

struct Number;
struct BinaryOperation;

struct Visitor
{
	virtual void visitNumber(Number const * number) = 0;
	virtual void visitBinaryOperation(BinaryOperation const * op) = 0;
	virtual ~Visitor() = default;
};

struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor * visitor) const = 0;
	virtual ~Expression() = default;
};

struct Number : Expression
{
	Number(double value);
	double evaluate() const;
	double getValue() const;
	void visit(Visitor * visitor) const;

private:
	double value;
};

struct BinaryOperation : Expression
{
	BinaryOperation(Expression const * left, char op, Expression const * right);
	~BinaryOperation();

	double evaluate() const;

	Expression const * getLeft() const;
	Expression const * getRight() const;
	char getOp() const;

	void visit(Visitor * visitor) const;

private:
	char op;
	Expression const * left;
	Expression const * right;
};

struct PrintVisitor : Visitor
{
	void visitNumber(Number const * number);
	void visitBinaryOperation(BinaryOperation const * op);
};


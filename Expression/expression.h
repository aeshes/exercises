#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <stdexcept>

class Expression
{
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() = default;
};

class Number : public Expression
{
public:
    Number(double n)
        : value(n) {}

    double evaluate() const { return value; }

private:
    double value;
};

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression* const left, char op, Expression* const right)
        : left(left), right(right), op(op) {}
    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

double evaluate() const override
{
    switch (op)
    {
        case '+': return left->evaluate() + right->evaluate();
        case '-': return left->evaluate() - right->evaluate();
        case '*': return left->evaluate() * right->evaluate();
        case '/':
            if (!right->evaluate()) throw std::runtime_error("Division by zero");
            return left->evaluate() / right->evaluate();
    }
    return 0;
}

private:
    Expression* const left;
    Expression* const right;
    char op;
};

#endif // EXPRESSION_H

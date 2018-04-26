#include "expression.h"
#include "test_expression.h"

#include <QTest>

TestExpression::TestExpression(QObject* parent)
    : QObject(parent)
{

}

void TestExpression::testNumberEvaluate()
{
    QCOMPARE(Number(-1).evaluate(), -1);
    QCOMPARE(Number(0).evaluate(), 0);
    QCOMPARE(Number(1).evaluate(), 1);
}

void TestExpression::testAddition()
{
    BinaryOperation op(new Number(3), '+', new Number(5));
    QCOMPARE(op.evaluate(), 8);
}

void TestExpression::testSubtraction()
{
    BinaryOperation op(new Number(3), '-', new Number(5));
    QCOMPARE(op.evaluate(), -2);
}

void TestExpression::testMultiplication()
{
    BinaryOperation op(new Number(3), '*', new Number(5));
    QCOMPARE(op.evaluate(), 15);
}

void TestExpression::testDivision()
{
    BinaryOperation op(new Number(6), '/', new Number(2));
    QCOMPARE(op.evaluate(), 3);
}

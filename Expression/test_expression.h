#ifndef TEST_EXPRESSION_H
#define TEST_EXPRESSION_H

#include <QObject>

class TestExpression : public QObject
{
    Q_OBJECT
public:
    explicit TestExpression(QObject* parent = 0);

private slots:
    void testNumberEvaluate();
    void testAddition();
    void testSubtraction();
    void testMultiplication();
    void testDivision();
};

#endif // TEST_EXPRESSION_H

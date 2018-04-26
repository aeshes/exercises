#include <QCoreApplication>
#include <QTest>

#include "test_expression.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new TestExpression, argc, argv);

    return a.exec();
}

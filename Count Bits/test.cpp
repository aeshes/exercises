#include <QTest>
#include "test.h"
#include "hamming.h"

Test::Test(QObject *parent)
    : QObject(parent)
{

}

void Test::count()
{
    QCOMPARE(::count(0), 0);
    QCOMPARE(::count(1), 1);
    QCOMPARE(::count(127), 7);
    QCOMPARE(::count(256), 1);
}

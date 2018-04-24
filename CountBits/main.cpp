#include <QCoreApplication>
#include <QTest>

#include <cstddef>

#include "test.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new Test, argc, argv);

    return a.exec();
}

#include <QCoreApplication>
#include "qReadisExample.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qReadisTest t;
    t.start();
    return a.exec();
}

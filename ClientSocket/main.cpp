#include <QCoreApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ClientSocket cTest;
    cTest.Connect();
    
    return a.exec();
}

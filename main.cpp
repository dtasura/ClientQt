#include "myclientql.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClientQl w;
    w.show();
    return a.exec();
}

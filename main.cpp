#include <QtGui/QApplication>
#include "maindice.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainDice w;
    w.show();

    return a.exec();
}

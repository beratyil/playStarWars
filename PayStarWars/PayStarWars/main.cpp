#include "PayStarWars.h"
#include <QtWidgets/QApplication>
#include <QPlainTextEdit>
#include <QtMessageHandler>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PayStarWars w;
    w.show();
    return a.exec();
}

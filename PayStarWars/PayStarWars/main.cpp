#include "PlayStarWars.h"
#include <QtWidgets/QApplication>
#include <QPlainTextEdit>
#include <QtMessageHandler>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlayStarWars w;
    w.show();
    return a.exec();
}

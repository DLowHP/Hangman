#include "Hangman.h"

#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QFontDatabase::addApplicationFont(":/fonts/PatrickHand-Regular.ttf");
    QApplication a(argc, argv);
    Hangman w;
    w.show();
    return a.exec();
}

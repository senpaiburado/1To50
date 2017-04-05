#include "startmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    StartMenu w;

    w.init();

    w.show();

    return app.exec();
}

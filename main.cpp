#include "window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_EnableHighDpiScaling);
    Window w;
    w.setFixedSize(480, 720);
    w.show();

    return app.exec();
}

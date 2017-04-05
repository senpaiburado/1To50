#ifndef STARTMENU_H
#define STARTMENU_H

#include <QMainWindow>
class ScoreMenu;
class Window;
#include "window.h"

namespace Ui {
class StartMenu;
}

class StartMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartMenu(QWidget *parent = 0);
    ~StartMenu();

    void init();

private:
    Ui::StartMenu *ui;
    Window *wnd;
};

#endif // STARTMENU_H

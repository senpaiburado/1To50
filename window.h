#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QtWidgets>
#include <QTimer>
#include "game.h"
class StartMenu;
#include "startmenu.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

    void setStepLabel(int step);
    void start();
    void init();

private:
    Ui::Window *ui;
    Game *game;
    QVector<QPushButton*> buttons;
    QTimer *timer;
    StartMenu *menu;
    int time;

    int max_score;


    void saveScore(int score);
    void getScore();
    void setValuesForButtons();
    void pushButtonsInArray();
    void connectButtons(QPushButton *but);
    void setConnectsButtons();
};

#endif // WINDOW_H

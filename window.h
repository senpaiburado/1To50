#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QtWidgets>
#include <QTimer>
#include "game.h"

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

private:
    Ui::Window *ui;
    Game *game;
    QVector<QPushButton*> buttons;
    QTimer *timer;
    int time;


    void setValuesForButtons();
    void pushButtonsInArray();
    void connectButtons(QPushButton *but);
    void setConnectsButtons();
};

#endif // WINDOW_H

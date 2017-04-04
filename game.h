#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QVector>
#include <QMap>
#include <algorithm>
#include <QDebug>
#include <random>
#include <time.h>

class Game
{
public:
    Game();

    void set25Numbers();
    int getNextCell();
    QVector<int> get25Numbers();
    int getStep();
    void refresh();

private:
    QVector<int> numbers;
    QVector<int> temp;
    int step;

};

#endif // GAME_H

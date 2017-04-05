#include "game.h"

Game::Game()
{

   for (size_t i(0); i < 50; i++)
       numbers.push_back(i+1);

   step = 1;

   set25Numbers();

}

void Game::set25Numbers()
{
    std::srand(time(NULL));
    QVector<int> temporary;

    for (size_t i(0); i < 7; i++)
    {
        temp.push_back(numbers[i]);
    }

    for (size_t i(7); i < numbers.size(); i++)
    {
        temporary.push_back(numbers[i]);
    }
    numbers = temporary;
    temporary.erase(temporary.begin(), temporary.end());

    std::random_shuffle(numbers.begin(), numbers.end());

    for (size_t i(0); i < 18; i++)
        temp.push_back(numbers[i]);
    for (size_t i(18); i < numbers.size(); i++)
    {
        temporary.push_back(numbers[i]);
    }
    numbers = temporary;
    temporary.erase(temporary.begin(), temporary.end());

    std::sort(numbers.begin(), numbers.end());
    std::random_shuffle(temp.begin(), temp.end());
}

QVector<int> Game::get25Numbers()
{
    return temp;
}

int Game::getStep()
{
    return step;
}

void Game::refresh()
{
    temp.erase(temp.begin(), temp.end());
    numbers.erase(numbers.begin(), numbers.end());

    for (size_t i(0); i < 50; i++)
        numbers.push_back(i+1);

    step = 1;
    set25Numbers();
}

int Game::getNextCell()
{
    std::srand(time(NULL));
    if (step < 26)
    {
        if (temp.contains(step+6))
        {
            std::random_shuffle(numbers.begin(), numbers.end());
            int num = numbers[0];
            numbers.erase(numbers.begin());
            temp.push_back(num);
            step++;
            return num;
        }
        else
        {

            int index = numbers.indexOf(step+6);
            int num = numbers[index];
            numbers.erase(numbers.begin()+index);
            temp.push_back(num);
            step++;
            return num;
        }
    }
    else
    {
        step++;
        return 0;
    }
}

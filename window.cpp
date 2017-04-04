#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    game = new Game();

    pushButtonsInArray();
    setValuesForButtons();
    setStepLabel(game->getStep());
    setConnectsButtons();
    timer = new QTimer(this);
    time = 0;

    connect(timer, &QTimer::timeout, this, [&]() {
        time++;
        ui->clock->display(time);
    });

    timer->start(1000);
}

Window::~Window()
{
    delete ui;
    delete game;
    for (size_t i(0); i < buttons.size(); i++)
        delete buttons[i];
    delete timer;
}

void Window::setStepLabel(int step)
{
    ui->nextLabel->setText(step >= 50 ? "50" : QString::number(step));
    ui->nextNextLabel->setText((step++) >= 50 ? "50" : QString::number(step++)+);
}

void Window::setValuesForButtons()
{
    for (size_t i(0); i < buttons.size(); i++)
    {
        buttons[i]->setText(QString::number(game->get25Numbers().at(i)));

    }
}

void Window::pushButtonsInArray()
{
    buttons.push_back(ui->b1);
    buttons.push_back(ui->b2);
    buttons.push_back(ui->b3);
    buttons.push_back(ui->b4);
    buttons.push_back(ui->b5);
    buttons.push_back(ui->b6);
    buttons.push_back(ui->b7);
    buttons.push_back(ui->b8);
    buttons.push_back(ui->b9);
    buttons.push_back(ui->b10);
    buttons.push_back(ui->b11);
    buttons.push_back(ui->b12);
    buttons.push_back(ui->b13);
    buttons.push_back(ui->b14);
    buttons.push_back(ui->b15);
    buttons.push_back(ui->b16);
    buttons.push_back(ui->b17);
    buttons.push_back(ui->b18);
    buttons.push_back(ui->b19);
    buttons.push_back(ui->b20);
    buttons.push_back(ui->b21);
    buttons.push_back(ui->b22);
    buttons.push_back(ui->b23);
    buttons.push_back(ui->b24);
    buttons.push_back(ui->b25);
}

void Window::connectButtons(QPushButton *but)
{
    //qDebug() << but << endl;
    if (but->text().toInt() == game->getStep())
    {
        //qDebug() << "TEST!" << endl;
        int cell = game->getNextCell();
        if (cell == 0)
        {
            but->setText("");
            but->setEnabled(false);
        }
        else
        {
            but->setText(QString::number(cell));
        }
        setStepLabel(game->getStep());
    }
}

void Window::setConnectsButtons()
{
    foreach(QPushButton *but, buttons)
        connect(but, &QPushButton::pressed, this, [=](){
           connectButtons(but);
        });


//    connect(ui->b1, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b1);
//    });
//    connect(ui->b2, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b2);
//    });
//    connect(ui->b3, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b3);
//    });
//    connect(ui->b4, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b4);
//    });
//    connect(ui->b5, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b5);
//    });
//    connect(ui->b5, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b5);
//    });
//    connect(ui->b6, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b6);
//    });
//    connect(ui->b7, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b7);
//    });
//    connect(ui->b8, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b8);
//    });
//    connect(ui->b9, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b9);
//    });
//    connect(ui->b10, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b10);
//    });
//    connect(ui->b11, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b11);
//    });
//    connect(ui->b12, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b12);
//    });
//    connect(ui->b13, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b13);
//    });
//    connect(ui->b14, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b14);
//    });
//    connect(ui->b15, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b15);
//    });
//    connect(ui->b16, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b16);
//    });
//    connect(ui->b17, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b17);
//    });
//    connect(ui->b18, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b18);
//    });
//    connect(ui->b19, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b19);
//    });
//    connect(ui->b20, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b20);
//    });
//    connect(ui->b21, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b21);
//    });
//    connect(ui->b22, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b22);
//    });
//    connect(ui->b23, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b23);
//    });
//    connect(ui->b24, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b25);
//    });
//    connect(ui->b25, &QPushButton::pressed, this, [&](){
//        connectButtons(ui->b25);
//    });
}

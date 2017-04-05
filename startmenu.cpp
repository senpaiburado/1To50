#include "startmenu.h"
#include "ui_startmenu.h"
#include <QApplication>

StartMenu::StartMenu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartMenu),
    wnd(NULL)
{
    ui->setupUi(this);
}

StartMenu::~StartMenu()
{
    delete ui;
    delete wnd;
}

void StartMenu::init()
{
    wnd = new Window;

    connect(ui->playButton, &QPushButton::pressed, this, [&](){
        this->wnd->init();
        this->wnd->show();
        this->hide();
        this->wnd->start();
    });

    connect(ui->exitButton, &QPushButton::pressed, this, [&](){
        QApplication::exit();
    });
}

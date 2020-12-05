#include "Hangman.h"
#include "ui_Hangman.h"

Hangman::Hangman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hangman)
{
    ui->setupUi(this);
}

Hangman::~Hangman()
{
    delete ui;
}


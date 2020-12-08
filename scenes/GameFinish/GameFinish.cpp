#include "GameFinish.h"
#include "ui_GameFinish.h"

GameFinish::GameFinish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameFinish)
{
    ui->setupUi(this);

    connect(ui->btnMenu, SIGNAL(clicked()), this, SLOT(btnMenuClicked()));
    connect(ui->btnContinue, SIGNAL(clicked()), this, SLOT(btnContinueClicked()));
}

GameFinish::~GameFinish()
{
    delete ui;
}

void GameFinish::setOutcome(bool gameWon)
{
    this->gameWon = gameWon;
    if (gameWon) {
        this->setWindowTitle("Solved!");
        ui->outcome->setText("Solved!");
        ui->btnContinue->setText("Continue");
    }
    else {
        ui->outcome->setText("Game over.");
        this->setWindowTitle("Game over.");
        ui->btnContinue->setText("Play again");
    }
}

void GameFinish::setScore(int score)
{
    ui->score->setText(QString::number(score));
}

void GameFinish::btnMenuClicked()
{
    emit returnToMenu();
    this->close();
}

void GameFinish::btnContinueClicked()
{
    emit playAgain();
    this->close();
}

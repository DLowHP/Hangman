#include "Scores.h"
#include "ui_Scores.h"

#include "scenes/Game/Game.h"

Scores::Scores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scores)
{
    ui->setupUi(this);

    connect(ui->btnMenu, SIGNAL(clicked()), this, SLOT(btnMenu()));
}

Scores::~Scores()
{
    delete ui;
}

void Scores::setGameRef(Game* ptr)
{
    g = ptr;
}

void Scores::saveScore()
{
    QVector<QString> score = g->getScore();

    ui->names->appendPlainText(score.at(0));
    ui->names->setStyleSheet("font: 18pt; color: #000000;");

    ui->balloons->appendPlainText(score.at(1));
    ui->balloons->setStyleSheet("font: 18pt; color: #000000;");

    ui->points->appendPlainText(score.at(2));
    ui->points->setStyleSheet("font: 18pt; color: #000000;");
}

void Scores::btnMenu()
{
    emit returnToMenu();
}


#include "Menu.h"
#include "ui_Menu.h"

#include <QtDebug>
#include <QFileDialog>
#include <fstream>

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;

#include "scenes/Help/Help.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);

    ui->btnPlay->setEnabled(false);

    connect(ui->btnFile, SIGNAL(clicked()), this, SLOT(setFileName()));

    connect(ui->btnEasy, SIGNAL(clicked()), this, SLOT(changeDifficulty()));
    connect(ui->btnMedium, SIGNAL(clicked()), this, SLOT(changeDifficulty()));
    connect(ui->btnHard, SIGNAL(clicked()), this, SLOT(changeDifficulty()));

    connect(ui->btnPlay, SIGNAL(clicked()), this, SLOT(startGame()));

    connect(ui->btnHelp, SIGNAL(clicked()), this, SLOT(showHelp()));
    connect(ui->btnScores, SIGNAL(clicked()), this, SLOT(showScores()));
}

Menu::~Menu() { delete ui; }

json Menu::getPhrases()
{
    return phrases;
}

Menu::Difficulty Menu::getDifficulty()
{
    return gameDifficulty;
}

bool Menu::isLatinExtended()
{
    return latinExtended;
}

void Menu::loadJson()
{
    std::ifstream filestream(fileName.toUtf8().constData());
    if (!filestream) {
        ui->labelFile->setText("There was an error reading the file!");
    }
    else {
        jsonFile = json::parse(filestream);
        if (jsonFile.is_discarded()) {
            ui->labelFile->setText("Invalid JSON: " + fileName);
            ui->btnPlay->setEnabled(false);
        }
        else {
            ui->labelFile->setText("OK: " + fileName);
            if (jsonFile.json::at("/lang"_json_pointer) == "pl") {
#ifdef DEBUG
                qDebug() << "Lang: pl\n";
#endif // DEBUG
                latinExtended = true;
            }
            else {
                latinExtended = false;
            }
            phrases = jsonFile.json::at("/Phrases"_json_pointer);
            ui->btnPlay->setEnabled(true);
        }
    }
}

void Menu::setFileName()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open JSON file"), "C:/", tr("JSON Files (*.json)"));
    loadJson();
}

void Menu::changeDifficulty()
{
    QPushButton* btn = (QPushButton*)sender();
    QString senderName = btn->objectName();

    if (senderName == "btnEasy") {
        gameDifficulty = Difficulty::Easy;
        ui->btnEasy->setChecked(true);
        ui->btnMedium->setChecked(false);
        ui->btnHard->setChecked(false);
    }
    else if (senderName == "btnMedium") {
        gameDifficulty = Difficulty::Medium;
        ui->btnEasy->setChecked(false);
        ui->btnMedium->setChecked(true);
        ui->btnHard->setChecked(false);
    }
    else if (senderName == "btnHard") {
        gameDifficulty = Difficulty::Hard;
        ui->btnEasy->setChecked(false);
        ui->btnMedium->setChecked(false);
        ui->btnHard->setChecked(true);
    }

}

void Menu::startGame()
{
    emit startGameSignal();
}

void Menu::showHelp()
{
    Help h;
    h.exec();
}

void Menu::showScores()
{
    emit showScoresSignal();
}

#include "Hangman.h"
#include "ui_Hangman.h"

#include <QtDebug>
#include <fstream>
#include <iostream>
#include <Windows.h>

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;



Hangman::Hangman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hangman)
{
    ui->setupUi(this);

    filename = "C:/dev/test.json";
}

Hangman::~Hangman() { delete ui; }


void Hangman::on_btnLoad_clicked()
{
    loadJson();
}

void Hangman::on_btnPrint_clicked()
{
    printJsonArray();
}

void Hangman::loadJson()
{
    std::ifstream filestream(filename);
    if (!filestream) {
        qDebug() << "There was an error reading the file! \n";
    }
    else {
        qDebug() << "Everything's ok. \n";
        jsonFile = json::parse(filestream);
    }
}

void Hangman::printJsonArray()
{
    for (auto& element : jsonFile) {
        qDebug() << QString::fromStdString(element.dump());
    }



}

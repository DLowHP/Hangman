#include "Game.h"
#include "ui_Game.h"

#include <QDebug>
#include <QPushButton>
#include <QRandomGenerator>

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;

#include "scenes/Menu/Menu.h"

#define DEBUG

Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);


    const QString btnLetters[35] = { "A", "A_", "B", "C", "C_", "D", "E", "E_", "F", "G", "H", "I", "J", "K", "L", "L_", "M", "N", "N_", "O", "O_", "P", "Q", "R", "S", "S_", "T", "U", "V", "W", "X", "X_", "Y", "Z", "Z_" };
    for (int i = 0; i < 35; i++) {
        QString btnName = "btn" + btnLetters[i];
        connect(Game::findChild<QPushButton*>(btnName), SIGNAL(clicked()), this, SLOT(checkLetter()));
    }

    connect(ui->btnMenu, SIGNAL(clicked()), this, SLOT(printArray()));
    connect(ui->btnRandom, SIGNAL(clicked()), this, SLOT(drawPhrase()));

}

Game::~Game() { delete ui; }

void Game::setMenuRef(Menu* ptr)
{
    menu = ptr;
}

void Game::setupGame()
{
    phrases = menu->getPhrases();

    //! Possible loss of data... 
    //  Probably should be changed (to what? Can't be size_t as phrasesAmount is used in QRandomGenerator)
    phrasesAmount = phrases.json::size();

    gameDifficulty = menu->getDifficulty();
    
    //Resets game state, draws random phrase and encodes it.
    resetGame();

#ifdef DEBUG
    switch (gameDifficulty) {
        case Menu::Difficulty::Easy:
            qDebug() << "Difficulty: Easy\n";
            break;

        case Menu::Difficulty::Medium:
            qDebug() << "Difficulty: Medium\n";
            break;

        case Menu::Difficulty::Hard:
            qDebug() << "Difficulty: Hard\n";
            break;

        default:
            qDebug() << "Something went wrong...\n";
            break;
    }
#endif
}

void Game::toggleLatinExtendedBtns(bool disable)
{
    const QString latinExtendedBtnsLetters[9] = { "A_", "C_", "E_", "L_", "N_", "O_", "S_", "X_", "Z_" };

    for (int i = 0; i < 9; i++) {
        QString btnName = "btn" + latinExtendedBtnsLetters[i];
        Game::findChild<QPushButton*>(btnName)->setDisabled(disable);
    }
}

void Game::resetGame()
{
    balloons = static_cast<int>(gameDifficulty);

    const QString btnLettersWoLE[26] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    for (int i = 0; i < 26; i++) {
        QString btnName = "btn" + btnLettersWoLE[i];
        Game::findChild<QPushButton*>(btnName)->setDisabled(false);
        Game::findChild<QPushButton*>(btnName)->setStyleSheet("QPushButton { border: 5px solid #000000; font-size: 16pt; background-color: #ffffff; color: #000000; } \
                                                               QPushButton:!enabled { border: 5px solid #c7c7c7; background-color: #ffffff; color: #c7c7c7; }");
    }

    //Reenables latin extended letters.
    if (!menu->isLatinExtended()) { toggleLatinExtendedBtns(false); };

    drawPhrase();
}

void Game::drawPhrase()
{
    int randomNumber = QRandomGenerator::global()->bounded(phrasesAmount);
    json currentPhrasePtr = phrases.at(randomNumber);

    currentCategory = QString::fromStdString(currentPhrasePtr.value("/category"_json_pointer, "Error: Wrong value"));
    currentPhrase = QString::fromStdString(currentPhrasePtr.value("/phrase"_json_pointer, "Error: Wrong value"));

    encodePhrase();

#ifdef DEBUG
    qDebug() << "Category: " << currentCategory << '\n';
    qDebug() << "Phrase: " << currentPhrase << '\n';
#endif // DEBUG
}

void Game::encodePhrase()
{
    secretPhrase.clear();
    for (int i = 0; i < currentPhrase.length(); i++) {
        if (currentPhrase[i] != ' ') {
            secretPhrase += "_ ";
        }
        else {
            secretPhrase += "  ";
        }
    }

    secretPhrase.chop(1);
    ui->phrase->setText(secretPhrase);
}

void Game::checkLetter()
{
    QPushButton* btn = (QPushButton*)sender();

    QChar letter = btn->text()[0];
#ifdef DEBUG
    qDebug() << letter << '\n';
#endif

    bool goodAnswer = false;

    for (int i = 0; i < currentPhrase.length(); i++) {
        QString temp = currentPhrase[i];
        if ((temp.compare(letter, Qt::CaseInsensitive)) == 0) {
            secretPhrase[i * 2] = letter;
            ui->phrase->setText(secretPhrase);
            goodAnswer = true;
        }
    }

    if (goodAnswer) {
        btn->setStyleSheet("QPushButton { border: 5px solid #000000; font-size: 16pt; background-color: #ffffff; color: #000000; } \
                            QPushButton:!enabled { border: 5px solid #73DA93; background-color: #ffffff; color: #73DA93; }");
    }
    else {
        btn->setStyleSheet("QPushButton { border: 5px solid #000000; font-size: 16pt; background-color: #ffffff; color: #000000; } \
                            QPushButton:!enabled { border: 5px solid #DA7373; background-color: #ffffff; color: #DA7373; }");
        balloons--;
    }
    btn->setDisabled(true);

}


void Game::printArray()
{
    for (auto& element : phrases) {
        qDebug() << QString::fromStdString(element.dump()) << '\n';
    }

    //Prints first "Phrases" array element phrase.
    qDebug() << QString::fromStdString(phrases.at(0).dump()) << '\n';
    qDebug() << "\"Phrases\" size: " << phrases.json::size() << '\n';

    qDebug() << (int)gameDifficulty << '\n';

    qDebug() << "Balloons: " << balloons << '\n';
}

void Game::menuBtn()
{
    emit returnToMenu();
}

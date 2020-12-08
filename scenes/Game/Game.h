#ifndef GAME_H
#define GAME_H

#include <QWidget>

#include "scenes/Menu/Menu.h"
#include "scenes/Canvas/Canvas.h"

namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    void setMenuRef(Menu* ptr);
    void setupGame();
    QVector<QString> getScore();

private:
    Ui::Game *ui;

    Menu* menu = nullptr;
    Canvas* hangman;

    json phrases;
    int phrasesAmount;
    Menu::Difficulty gameDifficulty;

    QString currentCategory;
    QString currentPhrase;
    int phraseLetterAmount;
    int guessedLetters;

    QString secretPhrase;

    int balloons;
    int points;
    int balloonsSaved;

    QVector<QString> score;

    void toggleLatinExtendedBtns(bool disable = true);
    void encodePhrase();
    void decodePhrase();

private slots:
    void resetGame();
    void continueGame();
    void drawPhrase();
    void checkLetter();
    void printArray();
    void menuBtn();
    void saveResetGame();

signals:
    void saveScore();
    void returnToMenu();
    void redraw();
};

#endif // GAME_H

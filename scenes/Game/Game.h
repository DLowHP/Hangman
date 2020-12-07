#ifndef GAME_H
#define GAME_H

#include <QWidget>

#include "scenes/Menu/Menu.h"

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

private:
    Ui::Game *ui;

    Menu* menu = nullptr;

    json phrases;
    int phrasesAmount;
    Menu::Difficulty gameDifficulty;

    QString currentCategory;
    QString currentPhrase;

    QString secretPhrase;

    int balloons;

    void toggleLatinExtendedBtns(bool disable = true);
    void encodePhrase();

private slots:
    void resetGame();
    void drawPhrase();
    void checkLetter();
    void printArray();
    void menuBtn();

signals:
    void returnToMenu();
};

#endif // GAME_H

#ifndef HANGMAN_H
#define HANGMAN_H

#include <QMainWindow>

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;

#include "scenes/Canvas/Canvas.h"
#include "scenes/Menu/Menu.h"
#include "scenes/Game/Game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Hangman; }
QT_END_NAMESPACE

class Hangman : public QMainWindow
{
    Q_OBJECT

public:
    Hangman(QWidget *parent = nullptr);
    ~Hangman();

private:
    Ui::Hangman *ui;

    Menu* menu;
    Game* game;

private slots:
    void showMenu();
    void startGame();


};
#endif // HANGMAN_H

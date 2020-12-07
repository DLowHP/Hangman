#include "Hangman.h"
#include "ui_Hangman.h"

#include <QtDebug>
#include <fstream>
#include <iostream>
#include <Windows.h>

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;

#include "scenes/Menu/Menu.h"
#include "scenes/Game/Game.h"

#define NOALLOWCOUT

Hangman::Hangman(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hangman)
{
    ui->setupUi(this);

    menu = new Menu;
    game = new Game;

    ui->display->insertWidget(0, menu);
    ui->display->insertWidget(1, game);

    ui->display->setCurrentIndex(0);

    connect(menu, SIGNAL(startGameSignal()), this, SLOT(startGame()));
    
    //! Working draft, used to allow std::cout, probably bad practice. 
    //Found a better way, but it may be useful in future.
#ifdef ALLOWCOUT
    AllocConsole(); //Needs "Windows.h"
    FILE* fDummy;
    freopen_s(&fDummy, "CONOUT$", "w", stdout);
    freopen_s(&fDummy, "CONOUT$", "w", stderr);
    freopen_s(&fDummy, "CONIN$", "r", stdin);
    std::cout.clear();
    std::clog.clear();
    std::cerr.clear();
    std::cin.clear();
#endif
}

Hangman::~Hangman() { delete ui; }

void Hangman::showMenu()
{
    ui->display->setCurrentIndex(0);
}

void Hangman::startGame()
{
    ui->display->setCurrentIndex(1);
    game->setMenuRef(menu);
    game->setupGame();
}

#ifndef MENU_H
#define MENU_H

#include <QWidget>

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;

#include "scenes/Help/Help.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

    json getPhrases();

    enum class Difficulty {
        Easy = 7,
        Medium = 6,
        Hard = 5
    };

private:
    Ui::Menu *ui;

    QString fileName;
    json jsonFile;
    bool latinExtended = false;
    json phrases;

    Difficulty gameDifficulty = Difficulty::Easy;

    void loadJson();

public:
    Difficulty getDifficulty();
    bool isLatinExtended();

private slots:
    void setFileName();
    void changeDifficulty();
    void startGame();
    void showHelp();
    void showScores();

signals:
    void startGameSignal();
    void showScoresSignal();
};

#endif // MENU_H

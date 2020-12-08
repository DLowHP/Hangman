#ifndef SCORES_H
#define SCORES_H

#include <QWidget>

#include "scenes/Game/Game.h"

namespace Ui {
class Scores;
}

class Scores : public QWidget
{
    Q_OBJECT

public:
    explicit Scores(QWidget *parent = nullptr);
    ~Scores();

    void setGameRef(Game* ptr);
    void saveScore();

private:
    Ui::Scores *ui;

    Game* g;

private slots:
    void btnMenu();

signals:
    void returnToMenu();
};

#endif // SCORES_H

#ifndef GAMEFINISH_H
#define GAMEFINISH_H

#include <QDialog>

namespace Ui {
class GameFinish;
}

class GameFinish : public QDialog
{
    Q_OBJECT

public:
    explicit GameFinish(QWidget *parent = nullptr);
    ~GameFinish();

    bool gameWon;

    void setOutcome(bool gameWon = false);
    void setScore(int score);

private:
    Ui::GameFinish *ui;

private slots:
    void btnMenuClicked();
    void btnContinueClicked();

signals:
    void playAgain();
    void returnToMenu();
};

#endif // GAMEFINISH_H

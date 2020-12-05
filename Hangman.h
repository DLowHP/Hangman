#ifndef HANGMAN_H
#define HANGMAN_H

#include <QMainWindow>

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
};
#endif // HANGMAN_H

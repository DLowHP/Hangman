#ifndef HANGMAN_H
#define HANGMAN_H

#include <QMainWindow>

#include "include/nlohmann/json.hpp"
using json = nlohmann::json;

QT_BEGIN_NAMESPACE
namespace Ui { class Hangman; }
QT_END_NAMESPACE

class Hangman : public QMainWindow
{
    Q_OBJECT

public:
    Hangman(QWidget *parent = nullptr);
    ~Hangman();

private slots:
    void on_btnLoad_clicked();

    void on_btnPrint_clicked();

private:
    Ui::Hangman *ui;

    std::string filename;
    json jsonFile;
    
    void loadJson();
    void printJsonArray();

};
#endif // HANGMAN_H

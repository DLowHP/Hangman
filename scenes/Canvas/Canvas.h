#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);
    ~Canvas();

protected:
    void paintEvent(QPaintEvent* event);


private:
    Ui::Canvas *ui;
};

#endif // CANVAS_H

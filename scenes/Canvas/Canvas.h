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

    void redraw();
    void setBallons(int value);

protected:
    void paintEvent(QPaintEvent* event);

private:
    Ui::Canvas *ui;

    int ballons;
};

#endif // CANVAS_H

#include "Canvas.h"
#include "ui_Canvas.h"

#include <QPainter>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
}

Canvas::~Canvas()
{
    delete ui;
}


void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing);

    //Center drawing
    p.translate(width() / 2, height() / 2);

    //Scale to fit
    int side = qMin(width(), height());
    p.scale(side / 200.0, side / 200.0);



    
}
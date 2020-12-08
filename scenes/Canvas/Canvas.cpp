#include "Canvas.h"
#include "ui_Canvas.h"

#include <QPainter>
#include <QPen>
#include <QBrush>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas)
{
    ui->setupUi(this);
    ballons = 0;
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::redraw()
{
    this->update();
}

void Canvas::setBallons(int value)
{
    this->ballons = value;
}

void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter p(this);
    QPen pen(Qt::black);
    QBrush brush(Qt::black);

    p.setRenderHint(QPainter::Antialiasing);

    brush.setColor(Qt::cyan);
    p.setBrush(brush);
    pen.setColor(Qt::transparent);
    p.setPen(pen);
    p.drawRect(0, 0, width(), height());

    brush.setColor(Qt::transparent);
    p.setBrush(brush);
    pen.setColor(Qt::black);
    pen.setWidth(5);
    p.setPen(pen);

    /* Stickman */
    pen.setColor(Qt::black);
    pen.setWidth(5);
    p.setPen(pen);

    //Head
    brush.setColor(Qt::gray);
    p.setBrush(brush);
    p.drawEllipse(225, 200, 50, 50);
    brush.setColor(Qt::transparent);
    p.setBrush(brush);
    //Eyes
    p.drawPoint(240, 217);
    p.drawPoint(260, 217);
    //Mouth
    pen.setWidth(2);
    p.setPen(pen);
    QRect rect(230, 230, 30, 10);
    p.drawArc(rect, 480, 1920);
    pen.setWidth(5);
    p.setPen(pen);
    //Hands
    p.drawLine(250, 300, 200, 225); //A1
    p.drawLine(200, 225, 250, 175); //B1
    p.drawLine(250, 300, 300, 225); //A2
    p.drawLine(300, 225, 250, 175); //B2
    //Body
    p.drawLine(250, 250, 250, 375);
    //Legs
    p.drawLine(250, 375, 200, 425);
    p.drawLine(250, 375, 300, 425);

    QPoint attach(250, 175);

    QPoint bAttach(325, 100);
    QPoint bPoint(bAttach.x(), 70);

    switch (ballons) {
    case 7:
        brush.setColor(Qt::red);
        p.setBrush(brush);

        //Balloon line
        bAttach.setX(325);
        p.drawLine(attach, bAttach);

        //Ballon
        bPoint.setX(bAttach.x());
        p.drawEllipse(bPoint, 25, 30);

    case 6:
        brush.setColor(Qt::green);
        p.setBrush(brush);


        //Balloon line
        bAttach.setX(175);
        p.drawLine(attach, bAttach);

        //Ballon
        bPoint.setX(bAttach.x());
        p.drawEllipse(bPoint, 25, 30);

    case 5:
        brush.setColor(Qt::blue);
        p.setBrush(brush);


        //Balloon line
        bAttach.setX(300);
        p.drawLine(attach, bAttach);

        //Ballon
        bPoint.setX(bAttach.x());
        p.drawEllipse(bPoint, 25, 30);
        
    case 4:
        brush.setColor(Qt::magenta);
        p.setBrush(brush);


        //Balloon line
        bAttach.setX(200);
        p.drawLine(attach, bAttach);

        //Ballon
        bPoint.setX(bAttach.x());
        p.drawEllipse(bPoint, 25, 30);
        
    case 3:
        brush.setColor(Qt::yellow);
        p.setBrush(brush);


        //Balloon line
        bAttach.setX(275);
        p.drawLine(attach, bAttach);

        //Ballon
        bPoint.setX(bAttach.x());
        p.drawEllipse(bPoint, 25, 30);
        
    case 2:
        brush.setColor(Qt::cyan);
        p.setBrush(brush);


        //Balloon line
        bAttach.setX(225);
        p.drawLine(attach, bAttach);

        //Ballon
        bPoint.setX(bAttach.x());
        p.drawEllipse(bPoint, 25, 30);
        
    case 1:
        brush.setColor(Qt::white);
        p.setBrush(brush);

        //Balloon line
        bAttach.setX(250);
        p.drawLine(attach, bAttach);

        //Ballon
        bPoint.setX(bAttach.x());
        p.drawEllipse(bPoint, 25, 30);


        brush.setColor(Qt::transparent);
        p.setBrush(brush);

        pen.setColor(Qt::black);
        pen.setWidth(5);
        p.setPen(pen);

        break;

    case 0:
        p.eraseRect(0, 0, 510, 460);

        brush.setColor(Qt::cyan);
        p.setBrush(brush);
        pen.setColor(Qt::transparent);
        p.setPen(pen);
        p.drawRect(0, 0, width(), height());

        brush.setColor(Qt::green);
        pen.setColor(Qt::transparent);
        p.setPen(pen);
        p.setBrush(brush);
        p.drawRect(0, height() - 200, width(), height());

        brush.setColor(Qt::transparent);
        p.setBrush(brush);
        pen.setColor(Qt::black);
        pen.setWidth(5);
        p.setPen(pen);

        p.save();
        p.translate(600, 220);
        p.rotate(110);

        //Head
        brush.setColor(Qt::gray);
        p.setBrush(brush);
        p.drawEllipse(225, 200, 50, 50);
        brush.setColor(Qt::transparent);
        p.setBrush(brush);

        pen.setWidth(2);
        p.setPen(pen);
        p.drawLine(235, 212, 245, 222);
        p.drawLine(235, 222, 245, 212);
        p.drawLine(255, 212, 265, 222);
        p.drawLine(255, 222, 265, 212);
        pen.setWidth(5);
        p.setPen(pen);

        //Hands
        p.drawLine(250, 300, 200, 270); //A1
        p.drawLine(250, 300, 300, 270); //A2
        //Body
        p.drawLine(250, 250, 250, 375);
        //Legs
        p.drawLine(250, 375, 200, 425);
        p.drawLine(250, 375, 300, 425);

        p.restore();
    }
    p.end();
}


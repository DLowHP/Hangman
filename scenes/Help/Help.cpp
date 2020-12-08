#include "Help.h"
#include "ui_Help.h"

Help::Help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Help)
{
    ui->setupUi(this);

    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(btnOk()));
}

Help::~Help()
{
    delete ui;
}


void Help::btnOk()
{
    this->close();
}
#include "helpform.h"
#include "ui_helpform.h"

helpForm::helpForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::helpForm)
{
    ui->setupUi(this);
}

helpForm::~helpForm()
{
    delete ui;
}

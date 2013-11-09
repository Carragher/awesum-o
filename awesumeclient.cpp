#include "awesumeclient.h"
#include "ui_awesumeclient.h"

AwesumeClient::AwesumeClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AwesumeClient)
{
    ui->setupUi(this);
}

AwesumeClient::~AwesumeClient()
{
    delete ui;
}

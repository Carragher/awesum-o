#include "bulletgui.h"

bulletgui::bulletgui(MainWindow* parent,Bullet* newBull,QWidget* newWorld) : QLabel(newWorld)
{
    this->win = parent;
    this->bull = newBull;
    this->pix = new QPixmap(50, 50);
    this->setStyleSheet("background-color:rgba(255,255,255,100%)");

}

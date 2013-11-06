#include "bulletgui.h"

BulletGUI::BulletGUI(MainWindow* parent, Bullet* newBull, QWidget* newWorld) : QLabel(newWorld)
{
    win = parent;
    bull = newBull;
    pix = new QPixmap(50, 50);
    this->setStyleSheet("background-color:rgba(255,255,255,100%)");

}

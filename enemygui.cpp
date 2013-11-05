#include "enemygui.h"

EnemyGUI::EnemyGUI(MainWindow* parent, Enemy* newEn, QWidget *newWorld) : QLabel(newWorld)
{
    win = parent;
    enemy = newEn;
    //load appropriate pixmap based on enemy type
    if (enemy->getType() == "walker")
    {
        pic.load(":/walkerRight.png");
    }
    else if (enemy->getType() == "sergeant")
    {
        pic.load(":/SergeantRight.png");
    }
    else if (enemy->getType() == "YOLO")
    {
        pic.load(":/YOLORight.png");
    }

}

void EnemyGUI::updateDirection()
{
    if (enemy->getDirection() == "right")
    {
        pic.load(":/walkerRight.png");
    }
    else if (enemy->getDirection() == "down")
    {
        pic.load(":/walkerDown.png");
    }
    else if (enemy->getDirection() == "left")
    {
        pic.load(":/walkerLeft.png");
    }
}

#include "enemygui.h"
//Create enemy image
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
//Change enemy image based on enemy direction
void EnemyGUI::updateDirection()
{
    if (enemy->getType() == "walker")
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
    else if (enemy->getType() == "sergeant")
    {
        if (enemy->getDirection() == "right")
        {
            pic.load(":/SergeantRight.png");
        }
        else if (enemy->getDirection() == "down")
        {
            pic.load(":/SergeantDown.png");
        }
        else if (enemy->getDirection() == "left")
        {
            pic.load(":/SergeantLeft.png");
        }
    }
    else if (enemy->getType() == "YOLO")
    {
        if (enemy->getDirection() == "right")
        {
            pic.load(":/YOLORight.png");
        }
        else if (enemy->getDirection() == "down")
        {
            pic.load(":/YOLODown.png");
        }
        else if (enemy->getDirection() == "left")
        {
            pic.load(":/YOLOLeft.png");
        }
    }
}

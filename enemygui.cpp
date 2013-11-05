#include "enemygui.h"

EnemyGUI::EnemyGUI(MainWindow* parent, Enemy* newEn, QWidget *newWorld) : QLabel(newWorld)
{
    win = parent;
    enemy = newEn;
    //load appropriate pixmap based on enemy type
    if (enemy->getType() == "walker")
    {
        pic.load(":/walker.png");
    }
    else if (enemy->getType() == "sergeant")
    {
        pic.load(":/sergeant.png");
    }
    else if (enemy->getType() == "YOLO")
    {
        pic.load(":/YOLO.png");
    }

}


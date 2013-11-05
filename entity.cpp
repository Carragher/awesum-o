#include <iostream>
#include "entity.h"
#include "world.h"

Entity::Entity(MainWindow *parent, Tile *newTile, QWidget *newWorld): QLabel(newWorld)
{
    this->mouseclick = false;
    this->win = parent;
    this->tile = newTile;
    if (dynamic_cast<pathTile*>(tile)) {
//        tilePic.load(":/empty.png");
//        this->setHidden(true);
        this->setStyleSheet("background-color: rgba(0,0,0,0%)");
//        tilePic.fill(Qt::transparent);
    } else if (dynamic_cast<towerTile*>(tile)) {
        tilePic.load(":/basicTowwa.gif");
    } else if (dynamic_cast<normalTile*>(tile)) {
        tilePic.load(":/normal.gif");
    }
}

// if the mouse enters the Entity change the color - these methods can be used for tower placement!
void Entity::enterEvent(QEvent *ev) {
    if (dynamic_cast<pathTile*>(tile)) {
        this->setStyleSheet("QLabel { background-color : red; border-style:dotted; border-width:1px; border-color: black; }");
    } else if (dynamic_cast<towerTile*>(tile)) {
        this->setStyleSheet("QLabel { border-style:dotted; border-width:1px; border-color: black; }");
    } else if (dynamic_cast<normalTile*>(tile)) {
        this->setStyleSheet("QLabel { border-style:dotted; border-width:1px; border-color: black; }");
    }
}

// if the mouse leaves the Entity, change the color
void Entity::leaveEvent(QEvent *ev) {
    this->setStyleSheet("QLabel { background-color : none; border-style:none; }");
}

void Entity::mouseReleaseEvent(QMouseEvent *ev) {
    if (dynamic_cast<normalTile*>(tile) && win->getCanCreateTower()) {
        // change the entitys pointer to a tile!

        // delete the normal tile
//        this->hide();
        win->createTower(tile->getX(), tile->getY());
        // create the tower tile!
//        this->tile = ;
        this->setStyleSheet("QLabel { background-color : black; border-style:dotted; border-width:1px; border-color: black; }");

    }
}


#include <iostream>
#include "entity.h"
#include "world.h"

Entity::Entity(MainWindow *parent, Tile *newTile, QWidget *newWorld): QLabel(newWorld)
{
    this->mouseclick = false;
    this->win = parent;
    this->tile = newTile;
    if (dynamic_cast<pathTile*>(tile)) {
        tilePic.load(":/path.gif");
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
        this->setStyleSheet("QLabel { background-color : red; border-style:dotted; border-width:1px; border-color: black; }");
    } else if (dynamic_cast<normalTile*>(tile)) {
        this->setStyleSheet("QLabel { background-color : blue; border-style:dotted; border-width:1px; border-color: black; }");
    }
}

// if the mouse leaves the Entity, change the color
void Entity::leaveEvent(QEvent *ev) {
    if (dynamic_cast<pathTile*>(tile)) {
        this->setStyleSheet("QLabel { background-color : SaddleBrown; border-style:dotted; border-width:1px; border-color: black; }");
    } else if (dynamic_cast<towerTile*>(tile)) {
        this->setStyleSheet("QLabel { background-color : black; border-style:dotted; border-width:1px; border-color: black; }");
    } else if (dynamic_cast<normalTile*>(tile)) {
        this->setStyleSheet("QLabel { background-color : green; border-style:dotted; border-width:1px; border-color: black; }");
    }
}

void Entity::mouseReleaseEvent(QMouseEvent *ev) {
    if (dynamic_cast<normalTile*>(tile) && win->getCanCreateTower()) {
        // change the entitys pointer to a tile!

        // delete the normal tile
        this->hide();
        win->createTower(tile->getX(), tile->getY());
        // create the tower tile!
//        this->tile = ;
        this->setStyleSheet("QLabel { background-color : black; border-style:dotted; border-width:1px; border-color: black; }");

    }
}


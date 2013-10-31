#include <iostream>
#include "entity.h"
#include "world.h"

//Entity::Entity()
//{
//    posX = 0;
//    posY = 0;
//    enemy.load(":/images/logo.jpeg");
//}

/*QRectF Entity::boundingRect() const
{
    return QRect(posX-15, posY-15, 20, 20);
}

void Entity::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    painter->drawPixmap(posX-15, posY-15, 0, 0, enemy);
}*/

void Entity::setX(int x) {posX = x; }

void Entity::setY(int y) {posY = y; }


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


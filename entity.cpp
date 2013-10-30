#include <iostream>
#include "entity.h"

//Entity::Entity()
//{
//    posX = 0;
//    posY = 0;
//    enemy.load(":/images/logo.jpeg");
//}

QRectF Entity::boundingRect() const
{
    return QRect(posX-15, posY-15, 20, 20);
}

void Entity::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    painter->drawPixmap(posX-15, posY-15, 0, 0, enemy);
}

void Entity::setX(int x) {posX = x; }

void Entity::setY(int y) {posY = y; }


// if the mouse enters the Entity change the color - these methods can be used for tower placement!
void Entity::enterEvent(QEvent *ev) {

    if (!dynamic_cast<pathTile*>(tile) && !dynamic_cast<towerTile*>(tile)) {
        this->setStyleSheet("QLabel { background-color : red; border-style:dotted; border-width:1px; border-color: black; }");
    }
}

// if the mouse leaves the Entity, change the color
void Entity::leaveEvent(QEvent *ev) {
    if (!dynamic_cast<pathTile*>(tile) && !dynamic_cast<towerTile*>(tile)) {
        this->setStyleSheet("QLabel { background-color : grey; border-style:dotted; border-width:1px; border-color: black; }");
    }

}

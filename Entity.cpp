#include "Entity.h"

Entity::Entity()
{
    posX = 0;
    posY = 0;
    enemy.load(":/images/logo.jpeg");
}

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

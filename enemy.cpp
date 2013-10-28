#include "enemy.h"

int Enemy::nextId = 0;

void Walker::deathUpdate()
{
    int checkHP = this->getHp();
    if (checkHP <= 0)
    {
        delete this;
    }
}

void Walker::updatePosition()
{
    int update = this->getMoveSpeed();
    int newX = this->getX();
    int newY = this->getY();

    newX+=update;
    newY+=update;

    this->setX(newX);
    this->setY(newY);

}

void Sergeant::deathUpdate()
{
    int checkHP = this->getHp();
    if (checkHP <= 0)
    {
        delete this;
    }
}

void Sergeant::updatePosition()
{
    int update = this->getMoveSpeed();
    int newX = this->getX();
    int newY = this->getY();

    newX+=update;
    newY+=update;

    this->setX(newX);
    this->setY(newY);
}

void YOLO::deathUpdate()
{
    int checkHP = this->getHp();
    if (checkHP <= 0)
    {
        delete this;
    }
}

void YOLO::updatePosition()
{
    int update = this->getMoveSpeed();
    int newX = this->getX();
    int newY = this->getY();

    newX+=update;
    newY+=update;

    this->setX(newX);
    this->setY(newY);
}

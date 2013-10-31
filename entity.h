#ifndef ENTITY_H
#define ENTITY_H
#include <QPainter>
#include <QLabel>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "mainwindow.h"
#include "tile.h"

using namespace std;

class MainWindow;

class Entity: public QLabel {
        MainWindow *win;
        Tile *tile;
        bool mouseclick;

    public:
        explicit Entity(MainWindow *parent, Tile *newTile, QWidget *newWorld):
                        QLabel(newWorld), win(parent), tile(newTile) {mouseclick = false; }

        /*QRectF boundingRect() const;
        void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);*/
        void setX (int);
        void setY (int);

        //void enterEvent(QEvent *);
       // void leaveEvent(QEvent *);
        void mouseReleaseEvent(QMouseEvent *);
    
        QPixmap enemy;
        int posX, posY;
    
    ~Entity(){}
};


#endif //ENTITY_H

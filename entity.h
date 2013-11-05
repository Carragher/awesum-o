#ifndef ENTITY_H
#define ENTITY_H
#include <QLabel>
#include "mainwindow.h"
#include "tile.h"

using namespace std;

class MainWindow;

class Entity: public QLabel {
        MainWindow *win;
        Tile *tile;
        bool mouseclick;
        QPixmap tilePic;
    public:
        explicit Entity(MainWindow*, Tile*, QWidget*);

        void setPic(){this->setPixmap(tilePic.scaled(50,50));}

        void enterEvent(QEvent *);
        void leaveEvent(QEvent *);
        void mouseReleaseEvent(QMouseEvent *);
        

};


#endif //ENTITY_H

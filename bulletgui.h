#ifndef BULLETGUI_H
#define BULLETGUI_H

#include <QLabel>
#include <string>
#include "bullet.h"
#include "mainwindow.h"
using namespace std;


class BulletGUI : public QLabel
{
    Q_OBJECT
    MainWindow *win;
    Bullet *bull;
    QPixmap *pix;

public:
    explicit BulletGUI(MainWindow*, Bullet*, QWidget*);

    Bullet *getBulletObj() {return bull;}

};

#endif // BULLETGUI_H

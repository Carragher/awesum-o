#ifndef ENEMYGUI_H
#define ENEMYGUI_H

#include <QLabel>
#include "enemy.h"
#include "mainwindow.h"
class EnemyGUI : public QLabel
{
    Q_OBJECT
    MainWindow *win;
    Enemy *enemy;

public:
    explicit EnemyGUI(MainWindow* parent, Enemy* newEn,QWidget *newWorld):
        QLabel(newWorld), win(parent), enemy(newEn){}
    
signals:
    
public slots:
    
};

#endif // ENEMYGUI_H

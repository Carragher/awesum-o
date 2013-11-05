#ifndef ENEMYGUI_H
#define ENEMYGUI_H

#include <QLabel>
#include <string>
#include "enemy.h"
#include "mainwindow.h"
using namespace std;
class EnemyGUI : public QLabel
{
    Q_OBJECT
    MainWindow *win;
    Enemy *enemy;
    QPixmap pic;
public:
    explicit EnemyGUI(MainWindow*, Enemy*,QWidget*);

    void setPic() { this->setPixmap(pic.scaled(50,50));}

    Enemy *getEnemyObj() { return enemy; }
    
signals:
    
public slots:
    
};

#endif // ENEMYGUI_H

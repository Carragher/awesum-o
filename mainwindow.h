#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Entity.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerHit();
    
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Entity *enemy;
};

#endif // MAINWINDOW_H

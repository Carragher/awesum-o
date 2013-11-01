#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "entity.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QTimer>
#include <QGraphicsItem>
#include <sstream>
#include <string>
#include <iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    bool play;
    QTimer *TIMER;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerHit();

    void initWorld();
    void loadPath(std::string pathString);
    void createPath(std::string cmd);

    void setPlay(bool newPlay) { play = newPlay; }

    bool getPlay() { return play; }

    void createTower(int x, int y);

    bool getCanCreateTower();

    int getSlotCoord(int slotNum, std::string coordType);

    void doCreate(std::stringstream& cmd);

    // save and load functinoality
    void save();
    void load();
    
private slots:
    void on_btnLoadLevel_clicked();

    void on_btnStartLevel_clicked();

    void on_btnAddTower_clicked();

private:
    Ui::MainWindow *ui;
//    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H

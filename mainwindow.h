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
    
private slots:
    void on_btnLoadLevel_clicked();

    void on_btnStartLevel_clicked();

    void on_btnAddTower_clicked();

private:
    Ui::MainWindow *ui;
//    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H

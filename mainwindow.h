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
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void timerHit();

    void initWorld();
    void loadPath(std::string pathString);
    void createPath(std::string cmd);

    void setPlay(bool newPlay) { play = newPlay; }

    bool getPlay() { return play; }
    
private slots:
    void on_spawnBtn_clicked();

    void on_buyBtn_clicked();

private:
    Ui::MainWindow *ui;
//    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H

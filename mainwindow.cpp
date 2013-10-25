#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    /*
    // Add the vertical lines first, paint them red
    for (int x=0; x<=500; x+=50)
        scene->addLine(x,0,x,500, QPen(Qt::red));

    // Now add the horizontal lines, paint them green
    for (int y=0; y<=500; y+=50)
        scene->addLine(0,y,500,y, QPen(Qt::green));*/
    //    enemy = new Entity;
    //    scene->addItem(Enemy);

    // timer for updating the game
    QTimer *timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, &QTimer::timeout, this, &MainWindow::timerHit);
    timer->start();
    this->show();
    scene->update();
    this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
//    delete enemy;`
}


void MainWindow::timerHit() {

    // get a collection of tiles and enemies
    // run the update method on each object




}

void MainWindow::on_spawnBtn_clicked()
{
    //    Entity e = new Entity();

    int test = World::getInstance().getScore();
    QString q = QString::number(test);
    ui->scoreLbl->setText(q);
}

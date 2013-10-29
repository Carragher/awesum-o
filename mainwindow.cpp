#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world.h"
#include "command.h"
#include "tile.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

//    scene = new QGraphicsScene(this);
//    ui->graphicsView->setScene(scene);
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
//    this->show();
//    scene->update();
//    this->update();
    this->initWorld();
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete scene;
//    delete enemy;
}


void MainWindow::timerHit() {

    // get a collection of tiles
    //and enemies
    // run the update method on each object

}

void MainWindow::on_spawnBtn_clicked()
{
    //    Entity e = new Entity();

    int test = World::getInstance().getScore();
    QString q = QString::number(test);
    ui->scoreLbl->setText(q);
}

void MainWindow::initWorld() {
    // 16 x 10
    int x = 0;
    int y = 0;

    for (int i = 0; i < 160; ++i) {
        if(i == 16 || i == 32 || i == 48 || i == 64 || i == 80 || i == 96 || i == 112 || i == 128 || i == 144) {
            y += 50;
            x = 0;
        } else if (i != 0) {
            x += 50;
        }

        // create the object in the model and name it obj


        CreateCommand *createObj = new CreateCommand("tile", "tile");
        createObj->execute();
        Tile *obj = World::getInstance().getTiles().back();

        obj->setX(x);
        obj->setY(y);

        // create the entity labels
        Entity *tile = new Entity(this, obj, ui->graphicsView);
        // set the location of the entity
        tile->setScaledContents(true);
        tile->setGeometry(obj->getX(), obj->getY(), 50, 50);
        tile->setStyleSheet("QLabel { background-color : red; color : blue; }");
        tile->show();

        delete createObj;
    }

//    return true;

}

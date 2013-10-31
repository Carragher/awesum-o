#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world.h"
#include "command.h"
#include "tile.h"
#include "enemygui.h"
#include "storage.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->btnAddTower->setCheckable(true);
    ui->btnAddTower->setEnabled(false);
    ui->btnStartLevel->setEnabled(false);

    TIMER = new QTimer(this);
}

MainWindow::~MainWindow() {
    delete ui;
    World::getInstance().reset();
//    delete scene;
//    delete enemy;
}

void MainWindow::timerHit() {

    // get a collection of tiles
    //and enemies

    // move hte enemies

    // check and see if there are any enemies

    vector<Enemy*> toUpdate = World::getInstance().getEnemies();

    if (toUpdate.size() > 0) {
//        for (int a = 0; a < toUpdate.size(); ++a) {
//            toUpdate.at(a)->updatePosition();
//        }
        for (EnemyGUI* curEnemy : storage::getInstance().getEngui()) {
            curEnemy->getEnemyObj()->updatePosition();
            curEnemy->move(curEnemy->getEnemyObj()->getX(), curEnemy->getEnemyObj()->getY());
        }
    }

//    Enemy *frenemy = World::getInstance().getEnemies().back();
//    frenemy->updatePosition();

//    EnemyGUI *en = storage::getInstance().getEngui().back();
//    en->move(frenemy->getX(), frenemy->getY());
    // run the update method on each object

}
void MainWindow::initWorld() {

    TIMER->setInterval(100);
    connect(TIMER, &QTimer::timeout, this, &MainWindow::timerHit);

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
        tile->setStyleSheet("QLabel { background-color : green; border-style:dotted; border-width:1px; border-color: black; }");
        tile->show();

        tile->setMouseTracking(true);

        delete createObj;

        // start the timer here...like you would add the beginning of a level.
        TIMER->start();

        // enable the buttons
        ui->btnAddTower->setEnabled(true);
        ui->btnStartLevel->setEnabled(true);
    }
}

void MainWindow::loadPath(string pathString) {
    vector<string> lines;

    stringstream paths(pathString);

    string line;
    getline(paths, line);

    while (paths.rdbuf()->in_avail() != 0) {
        lines.push_back(line);
        getline(paths, line);
    }

    lines.push_back(line);

    // load the path(s)
    for(int d = 0; d < lines.size(); ++d) {
        createPath(lines.at(d));
    }
}

void MainWindow::createPath(string cmd) {
    int slot = stoi(cmd);

    int x = 0;
    int y = 0;

    for (int i = 0; i < slot; ++i) {
        if(i == 16 || i == 32 || i == 48 || i == 64 || i == 80 || i == 96 || i == 112 || i == 128 || i == 144) {
            y += 50;
            x = 0;
        } else if (i != 0) {
            x += 50;
        }
    }

    vector<Tile*> tiles = World::getInstance().getTiles();

    for (int j = 0; j < tiles.size(); ++j) {
        Tile* tile = tiles.at(j);

        if(tile->getX() == x && tile->getY() == y) { // replace the thing!
            // get rid of the old tile
            delete tile;
            tiles.erase(tiles.begin()+j);

            // add the new tile!
            CreateCommand *createPath = new CreateCommand("path", "path");
            createPath->execute();

            Tile *path = World::getInstance().getTiles().back();
            path->setX(x);
            path->setY(y);

            // create the entity for it
            Entity *pathEntity = new Entity(this, path, ui->graphicsView);
            // set the location!
            pathEntity->setScaledContents(true);
            pathEntity->setGeometry(path->getX(), path->getY(), 50, 50);
            pathEntity->setStyleSheet("QLabel { background-color : SaddleBrown; border-style:dotted; border-width:1px; border-color: black; }");
            pathEntity->show();

            pathEntity->setMouseTracking(true);

            delete createPath;
        }
    }
}

void MainWindow::on_btnLoadLevel_clicked() {
    this->initWorld();
    this->loadPath("1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n32\n48\n47\n46\n45\n44\n43\n42\n41\n40\n39\n38\n37\n36\n35\n34\n33\n47\n49\n65\n66\n67\n68\n69\n70\n71\n72\n73\n74\n75\n76\n77\n78\n79\n80\n96\n97\n98\n99\n100\n101\n102\n103\n104\n105\n106\n107\n108\n109\n110\n111\n112\n113\n129\n130\n131\n132\n133\n134\n135\n136\n137\n138\n139\n140\n141\n142\n143\n144\n160");

    ui->btnLoadLevel->setEnabled(false);
}

void MainWindow::on_btnStartLevel_clicked() {

    ui->btnStartLevel->setEnabled(false); // disable the button s othe user can't start more things!
    // run the POC test:
    // move objects around

    //create enemy command
    CreateCommand *createEn = new CreateCommand("walker", "walker");
    createEn->execute();

    //test display score
    int test = World::getInstance().getScore();
    QString q = QString::number(test);
    World::getInstance().enemyDeath();
    ui->scoreLbl->setText(q);

    Enemy *texas = World::getInstance().getEnemies().back();

    EnemyGUI *ranger = new EnemyGUI(this, texas, ui->graphicsView);
    ranger->setGeometry(texas->getX(), texas->getY(), 50, 50);
    ranger->setStyleSheet("QLabel { background-color : blue; border-style:dotted; border-width:1px; border-color: black; }");
    storage::getInstance().addEngui(ranger);
    ranger->show();

    //trying to animate on button click

//    TIMER->start();

    delete createEn;

}

void MainWindow::on_btnAddTower_clicked() {    
    int ifScore = World::getInstance().getScore();
    if (ifScore > 43){
    World::getInstance().towerBuy(43);
    int test = World::getInstance().getScore();
    QString q = QString::number(test);
    ui->scoreLbl->setText(q);
    }
    World::getInstance().towerBuy(10);

}

void MainWindow::createTower(int x, int y) {
    // add the new tile!
    CreateCommand *createTower = new CreateCommand("tower", "tower");
    createTower->execute();

    Tile *tower = World::getInstance().getTiles().back();
    tower->setX(x);
    tower->setY(y);

    // create the entity for it
    Entity *towerEntity = new Entity(this, tower, ui->graphicsView);
    // set the location!
    towerEntity->setScaledContents(true);
    towerEntity->setGeometry(tower->getX(), tower->getY(), 50, 50);
    towerEntity->setStyleSheet("QLabel { background-color : black; border-style:dotted; border-width:1px; border-color: black; }");
    towerEntity->show();

    towerEntity->setMouseTracking(true);

    delete createTower;

}

bool MainWindow::getCanCreateTower() {
    return ui->btnAddTower->isChecked();
}

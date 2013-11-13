#ifndef AWESUMSERVER_H
#define AWESUMSERVER_H

#include <QDialog>
#include <QTcpServer>
#include <QTimer>
#include "world.h"
namespace Ui {
class AwesumServer;
}

class AwesumServer : public QDialog
{
    Q_OBJECT
    QTimer* SCORE;
struct player
{
    World* world;
    QString name;
    int score;
    player(World* w, QString n):
        world(w), name(n) {}
    void updateScore() {score = world->getScore();}
};

public:
    explicit AwesumServer(QWidget *parent = 0);
    ~AwesumServer();
    void addToLog(QString msg);
    vector<player*> players;
    bool getConnection(){return connection;}
    void timerHit();
    void createUsers(QString);
private slots:
    void clientConnected();
    void dataReceived();
    void clientDisconnected();

    void on_btnDisconnect_clicked();

private:
    Ui::AwesumServer *ui;
    QTcpServer server;
    int usrCount;
    bool connection;
    /*int score;
    QString usr;*/
};

#endif // AWESUMSERVER_H

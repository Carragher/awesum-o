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
public:
    explicit AwesumServer(QWidget *parent = 0);
    ~AwesumServer();
    void addToLog(QString msg);

    bool getConnection(){return connection;}
    void timerHit();
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
    QString usr;
};

#endif // AWESUMSERVER_H

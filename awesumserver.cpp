#include "awesumserver.h"
#include "ui_awesumserver.h"
#include <QMessageBox>
#include <QDateTime>
#include <QTcpSocket>
#include <QDebug>
#include <QString>

//Server source code courtesy of Mr. Stephen Schaub from Cps 111 Lab 7 assignment

AwesumServer::AwesumServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AwesumServer)
{
    ui->setupUi(this);
    usrCount = 0;
    connection = true;
    connect(&server, SIGNAL(newConnection()), this, SLOT(clientConnected()));
    if (!server.listen(QHostAddress::Any, 5000)) {
        connection = false;
    }
}

AwesumServer::~AwesumServer()
{
    delete ui;
}
//create log
void AwesumServer::addToLog(QString msg)
{
    QDateTime now = QDateTime::currentDateTime();
    ui->txtLog->appendPlainText(now.toString("hh:mm:ss") + " " + msg);
}
//handle client connection
void AwesumServer::clientConnected()
{
    QTcpSocket *sock = server.nextPendingConnection();
    connect(sock, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(sock, SIGNAL(readyRead()), this, SLOT(dataReceived()));
    ++usrCount;
    ui->lblConnected->setText(QString::number(usrCount));
    addToLog("Client connected.");
}
//handle information received
void AwesumServer::dataReceived()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());

    addToLog("Received data from socket ");
    while (sock->canReadLine()) {
        QString str = sock->readLine().trimmed();

        addToLog("-> " + str);

        sleep(2); // artificial delay

        if (str.startsWith("*USER ")) {
            sock->write("+OK\n");
        } else if (str.startsWith("*PASS ")) {
            if (str.endsWith(" 12345")) {
                sock->write("+OK\n");
            } else {
                sock->write("-ERR\n");
            }
        } else {
            // send data to all connected clients
            for (QObject *obj : server.children()) {
                QTcpSocket *anotherSock = dynamic_cast<QTcpSocket*>(obj);
                if (anotherSock != NULL) {
                    str += "\n";
                    anotherSock->write(str.toLatin1()); //replaces toAscii with toLatin1
                }
            }
        }
    }
}
//handle client disconnection
void AwesumServer::clientDisconnected()
{
    QTcpSocket *sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    --usrCount;
    ui->lblConnected->setText(QString::number(usrCount));
    addToLog("Client disconnected.");
}
//handle server disconnection
void AwesumServer::on_btnDisconnect_clicked()
{
    server.close();
    this->close();
}

#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent){
    config = new Config;
    serverInfo = new ServerInfo;
    connect(serverInfo,SIGNAL(ready()),this,SLOT(start()));
}

void Manager::start(){
    qDebug() << "Server is starting @"<<serverInfo->getIpAdress()<<"@ port"<<config->port();
    listener = new UdpListener(serverInfo->getIpAdress(), config->port());
    connect(listener,SIGNAL(recived(QHostAddress,int,QString)),this,SLOT(reciveMessage(QHostAddress,int,QString)));
}

void Manager::reciveMessage(QHostAddress senderIp, int senderPort, QString message){
    qDebug() << senderIp.toString()<<"@"<<senderPort<<" says: "<<message;
}

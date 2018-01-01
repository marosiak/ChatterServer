#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent){
    sender = new UdpSender;
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
    JsonReader json(message);

    sender->send(senderIp,senderPort, "something..");
    if(json.getType() == "login"){
        if(json.getSize() == 2){
            sender->send(senderIp,senderPort, "GOOD LOGIN");
        } else {
            // bad argument
        }
    }
    if(json.getType() == "register"){
        if(json.getSize() == 2){

        } else {
            // bad argument
        }
    }
    if(json.getType() == "keepSession"){
        if(json.getSize() == 1){

        } else {
            // bad argument
        }
    }
}

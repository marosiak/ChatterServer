#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent){
    config = new Config;
    serverInfo = new ServerInfo;
    connect(serverInfo,SIGNAL(ready()),this,SLOT(start()));
}

void Manager::start(){
    qDebug() << "Server is starting @"<<serverInfo->getIpAdress()<<"@ port"<<config->port();
}

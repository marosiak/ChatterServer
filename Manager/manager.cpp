#include "manager.h"

Manager::Manager(QObject *parent) : QObject(parent){
    serverInfo = new ServerInfo;
    connect(serverInfo,SIGNAL(ready()),this,SLOT(start()));
}

void Manager::start(){
    qDebug() << "Server is starting @"<<serverInfo->getIpAdress();
}

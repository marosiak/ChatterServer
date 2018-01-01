#ifndef MANAGER_H
#define MANAGER_H

#include <QDebug>
#include <QObject>
#include <ServerInfo/serverinfo.h>
#include <Config/config.h>
#include <Network/UdpListener/udplistener.h>
#include <Network/UdpSender/udpsender.h>
#include <Json/JsonReader/jsonreader.h>
#include <Json/JsonGenerator/jsongenerator.h>

class Manager : public QObject{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

private slots:
    void start();
    void reciveMessage(QHostAddress senderIp, int senderPort, QString message);
private:
    ServerInfo* serverInfo;
    Config* config;
    UdpListener* listener;
    UdpSender* sender;
};

#endif // MANAGER_H

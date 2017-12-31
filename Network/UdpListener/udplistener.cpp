#include "udplistener.h"

UdpListener::UdpListener(QString ip, int port) : QObject(parent){
    socket = new QUdpSocket;
    socket->bind(QHostAddress(ip), port);
    connect(socket, SIGNAL(readyRead()), this, SLOT(ready()));
}

void UdpListener::ready(){
    QByteArray buffer;
    buffer.resize(socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    socket->readDatagram(buffer.data(), buffer.size(),
                         &sender;, &senderPort;);
    emit recived(sender, senderPort, buffer);
}

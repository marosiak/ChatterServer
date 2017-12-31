#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include <QObject>
#include <QUdpSocket>
#include <./ServerInfo/serverinfo.h>

class UdpListener : public QObject {
    Q_OBJECT
public:
    UdpListener(QString ip, int port);

signals:
    void recived(QHostAddress senderIp, int senderPort, QString message);
private:
    QUdpSocket* socket;
private slots:
    void ready();
};

#endif // UDPLISTENER_H

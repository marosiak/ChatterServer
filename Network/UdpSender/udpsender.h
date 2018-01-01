#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QObject>
#include <QUdpSocket>

class UdpSender : public QObject{
    Q_OBJECT
public:
    UdpSender();
    void send(QHostAddress ip, quint32 port, QString message);
signals:

private:
    QUdpSocket* socket;
public slots:
};

#endif // UDPSENDER_H

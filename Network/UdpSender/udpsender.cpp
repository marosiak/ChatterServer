#include "udpsender.h"

UdpSender::UdpSender()
{

}

void UdpSender::send(QHostAddress ip, quint32 port, QString message){
    socket->writeDatagram(message.toUtf8(), ip, port);
}

#include "serverinfo.h"

QJsonObject ServerInfo::objectFromString(const QString& in) {
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    if (!doc.isNull()) {
        if (doc.isObject()) {
            obj = doc.object();
        } else {
            qDebug() << "Document is not an object" << endl;
        }
    } else {
        qDebug() << "Invalid JSON...\n" << in << endl;
    }
    return obj;
}

ServerInfo::ServerInfo(QObject *parent) : QObject(parent){
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(recive(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://ip-api.com/json")));
}

void ServerInfo::recive(QNetworkReply *reply){
    QString rep = reply->readAll();
    delete reply;
    QJsonObject obj = objectFromString(rep);
    setIpAdress(obj.value("query").toString());
    setIsp(obj.value("isp").toString());
    setCity(obj.value("city").toString());
    setCountry(obj.value("country").toString());
    emit ready();
}


QString ServerInfo::getCity() const { return m_city; }
QString ServerInfo::getIsp() const { return m_isp; }
QString ServerInfo::getCountry() const { return m_country; }
QString ServerInfo::getIpAdress() const { return m_ipAdress; }
void ServerInfo::setCountry(const QString &country) { m_country = country; }
void ServerInfo::setIpAdress(const QString &ipAdress) { m_ipAdress = ipAdress; }
void ServerInfo::setIsp(const QString &isp) { m_isp = isp; }
void ServerInfo::setCity(const QString &city) { m_city = city; }

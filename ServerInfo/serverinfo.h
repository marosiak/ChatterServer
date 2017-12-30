#ifndef SERVERINFO_H
#define SERVERINFO_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QList>
#include <QString>


class ServerInfo : public QObject{
    Q_OBJECT
public:
    explicit ServerInfo(QObject *parent = nullptr);

    QString getIpAdress() const;
    void setIpAdress(const QString &ipAdress);

    QString getCountry() const;
    void setCountry(const QString &country);

    QString getCity() const;
    void setCity(const QString &city);

    QString getIsp() const;
    void setIsp(const QString &isp);

private:
    QJsonObject objectFromString(const QString& in);
public slots:
    void recive(QNetworkReply *reply);
signals:
    void ready(); // return ready when it's ready to read lol xd
private:
    QNetworkAccessManager* manager;
    QString m_ipAdress;
    QString m_country;
    QString m_city;
    QString m_isp;

};

#endif // SERVERINFO_H

#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>

struct Default {
    int port = 3110;
    int timeout = 5;
    int maxSearchResults = 20;
};

class Config : public QObject{
    Q_OBJECT
public:
    explicit Config(QObject *parent = nullptr);

    int port() const;
    void setPort(int port);

    int timeout() const;
    void setTimeout(int timeout);

    int maxSearchResults() const;
    void setMaxSearchResults(int maxSearchResults);

    Default def;

signals:

public slots:

private:
    QFile* configFile;
    int m_port;
    int m_timeout;
    int m_maxSearchResults;
};

#endif // CONFIG_H

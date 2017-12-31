#include "config.h"

Config::Config(QObject *parent) : QObject(parent){
    configFile = new QFile("config/config.cfg");
    QDir dir("config");

    if (!dir.exists()) {
        dir.mkpath(".");
        configFile->open(QIODevice::ReadWrite);
        // load from template
        QTextStream stream(configFile);
        stream << QString("{\n"
                  "\"port\":\"%1\",\n\r"
                  "\"timeout\": \"%2\",\n\r"
                  "\"maxSearchResults\":\"%3\"\n\r"
                  "}").arg(def.port).arg(def.timeout).arg(def.maxSearchResults);
        configFile->close();
    }

    configFile->open(QIODevice::ReadWrite);
    // read props
    QJsonDocument doc = QJsonDocument::fromJson(QString(configFile->readAll()).toUtf8());
    QJsonValue port = doc.object().value("port");
    QJsonValue timeout = doc.object().value("timeout");
    QJsonValue maxSearchResults = doc.object().value("maxSearchResults");
    if(port.isUndefined()){
        setPort(def.port);
        qDebug() << "[Alert] Cannot load \"port\" value from config.cfg, the value has been set to default value"<<def.port;
    } else {setPort(port.toString().toInt());}

    if(timeout.isUndefined()){
        setTimeout(def.timeout);
        qDebug() << "[Alert] Cannot load \"timeout\" value from config.cfg, the value has been set to default value"<<def.timeout;
    } else {setTimeout(timeout.toString().toInt());}

    if(maxSearchResults.isUndefined()){
        setMaxSearchResults(def.maxSearchResults);
        qDebug() << "[Alert] Cannot load \"maxSearchResults\" value from config.cfg, the value has been set to default value"<<def.maxSearchResults;
    } else {setMaxSearchResults(maxSearchResults.toString().toInt());}
    configFile->close();
}

int Config::port() const{
    return m_port;
}

void Config::setPort(int port){
    m_port = port;
}

int Config::timeout() const{
    return m_timeout;
}

void Config::setTimeout(int timeout){
    m_timeout = timeout;
}

int Config::maxSearchResults() const{
    return m_maxSearchResults;
}

void Config::setMaxSearchResults(int maxSearchResults){
    m_maxSearchResults = maxSearchResults;
}

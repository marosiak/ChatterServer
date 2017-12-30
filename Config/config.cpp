#include "config.h"

Config::Config(QObject *parent) : QObject(parent){
    configFile = new QFile("config/config.cfg");
    QDir dir("config");

    if (!dir.exists()) {
        dir.mkpath(".");
        configFile->open(QIODevice::ReadWrite);
        // load from template
        QTextStream stream(configFile);
        stream << "{\n"
                  "\"port\":\"3110\",\n\r"
                  "\"timeout\": \"5\",\n\r"
                  "\"maxSearchResults\":\"20\"\n\r"
                  "}";
        configFile->close();
    }

    configFile->open(QIODevice::ReadWrite);
    // read props
    QJsonDocument doc = QJsonDocument::fromJson(QString(configFile->readAll()).toUtf8());
    setPort(doc.object().value("port").toString().toInt());
    setTimeout(doc.object().value("timeout").toString().toInt());
    setMaxSearchResults(doc.object().value("maxSearchResults").toString().toInt());
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

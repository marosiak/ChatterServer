#ifndef MANAGER_H
#define MANAGER_H

#include <QDebug>
#include <QObject>
#include <ServerInfo/serverinfo.h>
#include <Config/config.h>

class Manager : public QObject{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

private slots:
    void start();
private:
    ServerInfo* serverInfo;
    Config* config;
};

#endif // MANAGER_H

#ifndef MANAGER_H
#define MANAGER_H

#include <QDebug>
#include <QObject>
#include <ServerInfo/serverinfo.h>

class Manager : public QObject{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

private slots:
    void start();
private:
    ServerInfo* serverInfo;
};

#endif // MANAGER_H

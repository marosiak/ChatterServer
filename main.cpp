#include <QCoreApplication>
#include <Manager/manager.h>
#include <Json/JsonReader/jsonreader.h>
#include <Json/JsonGenerator/jsongenerator.h>

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);
    Manager manager;
    return a.exec();
}

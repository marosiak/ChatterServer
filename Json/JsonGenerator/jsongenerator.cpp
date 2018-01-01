#include "jsongenerator.h"

JsonGenerator::JsonGenerator(QString type, QStringList args){
    QString values;
    for(int i=0; i<args.size(); i++){
        if (i != args.size()-1){
            values.append(QString("\"%1\",").arg(args[i]));
        } else {
            values.append(QString("\"%1\"").arg(args[i]));
        }
    }
    m_output = QString("{\"type\":\"%1\",\"values\":[%2]}").arg(type).arg(values);
}

QString JsonGenerator::output() const {
    return m_output;
}

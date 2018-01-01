#ifndef JSONGENERATOR_H
#define JSONGENERATOR_H

#include <QObject>
#include <QStringList>
class JsonGenerator : public QObject {
    Q_OBJECT
public:
    JsonGenerator(QString type, QStringList args);

    QString output() const;

signals:
private:
    QString m_output;
public slots:
};

#endif // JSONGENERATOR_H

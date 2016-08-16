#ifndef QGLOBALS_H
#define QGLOBALS_H

#include <QObject>

class qGlobals : public QObject
{
    Q_OBJECT
public:
    explicit qGlobals(QObject *parent = 0);
    static QString jsonFile;

signals:

public slots:
};

#endif // QGLOBALS_H

#ifndef QJSONPARSING_H
#define QJSONPARSING_H
#include "QMap"
#include "qJsonObject.h"


class qJsonParsing
{
public:
    qJsonParsing();
        QMap<QString,QString> setMap(QString key);
        QMap<QString,QString> setMapArrsy(QString key);
        private:
            qJsonObject jsonUtil;
};

#endif // QJSONPARSING_H

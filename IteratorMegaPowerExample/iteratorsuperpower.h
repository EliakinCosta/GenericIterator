#ifndef ITERATORSUPERPOWER_H
#define ITERATORSUPERPOWER_H

#include <iiterator.h>
#include <QList>

class QMetaObject;

class IteratorSuperPower: public IIterator
{
public:
    IteratorSuperPower(QList<QObject *> *m_listAlunos, QString property, QString operador, QString value);
    virtual ~IteratorSuperPower();
    virtual bool hasNext() const;
    virtual QObject next();
private:
    QList<QObject *> *m_listAlunos;
    QString m_property;
    QString m_operator;
    QString m_value;
    int m_propertyIndex;
};

#endif // ITERATORSUPERPOWER_H

#ifndef ITERATORMEGARPOWER_H
#define ITERATORMEGARPOWER_H

#include <QObject>
#include <QMetaProperty>
#include <QMetaObject>
#include <aluno.h>
#include <QtAlgorithms>
#include <QDebug>
#include <QList>

template<class typeCollection>
class IteratorMegarPower
{
public:
    IteratorMegarPower(typeCollection *collection, QString propertyName, QString operation, QString value) :
        m_collection(collection),
        m_propertyName(propertyName),
        m_operation(operation),
        m_value(value),
        m_next(0)
    {
        this->m_iterator = this->m_collection->begin();
    }

    virtual ~IteratorMegarPower()
    {
        qDeleteAll(this->m_collection->begin(), this->m_collection->end());
        this->m_collection->clear();
        delete this->m_next;
    }

    bool hasNext()
    {
        while(this->m_iterator != this->m_collection->end())
        {
            QString temp = (*m_iterator)->property(this->m_propertyName.toLatin1()).toString();
            if (m_operation == QStringLiteral("=="))
            {
                if(temp.compare(m_value)==0){
                    m_next = *m_iterator;
                    ++m_iterator;
                    return true;
                }
            }
            else if(this->m_operation.compare("<")==0)
            {
                if(temp.compare(this->m_value)<0){
                    this->m_next = *this->m_iterator;
                    ++this->m_iterator;
                    return true;
                }
            }
            else if(this->m_operation.compare(">")==0)
            {
                if(temp.compare(this->m_value)>0){
                    this->m_next = *this->m_iterator;
                    ++this->m_iterator;
                    return true;
                }
            }
            ++this->m_iterator;
        }
        return false;
    }

    QObject *next()
    {
        return this->m_next;
    }
private:
    typeCollection *m_collection;
    QString m_propertyName;
    QString m_operation;
    QString m_value;
    typename typeCollection::iterator m_iterator;
    QObject *m_next;
};

#endif // ITERATORMEGARPOWER_H

#ifndef ITERATORMEGARPOWER_H
#define ITERATORMEGARPOWER_H

#include <QObject>
#include <QMetaProperty>
#include <QMetaObject>
#include <QDebug>
#include <QList>
#include <aluno.h>
#include <QtAlgorithms>

template<typename typeObject>
class IteratorMegarPower
{
    typedef char(Aluno::*FPtr)();
public:
    IteratorMegarPower(QList<typeObject*> *collection, FPtr ptr, QString propertyName, QString operation, QString value):
        m_collection(collection),
        m_propertyName(propertyName),
        m_operation(operation),
        m_value(value),
        m_ptr(ptr),
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
            if(this->m_operation.compare("==")==0)
            {
                if(QString(((*this->m_iterator)->*this->m_ptr)()).compare(this->m_value)==0)
                {
                    this->m_next = *this->m_iterator;
                    ++this->m_iterator;
                    return true;
                }
            }
            ++this->m_iterator;
        }
        return false;
    }

    typeObject *next()
    {
        return this->m_next;
    }
private:
    QList<typeObject*> *m_collection;
    QString m_propertyName;
    QString m_operation;
    QString m_value;
    FPtr m_ptr;
    typename QList<typeObject *>::iterator m_iterator;
    typeObject *m_next;
};

#endif // ITERATORMEGARPOWER_H

#include "iteratorsuperpower.h"
#include <aluno.h>
#include <QtAlgorithms>
#include <QList>
#include <QObject>
#include <QMetaObject>
#include <QMetaProperty>

IteratorSuperPower::IteratorSuperPower(QList<QObject *> *listAlunos, QString property,
                                       QString operador, QString value): m_listAlunos(listAlunos),
                                                                         m_property(property),
                                                                         m_operator(operador),
                                                                         m_value(value)
{
    foreach (QObject *item, *m_listAlunos)
    {
        const QMetaObject* metaObject = item->metaObject();
        for(int i = metaObject->propertyOffset(); i < metaObject->propertyCount(); ++i)
        {
            if(QString::fromLatin1(metaObject->property(i).name())==this->m_property)
                this->m_propertyIndex = i;
        }
    }
}

IteratorSuperPower::~IteratorSuperPower()
{
    delete m_listAlunos;
}

bool IteratorSuperPower::hasNext() const
{

}

QObject IteratorSuperPower::next()
{

}

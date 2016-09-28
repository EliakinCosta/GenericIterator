#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QScopedArrayPointer>

#include "aluno.h"
#include "iteratormegarpower.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QScopedPointer<QList<QObject *>> listaAlunos(new QList<QObject *>());
    QObject *eliakin = new Aluno('M', "Eliakin");
    QObject *caio = new Aluno('M', "Caio");
    QObject *jamile= new Aluno('F', "Jamile");

    listaAlunos.data()->append(eliakin);
    listaAlunos.data()->append(caio);
    listaAlunos.data()->append(jamile);

    IteratorMegarPower<QList<QObject *>> iterator(listaAlunos.data(), QStringLiteral("sexo"), QStringLiteral("=="), QStringLiteral("F"));


    while(iterator.hasNext())
        qDebug() << iterator.next()->property("nome").toString();
}

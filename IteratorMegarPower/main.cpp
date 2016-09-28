#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>

#include "aluno.h"
#include "iteratormegarpower.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QObject *> *listaAlunos = new QList<QObject *>();
    QObject *eliakin = new Aluno('M', "Eliakin");
    QObject *caio = new Aluno('M', "Caio");
    QObject *jamile= new Aluno('F', "Jamile");

    listaAlunos->append(eliakin);
    listaAlunos->append(caio);
    listaAlunos->append(jamile);

    IteratorMegarPower<QList<QObject *>> iterator(listaAlunos, QStringLiteral("sexo"), QStringLiteral("=="), QStringLiteral("F"));


    while(iterator.hasNext())
        qDebug() << iterator.next()->property("nome").toString();

    qDeleteAll(listaAlunos->cbegin(), listaAlunos->cend());
    delete listaAlunos;
}

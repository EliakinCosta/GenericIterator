#include <QCoreApplication>
#include <aluno.h>
#include <iteratormegarpower.h>
#include <QList>
#include <QString>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>

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

    IteratorMegarPower<QList<QObject *>> iterator(listaAlunos, QString("sexo"), QString(">"), QString("F"));


    while(iterator.hasNext())
    {
        QString nome;
        QMetaObject::invokeMethod(iterator.next(), "nome", Qt::DirectConnection,  Q_RETURN_ARG(QString, nome));
        qDebug() << nome;
    }

    delete listaAlunos;

    return a.exec();
}

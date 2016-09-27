#include <QCoreApplication>
#include <aluno.h>
#include <iteratormegarpower.h>
#include <QList>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<Aluno *> *listaAlunos = new QList<Aluno *>();
    Aluno *eliakin = new Aluno('M', "Eliakin");
    Aluno *caio = new Aluno('M', "Caio");
    Aluno *jamile= new Aluno('F', "Jamile");

    listaAlunos->append(eliakin);
    listaAlunos->append(caio);
    listaAlunos->append(jamile);

    IteratorMegarPower<Aluno> iterator(listaAlunos, &Aluno::sexo, QString("sexo"), QString("=="), QString("M"));


    while(iterator.hasNext())
    {
        qDebug() << iterator.next()->nome();
    }

    delete listaAlunos;

    return a.exec();
}

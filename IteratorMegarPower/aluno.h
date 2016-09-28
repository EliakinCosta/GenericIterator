#ifndef ALUNO_H
#define ALUNO_H

#include <QObject>

class Aluno: public QObject
{
    Q_OBJECT

    Q_PROPERTY(char sexo READ sexo)
    Q_PROPERTY(QString nome READ nome)

public:
    Aluno(char sexo, QString nome, QObject *parent=0);
    virtual ~Aluno(){}
    Q_INVOKABLE char sexo();
    Q_INVOKABLE QString nome();

private:
    char m_sexo;
    QString m_nome;
};

#endif // ALUNO_H

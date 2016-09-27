#ifndef ALUNO_H
#define ALUNO_H

#include <QObject>

class Aluno: public QObject
{
    Q_OBJECT
public:
    Aluno(char sexo, QString nome, QObject *parent=0);
    virtual ~Aluno(){}
    char sexo();
    QString nome();
private:
    char m_sexo;
    QString m_nome;
};

#endif // ALUNO_H

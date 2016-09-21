#ifndef ALUNO_H
#define ALUNO_H

#include <QString>
#include <QObject>

class Aluno: public QObject
{
    Q_OBJECT
public:
    Aluno(QString nome, char sexo, QObject *parent = 0);
    virtual ~Aluno(){}
    QString nome() const;
    char sexo() const;
private:
        QString m_nome;
        char m_sexo;
};

#endif // ALUNO_H

#include "aluno.h"
#include <QObject>

Aluno::Aluno(char sexo,  QString nome, QObject *parent):QObject(parent),
                                                        m_sexo(sexo),
                                                        m_nome(nome)
{

}


char Aluno::sexo()
{
    return m_sexo;
}

QString Aluno::nome()
{
    return m_nome;
}


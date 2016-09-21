#include "aluno.h"
#include <QString>

Aluno::Aluno(QString nome, char sexo, QObject *parent):m_nome(nome),
                                                       m_sexo(sexo),
                                                       QObject(parent)
{

}

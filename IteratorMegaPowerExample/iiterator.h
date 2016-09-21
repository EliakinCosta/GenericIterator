#ifndef IITERATOR_H
#define IITERATOR_H

class Aluno;
class QObject;

class IIterator
{
public:
    IIterator();
    virtual ~IIterator(){}
    virtual bool hasNext() const = 0;
    virtual QObject next() = 0;
};

#endif // IITERATOR_H

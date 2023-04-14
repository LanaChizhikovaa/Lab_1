#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H

#include "EStackExeption.h"

//класс исключений, связанных с извлечением из пустого стека (наследник класса EStackException)
class EStackEmpty : public EStackException
{
public:

    EStackEmpty() : EStackException ("Stack is empty") //конструктор по умолчанию, использующий конструктор базового класса
    {}

};
#endif // ESTACKEMPTY_H

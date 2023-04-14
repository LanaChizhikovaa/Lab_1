#ifndef ESTACKEXEPTION_H
#define ESTACKEXEPTION_H

#include <string.h>

//класс исключений, связанных с работой стека
class EStackException
{
  public:

    EStackException (const char* msg) //конструктор с аргументом-строкой
    {
        message = new char[strlen(msg)+1];
        strcpy_s(message, msg);
    }

    ~EStackException()  //деструктор
    {
        delete message;
    }

    const char *what()  //метод, возвращающий диагностическое сообщение
    {
        return message;
    }

private:
    char* message; //содержит сообщение об ошибке
};


#endif // ESTACKEXEPTION_H

#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include "Person.h"
#include "Stack.h"
#include <fstream>


//класс, хранящий личности в стеке, реализован на основе паттерна Singleton (одиночка)
class PersonKeeper
{
public:
    static PersonKeeper& Instance();//создание и хранение единственного экземпляра класса
    void readPersons(std::ifstream&); //метод, считывающий дичности из файлового потока в стек
    void writePersons (std::ofstream&); //метод, записывающий дичности из стека в файл

private:
    PersonKeeper(); //конструктор по умолчанию
    ~PersonKeeper(); //деструктор
    PersonKeeper(PersonKeeper const&); //конструктор копирования
    PersonKeeper& operator= (PersonKeeper const&);//оператор присвоения

    Stack<Person> nameStack_; //стек личностей (объектов класса Person)
};

#endif // PERSONKEEPER_H

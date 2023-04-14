

#include <string.h>
#include <iostream>

using namespace std;

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
    void writePersons(std::ofstream&); //метод, записывающий дичности из стека в файл

private:
    PersonKeeper(); //конструктор по умолчанию
    ~PersonKeeper(); //деструктор
    PersonKeeper(PersonKeeper const&); //конструктор копирования
    PersonKeeper& operator= (PersonKeeper const&);//оператор присвоения

    Stack<Person> nameStack_; //стек личностей (объектов класса Person)
};

#endif // PERSONKEEPER_H


//Тестирование 2 части лабораторной
int main(int argc, char *argv[])
{
    while (1)
    {
        cout << "Read file or write to file? r/w: ";
        string rw;
        getline (cin, rw); //записываем значение rw с клавиатуры 
        if (rw == "r") {    //считываем из файла в PersonKeeper
            string filename;
            cout << "Reading file name (path): ";
            getline (cin, filename);
            ifstream instr (filename);
            PersonKeeper::Instance().readPersons(instr);//обращаемся к экземпляру класса-одиночки через Instance()
            instr.close();
        }
        else if (rw == "w") {//записываем из PersonKeeper в файл
            string filename;
            cout << "Writing file name (path): ";
            getline (cin, filename);
            ofstream outstr (filename);
            PersonKeeper::Instance().writePersons(outstr);
            outstr.close();
        }
    }

}

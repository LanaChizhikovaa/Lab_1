#include "Person.h"

Person::Person (std::string lastName, std::string firstName, std::string patronymic)
{
    //устанавливаем член-данные аргументами конструкора
    lastName_ = lastName;
    firstName_ = firstName;
    patronymic_ = patronymic;
}

 Person::Person(const Person& p)
 {
     //устанавливаем член-данные данными существующего экземпляра класса
     firstName_ = p.firstName_;
     lastName_ = p.lastName_;
     patronymic_ = p.patronymic_;
     key_ = p.key_;
 }

void Person::setFirstame(const std::string& firstName)
{
    firstName_ = firstName; //устанавливаем имя
}

void Person::setLastName(const std::string& lastName)
{
    lastName_ = lastName; //устанавливаем фамилию
}

void Person::setPatronymic(const std::string& patronymic)
{
    patronymic_ = patronymic; //устанавливаем отчество
}


#ifndef PERSON_H
#define PERSON_H

#include <string>

//класс, хранящий личность
class Person
{
public:
    Person (std::string lastName = "", std::string firstName = "", std::string patronymic = ""); //конструктор создаёт объект класа по "фамилия", "имя", "отчество" (отчества нет - пустая строка)
    Person(const Person&);//конструктор копирования

    void setLastName(const std::string&); //метод, устанавливающий фамилию личности
    void setFirstame(const std::string&); //метод, устанавливающий имя личности
    void setPatronymic(const std::string&); //метод, устанавливающий отчество личности
    const std::string& getLastName() const { return lastName_; } //метод возвращающий фамилию личности
    const std::string& getFirstName() const { return firstName_; } //метод возвращающий имя личности
    const std::string& getPatronymic() const { return patronymic_; } //метод возвращающий отчество личности

private:
    long key_; //ключ
    std::string lastName_; //содержит фамилию
    std::string firstName_; //содержит имя
    std::string patronymic_; //содержит отчество
};

#endif // PERSON_H

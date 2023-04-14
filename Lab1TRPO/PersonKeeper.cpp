#include "PersonKeeper.h"
#include <cstring>
#include <vector>
#include <sstream>

PersonKeeper::PersonKeeper() {};

PersonKeeper::~PersonKeeper() {};

PersonKeeper& PersonKeeper::Instance()
{
    static PersonKeeper instance_; //создаем (или возвращаем) экземпляр PersonKeeper
    return instance_;
}


void PersonKeeper::readPersons(std::ifstream& file)
{ 
    if(!(file.is_open())) { // проверка на открытие файла
        throw "Error: CANNOT OPEN THE FILE! (READING)";
    }
    else
    {
        std::string string; 
        while(getline(file, string)) //читаем файл построчнo, каждую строку файла записываем в str
        {
            //разделяем str на слова, подсчитывая их количество
            std::vector <std::string> stringVector;
            std::string word;
            std::stringstream s(string);
            int wordCount = 0;
            while (s >> word){
                stringVector.push_back(word);
                wordCount++;
            }

           if (wordCount == 3)//если в строке 3 слова (отчество есть)
           nameStack_.push(Person (stringVector[0], stringVector[1], stringVector[2]));//кладем в стек экземпляр класса Person
            else if (wordCount == 2)//если в строке 2 слова
            nameStack_.push(Person (stringVector[0], stringVector[1])); //кладем в стек экземпляр класса Person без отчества
           //Строки, состоящие из одного слова будут проигнорированы
        }
        file.close();
    }
}

void PersonKeeper::writePersons(std::ofstream& file)
{
        Person person;
        while (nameStack_.getSize() != 0){    //пока стек не пуст (размерность ненулевая)
        person = nameStack_.pop();//достаем из вершины стека персону
        file << person.getLastName() << " " << person.getFirstName() << " " << person.getPatronymic() << "\n";  //записываем в файл ФИО персоны
        }
        file.close();

}

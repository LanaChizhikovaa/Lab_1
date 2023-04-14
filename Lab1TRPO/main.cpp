

#include <string.h>
#include <iostream>
#include <PersonKeeper.h>
using namespace std;




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

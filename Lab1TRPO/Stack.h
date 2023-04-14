#ifndef STACK_H
#define STACK_H

#include "EStackEmpty.h"

//класс стек
template <class T> class Stack
{
public:

    void push(const T& value);  //метод, помещающий объект в стек
    const T pop();  //метод, извлекающий объект из стека
    int getSize(); //получение размерности стека
    void clear(); //очистка стека
    ~Stack();//деструктор

private:
    //стуктура, описывающая элемент стека
    struct Node
    {
        const T value; //хранимое значение элемета стека
        Node* prev = nullptr; //указатель на следующий элемент стека
    };

    Node* top_ = nullptr; //указатель на вершину стека
    int size_  = 0; //размерность стека
};

template <class T> void Stack<T>::push(const T &val)
{
    Node* newNode = new Node {val, top_};//создаем указатель на новый элемент стэка
    top_ = newNode;
    size_ ++; //увеличиваем размерность
}

template <class T> const T Stack<T>::pop()
{
    //выкидываем исключение, связанное с извлечением из пустого стека
    if (top_ == nullptr){
        throw EStackEmpty();
    }

    const T val = top_->value; //извлекаем значение с вершины
    Node* temp = top_; //времнный указатель, чтоб можно было сдвинуть
    top_ = top_->prev; //смещаем указатель на вершину
    delete temp; //удаляем старую вершину
    size_ --;
    return val; //значение бывшего верхнего узла
}

template <class T> int Stack<T>::getSize()
{
    return size_;
}

template <class T> void Stack<T>::clear()
{

    while (top_ !=nullptr){  // пока стек не станет пуст
        Node* temp = top_;
        top_ = top_->prev;    //смещаем указатель вершины вниз
        delete temp;    //удаляем старую вершину
    }

        size_ = 0; //обнуляем размер
        top_ = nullptr;
}

template <class T> Stack<T>::~Stack<T>()
{
    clear();
};

#endif // STACK_H

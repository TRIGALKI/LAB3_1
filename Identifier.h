#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include "string.h"
#include <iostream>
#include <list>
#include <algorithm>
template <class T>
class Identifier
{
public:
    // Задаётся имя переменной при создании
    Identifier(const T &name):
    m_name(name)
    {
        counter=1;
    }
    Identifier():
     m_name()
    {
        counter=0;
    }
    ~Identifier()
    {
    }

public:
    // Получается имя переменной
    T getName() const
    {
        return m_name;
    }
    int getCounter() const
    {
        return counter;
    }
    void changeCounter(int newCount)
    {
        counter=newCount;
    }
private:
    T m_name;
    int counter;
};

template <class T>// Необходимо для поиска переменной по имени
bool operator==(const Identifier<T> &left, const Identifier<T> &right)
{
 return left.getName() == right.getName();
}

// Функция, вычисляющая хэш
// Принимает идентификатор, хэш которого надо посчитать
// Возвращает вычисленный хэш
template <class T>
unsigned hash(const Identifier<T> &id)
{
    std::hash<T> hash;
    return hash(id.getName());
}



#endif // IDENTIFIER_H

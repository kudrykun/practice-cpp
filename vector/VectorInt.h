//
// Created by kudry on 23.05.17.
//

#ifndef VECTOR_VECTORINT_H
#define VECTOR_VECTORINT_H

class VectorInt{
public:
    VectorInt();

    ~VectorInt();

    unsigned int size(); //возвращает количество элементов в векторе

    unsigned int capacity(); //возвращает текущую емкость вектора
    bool isEmpty(); //возвращает true или false, в зависимости от того, есть ли элементы в векторе или нет

    int at(unsigned int); //возвращает элемент под индексом i

    void push(int); //добавляет следующий элемент в вектор

    void insert(int, int); //вставляет элемент в определенный индекс

    void prepend(int); //вставляет элемент в нулевой индекс

    int pop(); //удаляет элемент из конца вектора, возвращает его значение

    void delete_item(int); //удаляет элемент по указанному индексу

    void remove(int); //получает значение, удаляет все элементы с этим значением

    int find(int); //получачет значение, вовзращает индекс первого элемента с этим значением

private:
    unsigned int vector_size; //количество элементов
    unsigned int vector_capacity; // количество элементов, которые можно вместить.
    int *array; // под динамический массив.
    const double decreaseFactor = 0.25;//отношение размера size к capacity, при котором произойдет уменьшение ёмкости

    void increaseSize(); // увеличивает ёмкость вектора
    void decreaseSize(); // уменьшает ёмкость вектора
    void resise(); //решает, уменьшить или увеличить память, и делает это
};

#endif //VECTOR_VECTORINT_H

//
// Created by kudry on 23.05.17.
//
//
// Created by kudry on 23.05.17.
//

#include <iostream>
#include "Vector.h"

using namespace std;

//PUBLIC

Vector::Vector() {
    array = new int[1];
    vector_size = 0;
    vector_capacity = 1; // начальная ёмкость - 1 элемент
    cout << "LOG " << "Сработал конструктор без аргументов" << endl;
}

Vector::~Vector() {
    delete[] array;
    cout << "LOG " << "Сработал деструктор" << endl;
}

unsigned int Vector::size() { //возвращает количество элементов в векторе
    return vector_size;
}

unsigned int Vector::capacity() { //возвращает текущую емкость вектора
    return vector_capacity;
}

bool Vector::isEmpty() { //возвращает true или false, в зависимости от того, есть ли элементы в векторе или нет
    return !(bool) vector_size;
}

int Vector::at(unsigned int i) { //возвращает элемент под индексом i
    //TODO Добавь исключения
    return array[i];
}

void Vector::push(int item) { //добавляет следующий элемент в вектор
    array[size()] = item; // присваиваем элементу значение
    vector_size++; // увеличиваем размер
    resise();
    return;
}

void Vector::insert(int index, int item) { //вставляет элемент в определенный индекс
    if (!size()) {// если массив не пуст, то просто пушим элемент
        push(item);
    } else
        vector_size++;
    for (int i = vector_size - 1; i > index; i--)
        array[i] = array[i - 1];

    resise();
    return;
}

void Vector::prepend(int item) { //вставляет элемент в нулевой индекс
    insert(0, item);
    resise();
    return;
}

int Vector::pop() { //удаляет элемент из конца вектора, возвращает его значение
    int result = array[size() - 1]; //сохраняем значение последнего элемента вектора
    array[vector_size - 1] = 0; //обнуляем его в векторе
    vector_size--;
    resise();
    return result;
}

void Vector::delete_item(int index) { //удаляет элемент по указанному индексу
    /*[0,1,2,3,4,5]*/
    for (int i = index; i < vector_size - 1; i++)
        array[i] = array[i + 1];
    vector_size--;
    resise();
    return;
}

void Vector::remove(int item) { //получает значение, удаляет все элементы с этим значением
    for (int i = 0; i < vector_size; i++) {
        int buff = at(i);
        if (item == buff) {
            delete_item(i);
            i -= 1;
        }
    }
    resise();
    return;
}

int Vector::find(int item) { //получачет значение, вовзращает индекс первого элемента с этим значением
    for (int i = 0; i < vector_size; i++)
        if (item == at(i))
            return i;
    return -1;
}

//PRIVATE
void Vector::increaseSize() { // увеличивает ёмкость вектора в 2 раза
    int *buffArray = new int[capacity()];

    for (int i = 0; i < capacity(); i++) //копируем значение из исходного массива
        buffArray[i] = array[i];

    delete[]array;  //очищаем память из под исходного массива
    array = new int[capacity() * 2]; //выделяем удвоенную память исходному массиву

    for (int i = 0; i < capacity(); i++) //копируем значения из временного массива
        array[i] = buffArray[i];

    vector_capacity *= 2;

    delete[]buffArray;

    return;
}

void Vector::decreaseSize() { // уменьшает ёмкость вектора вдвое
    int *buffArray = new int[size()];
    for (int i = 0; i < size(); i++) //копируем значение из исходного массива
        buffArray[i] = array[i];

    delete[]array;  //очищаем память из под исходного массива
    array = new int[capacity() / 2]; //выделяем уменьшенную память исходному массиву
    for (int i = 0; i < capacity() / 2; i++) //ОБНУЛЯЕМ МАССИВ
        array[i] = 0;

    for (int i = 0; i < size(); i++) //копируем значения из временного массива
        array[i] = buffArray[i];

    vector_capacity /= 2;

    delete[]buffArray;
    return;
}

void Vector::resise() { //решает, уменьшить или увеличить память, и делает это
    if (size() == capacity()) {
        increaseSize();
        cout << "LOG изменение размера вектора: capacity = " << capacity() << endl;
    } else if (double(size()) / double(capacity()) <= decreaseFactor) {
        decreaseSize();
        cout << "LOG изменение размера вектора: capacity = " << capacity() << endl;
    }
    return;
}
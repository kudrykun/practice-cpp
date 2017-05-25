//
// Created by kudry on 23.05.17.
//
//
// Created by kudry on 23.05.17.
//

#include <iostream>
#include "VectorInt.h"
using namespace std;


//PRIVATE
void VectorInt::increaseSize(){ // увеличивает ёмкость вектора в 2 раза
    int *buffArray = new int[capacity()];

    for(int i = 0; i < capacity();i++) //копируем значение из исходного массива
        buffArray[i] = array[i];

    delete []array;  //очищаем память из под исходного массива
    array = new int[capacity()*2]; //выделяем удвоенную память исходному массиву

    for(int i = 0; i < capacity(); i++) //копируем значения из временного массива
        array[i] = buffArray[i];

    vector_capacity *= 2;

    delete []buffArray;

    return;
}

void VectorInt::decreaseSize() { // уменьшает ёмкость вектора вдвое
    int *buffArray = new int[size()];
    for(int i = 0; i < size();i++) //копируем значение из исходного массива
        buffArray[i] = array[i];

    delete []array;  //очищаем память из под исходного массива
    array = new int[capacity()/2]; //выделяем уменьшенную память исходному массиву
    for(int i = 0; i < capacity()/2; i++) //ОБНУЛЯЕМ МАССИВ
        array[i] = 0;

    for(int i = 0; i < size(); i++) //копируем значения из временного массива
        array[i] = buffArray[i];

    vector_capacity /= 2;

    delete []buffArray;
    return;
}

void VectorInt::resise() { //решает, уменьшить или увеличить память, и делает это
    if(size() == capacity()) {
        increaseSize();
        cout << "LOG изменение размера вектора: capacity = " << capacity() << endl;
    }else
        if(double(size())/ double(capacity()) <= decreaseFactor) {
            decreaseSize();
            cout << "LOG изменение размера вектора: capacity = " << capacity() << endl;
        }
    return;
}


//PUBLIC
VectorInt::VectorInt(){
    array = new int[16];
    vector_size = 0;
    vector_capacity = 1; // начальная ёмкость - 1 элемент
    cout << "LOG " << "Сработал конструктор" << endl;
}

VectorInt::~VectorInt(){
    delete [] array;
    cout << "LOG " << "Сработал деструктор" << endl;
}
unsigned int VectorInt::size(){ //возвращает количество элементов в векторе
    return vector_size;
}

unsigned int VectorInt::capacity(){ //возвращает текущую емкость вектора
    return vector_capacity;
}

bool VectorInt::isEmpty(){ //возвращает true или false, в зависимости от того, есть ли элементы в векторе или нет
    return !(bool) vector_size;
}

int VectorInt::at(unsigned int i){ //возвращает элемент под индексом i
    //TODO Добавь исключения
    return *(array + i);
}

void VectorInt::push(int item){ //добавляет следующий элемент в вектор
    *(array + vector_size) = item; // присваиваем элементу значение
    vector_size++; // увеличиваем размер
    resise();
    return;
}

void VectorInt::insert(int index, int item){ //вставляет элемент в определенный индекс
    if (!isEmpty()){
        int *buff_arr = new int[vector_size]; //создаем временный массив
        for(int i = index; i < vector_size; i++) //копируем в него, все элементы от index, включая его
            *(buff_arr + i - index) = *(array + i);
        *(array + index) = item;//делаем значение элемента c index равным item
        vector_size++;
        for(int i = index+1; i < vector_size; i++) { //копируем в исходный массив после index все элементы buff
            *(array + i) = *(buff_arr + i - index - 1);
        }
        delete [] buff_arr;
    }else
        push(item); // если массив не пуст, то просто пушим элемент
    resise();
    return;
}

void VectorInt::prepend(int item){ //вставляет элемент в нулевой индекс
    insert(0,item);
    resise();
    return;
}

int VectorInt::pop() { //удаляет элемент из конца вектора, возвращает его значение
    int result = *(array + vector_size - 1); //сохраняем значение последнего элемента вектора
    *(array + vector_size - 1) = 0; //обнуляем его в векторе
    vector_size--;
    resise();
    return  result;
}

void VectorInt::delete_item(int index) { //удаляет элемент по указанному индексу
    /*[0,1,2,3,4,5]*/
    for(int i = index; i < vector_size-1; i++)
        *(array + i) = *(array + i + 1);
    vector_size--;
    resise();
    return;
}

void VectorInt::remove(int item) { //получает значение, удаляет все элементы с этим значением
    for(int i = 0; i < vector_size; i++) {
        int buff = at(i);
        if (item == buff) {
            delete_item(i);
            i -= 1;
        }
    }
    resise();
    return;
}

int VectorInt::find(int item) { //получачет значение, вовзращает индекс первого элемента с этим значением
    for(int i = 0; i < vector_size; i++)
        if(item == at(i))
            return i;
    return -1;
}
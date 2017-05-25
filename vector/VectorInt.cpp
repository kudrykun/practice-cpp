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
void VectorInt::resize(int new_capacity) { // задает новую ёмкость для вектора
    if(capacity() == new_capacity)
        return;
    else
        if(capacity() < new_capacity)

        else

    return;
}

//PUBLIC
VectorInt::VectorInt(){
    array = new int[16];
    vector_size = 0;
    vector_capacity = 16; // начальная ёмкость - 16 элементов
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
    return;
}

void VectorInt::prepend(int item){ //вставляет элемент в нулевой индекс
    insert(0,item);
    return;
}

int VectorInt::pop() { //удаляет элемент из конца вектора, возвращает его значение
    int result = *(array + vector_size - 1); //сохраняем значение последнего элемента вектора
    *(array + vector_size - 1) = 0; //обнуляем его в векторе
    vector_size--;
    return  result;
}

void VectorInt::delete_item(int index) { //удаляет элемент по указанному индексу
    /*[0,1,2,3,4,5]*/
    for(int i = index; i < vector_size-1; i++)
        *(array + i) = *(array + i + 1);
    vector_size--;
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
    return;
}

int VectorInt::find(int item) { //получачет значение, вовзращает индекс первого элемента с этим значением
    for(int i = 0; i < vector_size; i++)
        if(item == at(i))
            return i;
    return -1;
}
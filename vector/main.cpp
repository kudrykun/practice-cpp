#include <iostream>
#include "VectorInt.h"

using namespace std;

int main(){
    VectorInt vector1;

    cout << "START. Вывод элементов вектора : ";
    for (int i = 0; i < vector1.capacity(); i++)
        cout << vector1.at(i) << " ";
    cout << "   " << "size = " << vector1.size() << " capacity = " << vector1.capacity() << endl;


    for(int i = 0; i < 15; i++) {
        cout << "Вставка значения: value = " << i+1 << endl;
        vector1.push(i + 1);
        cout << "Вывод элементов вектора : ";
        for (int j = 0; j < vector1.capacity(); j++)
            cout << vector1.at(j) << " ";
        cout << "   " << "size = " << vector1.size() << " capacity = " << vector1.capacity() << endl;
    }

    cout << endl << endl << "Начинаем попить элементы" << endl << endl;

    for(int i = 0; i < 15; i++) {
        cout << "Извлечение последнего элемента" << endl;
        vector1.pop();
        cout << "Вывод элементов вектора : ";
        for (int j = 0; j < vector1.capacity(); j++)
            cout << vector1.at(j) << " ";
        cout << "   " << "size = " << vector1.size() << " capacity = " << vector1.capacity() << endl;
    }
    return 0;
}
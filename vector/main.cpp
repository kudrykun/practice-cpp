#include <iostream>
#include "VectorInt.h"

using namespace std;

void fillVector(VectorInt &v,int quantity){
    for (int i = 0; i < quantity; i++)
        v.push(i);
    return;
}

void printVector(VectorInt &v){
    cout << "START. Вывод элементов вектора : ";
    for (int i = 0; i < v.capacity(); i++)
        cout << v.at(i) << " ";
    cout << "   " << "size = " << v.size() << " capacity = " << v.capacity() << endl;
}

int main(){
    VectorInt vector;
    fillVector(vector,10);
    printVector(vector);
    return 0;
}
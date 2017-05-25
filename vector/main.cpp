#include <iostream>
#include "VectorInt.h"

using namespace std;

int main(){
    VectorInt vector1;

    for(int i = 0; i < 8; i++)
        vector1.push(i);


    cout << "Тест vector.at() на всех элементах : ";
    for(int i = 0; i < vector1.size(); i++)
        cout << vector1.at(i) << " " ;
    cout << endl;

    vector1.insert(3,3);
    vector1.insert(6,3);

    cout << "Тест vector.at() на всех элементах : ";
    for(int i = 0; i < vector1.size(); i++)
        cout << vector1.at(i) << " " ;
    cout << endl;

    cout << vector1.find(3) << endl;

    cout << "Тест vector.at() на всех элементах : ";
    for(int i = 0; i < vector1.size(); i++)
        cout << vector1.at(i) << " " ;
    cout << endl;
    return 0;
}
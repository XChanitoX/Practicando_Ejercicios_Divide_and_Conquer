#include <iostream>
#include <vector>

using namespace std;

int contador(vector<int> &numbers, int k){
    // Caso base en el que no hay elementos
    if (int(numbers.size()) == 0)
        return 0;

    // Caso base si el unico elemento es el que buscamos
    if (numbers.size() == 1)
        return numbers[0] == k;

    // Divide
    vector<int> L, R;
    int mid = int((numbers.size()-1)) / 2;

    // Agregamos todos los elementos del lado izquierdo
    for (int i = 0; i <= mid; ++i)
        L.push_back(numbers[i]);

    // Agregamos todos los elementos del lado derecho
    for (int i = mid+1; i <= numbers.size()-1; ++i)
        R.push_back(numbers[i]);


    // Conquer al llegar a los casos base
    // Combine
    return (contador(L, k) + contador(R, k));
}

int problem2(vector<int> &&numbers, int k){
    return contador(numbers, k);
}

int main(){
    cout << "Problem 2 - Occurrences\n";
    vector<int> numbers = {5,5,5,5,5};
    int k = 5;
    cout << problem2(move(numbers), k) << endl;
}
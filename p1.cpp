#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int> &numbers, int low, int mid, int high){
    //Creamos vectores para separar el vector original
    vector<int> L, R;

    //Agregamos todos los elementos de la izquierda
    for (int i = low; i <= mid; ++i) {
        L.push_back(numbers[i]);
    }

    //Agregamos todos los elementos de la derecha
    for (int i = mid+1; i <= high; ++i) {
        R.push_back(numbers[i]);
    }

    //Obtenemos los tamanhos de los subarrays
    int size_L = L.size(), size_R = R.size();
    int inversiones = 0;

    //Apuntadores a los indices actuales de los subarrays
    int indice_L = 0, indice_R = 0;
    int i;

    for (i = low; i <= high; ++i) {
        //Si ya terminamos
        if (indice_L == size_L || indice_R == size_R)
            break;

        //Si no existe inversion
        if (R[indice_R] > L[indice_L]){
            numbers[i] = L[indice_L];
            indice_L++;
        }else{//Si existe inversion
            //Como está ordenado sabemos que si el elemento que hace
            //inversión tiene elementos mayores a él entonces estos
            //también hacen inversión
            inversiones += (size_L-indice_L);
            numbers[i] = R[indice_R];
            indice_R++;
        }
    }

    //Copiamos lo que sobre
    while(indice_L < size_L)
        numbers[i++] = L[indice_L++];

    //Copiamos lo que sobre
    while(indice_R < size_R)
        numbers[i++] = R[indice_R++];

    return inversiones;
}


int contarInversiones(vector<int> &numbers, int low, int high){
    int inversiones = 0;

    //Si aun no se acaba de leer todo el vector
    if (low < high){
        // Divide
        int mid = (low+high)/2;

        //Conquer
        inversiones += contarInversiones(numbers, low, mid);
        inversiones += contarInversiones(numbers, mid+1, high);

        //Combine
        inversiones += merge(numbers, low, mid, high);
    }
    return inversiones;
    /*
     * T(n) = 2T(n/2) + O(n)
     */
}

int problem1(vector<int> && numbers) {
    return contarInversiones(numbers, 0, (int)numbers.size()-1);
}

int main() {
    cout << "Problem 1 - Similarity\n";

    vector<int> numbers = {10,2,4,1,3,5,8};

    cout << problem1(move(numbers)) << "\n";

    return 0;
}
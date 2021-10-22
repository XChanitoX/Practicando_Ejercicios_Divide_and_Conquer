#include <iostream>

using namespace std;

long potencia(long num, long k){
    int resultado = num;
    if (k == 0)
        return 1;
    else if (k == 1)
        return resultado;
    else{
        int calculo = potencia(num, k/2);
        if (k % 2 == 0){
            resultado = calculo * calculo;
        }else{
            resultado = calculo * calculo * num;
        }
        return resultado;
    } //T(n) = T(n/2) + O(1)
    // T(n) = Theta(log(n))
}

long problem4(long base, long power){
    return potencia(base,power);
}

int main() {
    cout << "Problem 4 - Powering\n";
    long base = 4;
    long power = 2;
    printf("%ld power of %ld is %ld\n", base, power, problem4(base,power));
}

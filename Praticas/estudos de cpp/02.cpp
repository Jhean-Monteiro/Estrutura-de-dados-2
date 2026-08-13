#include <iostream>

const int exercicio() {
    int arr[10] = {1,2,3,4,50,6,7,8,9,10};
    int contador = 0;
    int pares = 0;

    std::cout << "numeros: ";
    for (int x : arr) {
        contador = contador+x;
        std::cout << x << " ";
        if (x % 2 == 0) {
            pares++;
        }
    }
    
    std::cout << std::endl << "quantos pares tem: " << pares << std::endl;

    int i = 0;
    int maior = arr[0];
    while (i < 10) {
        if (arr[i] > maior) {
            maior = arr[i];
        }
        i++;
    }
    std::cout << "maior: " << maior << std::endl;
    return 0;
}

void teste() {
    for (int i = 0; i < 100; i++) {
        std::cout << i << " ";
    }
}

void teste2() {
    int arr[5] = {2,4,6,8,10};

    for (int i : arr) {
        std::cout << i << " ";
    }

    int i = 0;
    while (i < 6) {
        int teste = arr[i];
        std::cout << teste << " ";
        i++;
    }
}

int main() {
    exercicio();
    teste();
    teste2();
    return 0;
}
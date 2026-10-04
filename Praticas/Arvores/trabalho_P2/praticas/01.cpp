#include <iostream>
#include <iterator>

int buscaBinaria(int vetor[], int tamanho, int alvo) {
    int inicio = 0;
    int final = tamanho - 1;

    while (inicio <= final) {
        int meio = inicio + (final - inicio) / 2;

        if (vetor[meio] == alvo) {
            return meio;
        }
        if (vetor[meio] < alvo) {
            inicio = meio+1; // alvo está na frente do meio, então corta o inicio
        } else {
            final = meio - 1;
        }
    }

    return -1; // elemento não encontrado
}

void selectionSort(int vetor[], int tamanho) {

    for (int i = 0; i <= tamanho -2; i++) {
        int menorIndice = i;
        for (int j = i+1; j <=tamanho-1; j++) {
            if (vetor[j] < vetor[menorIndice]) {
                menorIndice = j;
            }
        }
        if (menorIndice != i) {
            int temp = vetor[i];
            vetor[i] = vetor[menorIndice];
            vetor[menorIndice] = temp;
        }
    }

    return;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int tam = std::size(arr);
    std::cout << buscaBinaria(arr, tam, 5) << std::endl;

    int arr2[] = {1,5,7,5,8,9,4,3,2,56,-55,3,4,7};
    int tam2 = std::size(arr2);
    selectionSort(arr2, tam2);

    for (int k = 0; k < tam2; k++) {
        std::cout << arr2[k] << " ";
    }
    std::cout << std::endl;

    std::cout << "oii" << std::endl;
    return 0;
}
#include <iostream>

using namespace std;

void ordenacaoPorSelecao(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        int menorIndice = i; // assume inicialmente que o menor indice está na posicao 'i'

        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menorIndice]) {
                menorIndice = j;
            }
        }

        int aux = vetor[i];
        vetor[i] = vetor[menorIndice];
        vetor[menorIndice] = aux;
    }
}

void exibirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << "[" << vetor[i] << "] ";
    }
    cout << endl;
}

int main() {
    // vetor desordenado igual ao da aula 8
    int vetor[] = {20,13,17,-9,4,8,2,-1,-5,0,-11,6};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    cout << "vetor antes da ordenação: " << endl;
    exibirVetor(vetor, tamanho);

    ordenacaoPorSelecao(vetor, tamanho);

    cout << "\nvetor após a ordenação por seleção: " << endl;
    exibirVetor(vetor, tamanho);

    return 0;
}
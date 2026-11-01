#include <iostream>

using namespace std;

int buscaBinaria(int vetor[], int tamanho, int alvo) {
    int primeiro = 0;
    int ultimo = tamanho-1;
    int posicao = -1; // -1 como retorno padrão (não encontrado)

    while (primeiro <= ultimo) {
        int meio = (primeiro + ultimo) / 2;

        if (vetor[meio] == alvo) {
            posicao = meio; // achou o alvo
            primeiro = ultimo + 1; // faz o 'primeiro' passar de 'ultimo' para sair do while

        } else if (vetor[meio] < alvo) {
            primeiro = meio + 1; // 'corta' a metade 'esquerda' do vetor

        } else {
            ultimo = meio - 1; // 'corta' a metade 'direita' do vetor
        }
    }


    return posicao;
}

void conferirResultado(int resultado) {
    if (resultado != -1) {
        cout << "Elemento encontrado no indice " << resultado << " (posicao " << resultado + 1 << " da lista)." << endl;
    } else {
        cout << "Elemento não encontrado na lista. " << endl; 
    }
}

int main() {
    // vetor ordenado igual ao da aula 7
    int vetor[] = {1,3,6,9,10,11,15,16,19,20,22,26,28,31,33,34};

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int alvo;

    cout << "Vetor ordenado: ";
    for (int i = 0; i < tamanho; i++) {
        cout << "[" << vetor[i] << "] ";
    }
    cout << endl;


    cout << "Digite o valor que deseja buscar: ";
    cin >> alvo;

    int resultado = buscaBinaria(vetor, tamanho, alvo);

    conferirResultado(resultado);

    return 0;
}
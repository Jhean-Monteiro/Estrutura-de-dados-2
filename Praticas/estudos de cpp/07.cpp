#include <iostream>

struct No {
    int valor;
    No *proximo;
};

No* inserirInicio(No *cabeca, int valor) {
    No *novo = new No;
    novo->valor = valor;
    novo->proximo = cabeca; // novo nó aponta pro antigo primeiro
    return novo;
}

void imprimirLista(No *cabeca) {
    No *temp = cabeca;

    while (temp != nullptr) {
        std::cout << temp->valor << std::endl;

        temp = temp->proximo;
    }
}

No* inserirFim(No *cabeca, int valor) {
    No *novo = new No;
    novo->valor = valor;
    novo->proximo = nullptr;

    if (cabeca == nullptr) {
        return novo; // lista tava vazia
    }

    // lista não estava vazia
    No *temp = cabeca;
    while (temp->proximo != nullptr) {
        temp = temp->proximo;
    }
    temp->proximo = novo; // conecta o ultimo nó ao novo

    return cabeca; // cabeca não mudou. só cresceu no fim.
}

No* remover(No *cabeca, int valor) {

    if (cabeca == nullptr) {
        return cabeca;
    }

    if (cabeca->valor == valor) {
        No *novaCabeca = cabeca->proximo;
        delete cabeca;
        return novaCabeca;
    }

    No *anterior = cabeca;
    No *atual = cabeca->proximo;

    while (atual != nullptr) {
        if (atual->valor == valor) {
            anterior->proximo = atual->proximo;
            delete atual;
            return cabeca;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    // valor não encontrado
    return cabeca;
}

bool buscar(No *cabeca, int valor) {
    No *temp = cabeca;

    while (temp != nullptr) {
        if (temp->valor == valor) {
            return true;
        }
        temp = temp->proximo;
    }
    return false;
}

int main() {
    No *lista = nullptr;

    lista = inserirInicio(lista, 30);
    lista = inserirInicio(lista, 20);
    lista = inserirFim(lista, 40);
    lista = inserirInicio(lista, 10);
    lista = remover(lista, 20);
    lista = remover(lista, 0);

    bool b = buscar(lista, 30);
    bool a = buscar(lista, 20);

    std::cout << b << std::endl << a << std::endl;

    imprimirLista(lista);
}
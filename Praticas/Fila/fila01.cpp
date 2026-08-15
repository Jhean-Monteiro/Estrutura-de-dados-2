#include <iostream>

struct No {
    int valor;
    No *proximo;
};

struct Fila {
    No *frente;
    No *tras;
};

bool isEmpty(Fila *f) {
    if (f->frente == nullptr) {
        std::cout << "lista vazia" << std::endl;
        return true;
    }
    return false;
}

void enqueue(Fila *f, int valor) {
    No *novo = new No;
    novo->valor = valor;
    novo->proximo = nullptr;

    if (isEmpty(f)) {
        f->frente = novo;
        f->tras = novo;
        return;
    } else {
        f->tras->proximo = novo;
    }
    f->tras = novo;
    return;
}

void exibir(Fila *f) {
    No *temp = f->frente;

    while (temp != nullptr) {
        std::cout << temp->valor << " ";

        temp = temp->proximo;
    }

    std::cout << std::endl;
    return;
}

void dequeue(Fila *f) {
    if (isEmpty(f)) {
        return;
    }

    No *temp = f->frente;
    f->frente = f->frente->proximo;

    if (f->frente == nullptr) {
        f->tras = nullptr;
    }

    std::cout << "removendo: " << temp->valor << std::endl;
    delete temp;
    return;
}

int frenteValor(Fila *f) {
    std::cout << "valor da frente: " << f->frente->valor << std::endl;
    return f->frente->valor;
} 


int main(){
    Fila *fila = new Fila;

    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);
    enqueue(fila, 40);
    dequeue(fila);
    frenteValor(fila);
    dequeue(fila);
    exibir(fila);

    return 0;
}
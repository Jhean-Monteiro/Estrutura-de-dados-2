#include <iostream>

struct No {
    int valor;
    No *prev;
};

struct Pilha {
    No *topo;
};

No* push(No *topo, int valor) {
    No *novo = new No;
    novo->valor = valor;
    novo->prev = topo;
    topo = novo;
    return topo;
}

void exibir(Pilha *p) {
    No *temp = p->topo;

    while (temp != nullptr) {
        std::cout << temp->valor << " ";

        temp = temp->prev;
    }

    std::cout << std::endl;
}

bool isEmpty(No *topo) {
    if (topo == nullptr) {
        std::cout << "lista vazia" << std::endl;
        return true;
    }
    return false;
}

No* pop(No *topo) {

    if (isEmpty(topo)) {
        return topo;
    }

    No *temp = topo;

    topo = topo->prev;

    delete temp;

    return topo;
}

int pick(No *topo) {
    return topo->valor;
}

int main() {
    Pilha *pilha = new Pilha;
    
    pilha->topo = push(pilha->topo, 10);
    pilha->topo = push(pilha->topo, 20);
    pilha->topo = push(pilha->topo, 30);
    pilha->topo = pop(pilha->topo);
    int a = pick(pilha->topo);
    std::cout << "topo: " << a << std::endl;
    pilha->topo = pop(pilha->topo);
    pilha->topo = pop(pilha->topo);
    pilha->topo = pop(pilha->topo);
    exibir(pilha);

    return 0;
}
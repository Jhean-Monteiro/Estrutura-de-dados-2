#include <iostream>

struct No {
    int valor;
    No *esquerda;
    No *direita;
};

int contarNos(No *raiz) {
    if (raiz == nullptr) return 0;
    
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int somarValor(No *raiz) {
    if (raiz == nullptr) return 0;
    
    return raiz->valor + somarValor(raiz->esquerda) + somarValor(raiz->direita);
}

int main()
{
    No *a = new No{10, nullptr, nullptr};
    No *b = new No{20, nullptr, nullptr};
    No *c = new No{30, nullptr, nullptr};
    No *d = new No{40, nullptr, nullptr};
    No *e = new No{50, nullptr, nullptr};
    No *f = new No{60, nullptr, nullptr};
    No *g = new No{70, nullptr, nullptr};
    No *h = new No{80, nullptr, nullptr};
    
    a->esquerda = b;
    a->direita = c;
    b->esquerda = d;
    b->direita = e;
    c->esquerda = f;
    c->direita = g;
    d->esquerda = h;
    
    std::cout << "hello world" << std::endl;
    
    int numero = contarNos(a);
    
    int total = somarValor(a);
    
    std::cout << numero << std::endl;
    
    std::cout << total << std::endl;

    return 0;
}

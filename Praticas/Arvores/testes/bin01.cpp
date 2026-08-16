#include <iostream>

// numa arvore binária, cada nó tem, no máximo, um filho esquerdo e um filho direito.

struct No {
    int valor;
    No *esquerda;
    No *direita;
};
// diferença para com a lista encadeada: em vez de um unico ponteiro (proximo), agora são dois (esquerda e direita). cada um pode ser nullptr (ausencia de filho).


// RAIZ: O nó do topo (sem pai)
// Folha: Nó sem filhos
// Nível de um nó: quantos nós há no caminho da raiz até ele (raiz = nivel 1)
// Altura da árvore: nível do nó mais profundo

int contarNos(No *raiz, int contador) {

    if (raiz->esquerda != nullptr) {
        contador = contarNos(raiz->esquerda, contador);
    } 

    if (raiz->direita != nullptr) {
        contador = contarNos(raiz->direita, contador);
    }

    return contador+1;
};

int contarNos(No *raiz) {
    if (raiz == nullptr) {
        return 0;
    }

    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}


// Percursos

// pré ordem: visita o nó antes de descer
void preOrdem(No *raiz) {
    if (raiz == nullptr) return;
    std::cout << raiz->valor << " "; // visita o nó;
    preOrdem(raiz->esquerda); // desce pra esquerda
    preOrdem(raiz->direita); // desce pra direita
}

// em ordem: visita o nó entre as duas descidas
void emOrdem(No *raiz) {
    if (raiz == nullptr) return;
    emOrdem(raiz->esquerda); // desce pra esquerda primeiro
    std::cout << raiz->valor << " "; // só ai visita o nó
    emOrdem(raiz->direita); // depois desce para a direita
}

// pos ordem: visita o nó depois de descer nos dois lados
void posOrdem(No *raiz) {
    if (raiz == nullptr) return;
    posOrdem(raiz->esquerda);
    posOrdem(raiz->direita);
    std::cout << raiz->valor << " ";
}

int main() {
    No *a = new No{1, nullptr, nullptr};
    No *b = new No{2, nullptr, nullptr};
    No *c = new No{3, nullptr, nullptr};
    No *d = new No{4, nullptr, nullptr};
    No *e = new No{5, nullptr, nullptr};
    No *f = new No{5, nullptr, nullptr};
    No *g = new No{5, nullptr, nullptr};

    a->esquerda = b;
    a->direita = c;
    b->esquerda = d;
    b->direita = e;
    c->esquerda = f;
    c->direita = g;

    int numero = contarNos(a,0); // com a raiz, já começa com 1

    std::cout << numero << std::endl;

    preOrdem(a);
    std::cout << std::endl;
    emOrdem(a);
    std::cout << std::endl;
    posOrdem(a);
    std::cout << std::endl;

    return 0;
}


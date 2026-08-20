#include <iostream>
#include <queue>

struct No {
    int valor;
    No *esquerda;
    No *direita;
};

No* criar(int valor) {
    return new No{valor, nullptr, nullptr};
}

// insere no primeiro espaço vazio, da esquerda pra direita
No* inserir(No* raiz, int valor) {
    if (raiz == nullptr) {
        return criar(valor);
    }

    // se já tem os dois filhos, avisa e desce para onde o usuario escolher
    // se só tem um lado vazio, insere direto
    if (raiz->esquerda == nullptr && raiz->direita == nullptr) {
        char lado;
        std::cout << "Inserir " << valor << " à esquerda (e) ou direita (d) de " << raiz->valor << "? ";
        std::cin >> lado;
        if (lado == 'e') raiz->esquerda = criar(valor);
        else raiz->direita = criar(valor);
        return raiz;
    }

    char lado;
    std::cout << "Inserir " << valor << " à esquerda (e) ou direita (d) de " << raiz->valor << "? ";
    std::cin >> lado;

    if (lado == 'e') {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

int main() {
    No* raiz = criar(10);

    inserir(raiz, 5);
    inserir(raiz, 15);
    inserir(raiz, 3);
    inserir(raiz, 7);

    std::cout << "raiz: " << raiz->valor << std::endl;
    
    if (raiz->esquerda) 
        std::cout << "esq: " << raiz->esquerda->valor << std::endl;
    
    if (raiz->direita) 
        std::cout << "dir: " << raiz->direita->valor << std::endl;


    return 0;
}
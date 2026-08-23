#include <iostream>


struct No {
    int valor;
    No *esquerda;
    No *direita;
};

No* criarDegeneradaDireita(int atual, int limite) {
    if (atual > limite) {
        return nullptr; // acabaram os valores para inserir
    }

    No *novo = new No;
    novo->valor = atual;
    novo->esquerda = nullptr;
    novo->direita = criarDegeneradaDireita(atual+1,limite);

    return novo;
}


No* criarDegeneradaEsquerda(int atual, int limite) {
    if (atual > limite) {
        return nullptr;
    }

    No *novo = new No;
    novo->valor = atual;
    novo->esquerda = criarDegeneradaEsquerda(atual+1, limite);
    novo->direita = nullptr;

    return novo;
}


void imprimirComProfundidade(No *raiz, int profundidade) {
    if (raiz == nullptr) return;

    // imprime recuo proporcional ao nível do nó
    for (int i = 0; i < profundidade; i++) {
        std::cout << "  ";
    }
    std::cout << "- " << raiz->valor << std::endl;


    // chama os dois lados por segurança
    imprimirComProfundidade(raiz->esquerda, profundidade+1);
    imprimirComProfundidade(raiz->direita, profundidade+1);

}



int main() {
    std::cout << "Degenerada a direita (1 a 50):" << std::endl;
    No *raizDireita = criarDegeneradaDireita(1,50);
    imprimirComProfundidade(raizDireita, 0);

    std::cout << std::endl;

    std::cout << "Degenerada a esquerda (1 a 50):" << std::endl;
    No *raizEsquerda = criarDegeneradaEsquerda(1,50);
    imprimirComProfundidade(raizEsquerda, 0);

    return 0;
}
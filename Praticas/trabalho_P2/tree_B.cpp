#include <iostream>

using namespace std;

// estrutura do nó da árvore
struct No {
    int chave; // valor armazenado no nó
    No* esq; // ponteiro para o filho esquerdo
    No* dir; // ponteiro para o filho direito
};

No* criarNo(int chave) {
    No* novo = new No;
    novo->chave = chave;
    novo->esq = nullptr;
    novo->dir = nullptr;
    return novo;
}


No* inserir(No* raiz, int chave) {
    // caso base: encontrou a posição vaia para inserir o nó
    if (raiz == nullptr) {
        return criarNo(chave);
    }

    // se a chave for menor, insere na subarvore esquerda
    if (chave < raiz->chave) {
        raiz->esq = inserir(raiz->esq, chave);
    }

    // se for maior, insere na subarvore direita
    else if (chave > raiz->chave) {
        raiz->dir = inserir(raiz->dir, chave);
    }

    // chave duplicada
    else {
        cout << "Chave " << chave << " já existe na arvore (duplicata rejeitada)." << endl;
    }

    return raiz;
}

bool buscar(No* raiz, int chave) {
    // caso base: arvore vazia ou chave nao encontrada
    if (raiz == nullptr) {
        return false;
    }

    // chave encontrada
    if (raiz->chave == chave) {
        return true;
    }

    // se a chave procurada é menor, busca apenas na subarvore esquerda
    if (chave < raiz->chave) {
        return (buscar(raiz->esq, chave));
    }

    // caso contrario, busca apenas na subarvore direita
    else {
        return buscar(raiz->dir, chave);
    }
}


// esse percurso sempre exibe os numeros em ordem crescente
void emOrdem(No* raiz) {
    if (raiz == nullptr) {
        return;
    }
    emOrdem(raiz->esq);
    cout << "[" << raiz->chave << "] ";
    emOrdem(raiz->dir);
}

void destruirArvore(No*& raiz) {
    if (raiz == nullptr) {
        return;
    }
    destruirArvore(raiz->esq);
    destruirArvore(raiz->dir);
    delete raiz;
    raiz = nullptr;
}


int main() {
    No* raiz = nullptr;

    // valores para montar a arvore binaria de busca
    int valores[] = {1,4,5,7,8,9,66,33,15,6,9,45,32,25};
    int total = sizeof(valores) / sizeof(valores[0]);

    cout << "inserindo valores na ABB: ";
    for (int i = 0; i < total; i++) {
        cout << valores[i] << " ";
        raiz = inserir(raiz, valores[i]);
    }

    cout << "\n\n";

    cout << "Exibicao em-ordem (elementos ficam ordenados):" << endl;
    emOrdem(raiz);

    cout << "\n\n";

    // teste de busca
    int valorBusca = 0;
    cout << "Digite um valor para buscar na arvore: ";
    cin >> valorBusca;

    if (buscar(raiz,  valorBusca)) {
        cout << "Resultado: O valor " << valorBusca << " pertence à arvore." << endl; 
    } else {
        cout << "Resultado: O valor " << valorBusca << " não pertence à arvore." << endl;
    }


    // liberando a memória antes de encerrar
    destruirArvore(raiz);
    cout << "\nMemoria da arvore liberad com sucesso." << endl;

    return 0;
}
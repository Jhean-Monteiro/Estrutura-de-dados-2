#include <iostream>

struct No {
    int valor;
    No *proximo;
};

int main() {
    No *n1 = new No;
    No *n2 = new No;
    No *n3 = new No;

    n1->valor = 10;
    n2->valor = 20;
    n3->valor = 30;

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = nullptr;

    No *temp = n1;
    
    while (temp != nullptr) {
        std::cout << temp->valor << std::endl;
        temp = temp->proximo;
    }

    delete n1;
    delete n2;
    delete n3;
}
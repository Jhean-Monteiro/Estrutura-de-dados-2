#include <iostream>

struct No {
    int valor;
    No *proximo; // ponteiro para outro No
};

int main() {
    No *n = new No;
    n->valor = 10;
    n->proximo = nullptr;

    std::cout << n->valor << std::endl;   // 42
    std::cout << (*n).valor << std::endl; // 42 -- mesma coisa, forma "crua"


    delete n;
}

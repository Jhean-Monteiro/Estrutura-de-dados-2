#include <iostream>

struct Pilha {
    int dados[100];
    int topo = -1;

    void push(int valor) {
        if (topo < 99) {
            dados[++topo] = valor;
        }
    }

    void pop() {
        if (topo >= 0) {
            topo--;
        }
    }

    int peak() {
        return dados[topo];
    }
};

int main() {
    Pilha p;
    p.push(5);
    p.push(10);
    std::cout << "Topo da pilha:: " << p.peak() << std::endl;
}

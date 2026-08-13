#include <iostream>

int dobrar(int x) {
    return x * 2;
}

double dobrar(double x) {
    return x * 2;
}

void trocar(int &a, int &b) {
    int c = a; // auxiliar
    a = b;
    b = c;
}

int main() {
    int n = 4;
    double m = 8.333;
    std::cout << dobrar(n) << " " << std::endl;
    std::cout << dobrar(m) << " " << std::endl;

    int a = 4;
    int b = 6;
    trocar(a,b);
    std::cout << "valor de a: " << a << ", valor de b: " << b << std::endl;

    return 0;
}
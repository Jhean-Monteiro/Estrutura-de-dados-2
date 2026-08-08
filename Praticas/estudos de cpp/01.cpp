#include <iostream> // acesso a entrada e saida de dados

int teste() {
    int idade;
    std::cout << "Digite sua idade: ";
    std::cin >> idade;
    std::cout << "Você tem " << idade << " anos." << std::endl;
    return 0;
}


int ex() {
    char nome[50];
    int idade;
    std::cout << "Digite seu nome: ";
    std::cin >> nome;

    std::cout << "Digite sua idade: ";
    std::cin >> idade;
    std::cout << "olá, " << nome << "! você tem " << idade << " anos." << std::endl;

    return 0;
}

int main() {

    // cout é um objeto (não uma função) que representa o canal de saída padrão (a tela). o operador '<<' é usado para 'empurrar' coisas nele

    std::cout << "olá, mundo" << std::endl;

    // pensa assim: '<<' significa 'insere isso aqui no fluxo de saída' igual uma seta apontando para dentro do cout

    int idade = 20;
    std::cout << "Minha idade é: " << idade << " anos" << std::endl;
    teste();
    ex();

    return 0; // chegar aqui significa que 'rodou tudo certo'
}
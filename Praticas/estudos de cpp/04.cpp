#include <string>
#include <iostream>

void teste() {
    std::string s = "c++";
    std::cout << s[0] << std::endl;
    s[0] = 'K'; // strings são mutáveis em c++
    std::cout << s << std::endl;
}

void substring() {
    std::string s = "Estruturas de Dados";
    std::string parte = s.substr(0,10); // começa no índice 0, pega 10 caracteres
    std::cout << parte << std::endl; // estruturas

    std::string resto = s.substr(11); // sem segundo argumento, vai até o fim
    std::cout << resto << std::endl;
}

void buscar() {
    std::string s = "Estruturas de Dados";
    size_t pos = s.find("de"); // procura a substring
    if (pos != std::string::npos) { // npos = 'não encontrado' (tipo -1, mas de outro tipo)
        std::cout << "achou na posição: " << pos << std::endl;
    } else {
        std::cout << "não achou" << std::endl;
    } 
}

void percorrer() {
    std::string s = "abc";
    for (char c : s) {
        std::cout << c << " " << std::endl;
    }
}


bool isPalindrome(std::string s) {
    bool retornavel = false;

    int i = 1;
    for (char x : s) {
        int indice = s.length()-i;
        if (x == s[indice]) {
            retornavel = true;
        } else {
            std::cout << "a string '" << s << "' não é um palindromo" << std::endl;
            retornavel = false;
            return retornavel;
        }
        i++;
    }

    std::cout << "a string '" << s << "' é um palindromo" << std::endl;

    return retornavel;
}

bool isPalindromo(std::string s) {
    int inicio = 0;
    int fim = s.length() -1;

    while (inicio < fim) {
        if (s[inicio] != s[fim]) {
            std::cout << "a string '" << s << "' não é um palindromo" << std::endl;
            return false;
        }
        inicio++;
        fim--;
    }

    std::cout << "a string '" << s << "' é um palindromo" << std::endl;
    return true;
}


int main() {
    std::string nome = "Jhean";
    std::string sobrenome = "Monteiro";
    std::string completo = nome + " " + sobrenome;
    std::cout << completo << std::endl;
    std::cout << completo.length() << std::endl;

    teste();
    substring();
    buscar();
    percorrer();

    isPalindrome("jheannaehj");
    isPalindromo("subinoonibus");

    return 0;
}
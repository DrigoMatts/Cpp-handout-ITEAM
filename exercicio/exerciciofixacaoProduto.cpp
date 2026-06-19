#include <iostream>
#include <string>

class Produto {
private:
    std::string nome;
    double preco;

public:
    Produto(std::string n, double p) {
        nome = n;
        setPreco(p);
    }

    // Getters e Setters
    void setNome(std::string n) {
        nome = n;
    }

    std::string getNome() {
        return nome;
    }

    void setPreco(double p) {
        if (p > 0) {
            preco = p;
        } else {
            std::cout << "Erro: O preco deve ser maior que zero!" << std::endl;
            preco = 0.01; 
        }
    }

    double getPreco() {
        return preco;
    }

    void exibirDados() {
        std::cout << "Produto: " << nome << " | Preco: R$ " << preco << std::endl;
    }
};

int main() {
    Produto p1("Notebook", 3500.00);
    
    Produto p2("Caneta", -1.50);

    std::cout << "--- Dados dos Produtos ---" << std::endl;
    p1.exibirDados();
    p2.exibirDados();

    return 0;
}

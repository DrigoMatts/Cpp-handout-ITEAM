#include <iostream>
#include <string>

class Produto {
private:
    std::string nome;
    double preco;

public:
    // Getters
    std::string getNome() { return nome; }
    double getPreco() { return preco; }

    // Setters
    void setNome(std::string n) { nome = n; }
    
    void setPreco(double p) {
        if (p > 0) {
            preco = p;
        } else {
            std::cout << "Erro: O preco deve ser maior que zero." << std::endl;
        }
    }
};

int main() {
    Produto p1, p2;

    p1.setNome("Notebook");
    p1.setPreco(3500.00);

    p2.setNome("Mouse");
    p2.setPreco(150.00);

    // Dados
    std::cout << "Produto 1: " << p1.getNome() << " | Preco: R$ " << p1.getPreco() << std::endl;
    std::cout << "Produto 2: " << p2.getNome() << " | Preco: R$ " << p2.getPreco() << std::endl;

    // validação 
    std::cout << "\nTentando definir preco invalido para o Produto 2:" << std::endl;
    p2.setPreco(-10.00);

    return 0;
}

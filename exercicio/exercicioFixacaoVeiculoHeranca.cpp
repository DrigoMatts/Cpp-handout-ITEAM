#include <iostream>
#include <string>

// Classe(Pai)
class Veiculo {
public:
    std::string marca;

    // Construtor
    Veiculo(std::string m) : marca(m) {}
};

// Classe(Filho) que herda de Veiculo
class Carro : public Veiculo {
public:
    std::string modelo;

    // Construtor da classe Carro
    // Chamamos o construtor de Veiculo passando a marca
    Carro(std::string m, std::string mod) : Veiculo(m), modelo(mod) {}

    void exibirDetalhes() {
        std::cout << "Carro: " << marca << " " << modelo << std::endl;
    }
};

int main() {
    // Objeto da classe Carro
    Carro meuCarro("Ford", "Mustang");
    meuCarro.exibirDetalhes();

    return 0;
}
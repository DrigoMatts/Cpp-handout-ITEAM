#include <iostream>
#include <string>

class Carro {
private:
    std::string marca;
    double velocidade;

public:
    // Construtor
    Carro(std::string m) : marca(m), velocidade(0.0) {}

    // Métodos
    void acelerar(double valor) {
        if (valor > 0) {
            velocidade += valor;
        }
    }

    void frear(double valor) {
        if (valor > 0) {
            velocidade -= valor;
            if (velocidade < 0) {
                velocidade = 0;
            }
        }
    }

    // Getters
    std::string getMarca() const {
        return marca;
    }

    double getVelocidade() const {
        return velocidade;
    }
};

int main() {
    Carro meuCarro("Toyota");

    meuCarro.acelerar(50);
    std::cout << "Marca: " << meuCarro.getMarca() << " | Velocidade: " << meuCarro.getVelocidade() << " km/h" << std::endl;

    meuCarro.frear(60); 
    std::cout << "Após frear: " << meuCarro.getVelocidade() << " km/h" << std::endl;

    return 0;
}

#include <iostream>
#include <string>

class Guitarra {
private:
    std::string marca;
    std::string cor;
    int numeroCordas;
    bool afinada;

public:
    // Construtor: inicializa os atributos do objeto
    Guitarra(std::string _marca, std::string _cor, int _numeroCordas) {
        marca = _marca;
        cor = _cor;
        numeroCordas = _numeroCordas;
        afinada = true; // Guitarra começa afinada por padrão
    }

    // Comportamentos (Métodos)
    void tocarNota(std::string nota) {
        if (afinada) {
            std::cout << "Tocando a nota " << nota << " na sua guitarra " << cor << " da " << marca << "!" << std::endl;
        } else {
            std::cout << "A guitarra esta desafinada! Afine-a primeiro." << std::endl;
        }
    }

    void afinar() {
        afinada = true;
        std::cout << "As cordas foram ajustadas. A guitarra agora esta afinada!" << std::endl;
    }

    void trocarCor(std::string novaCor) {
        cor = novaCor;
        std::cout << "A guitarra foi repintada. Nova cor: " << cor << std::endl;
    }
    
    // Método para exibir o estado atual dos atributos
    void exibirDetalhes() {
        std::cout << "\n--- Detalhes da Guitarra ---" << std::endl;
        std::cout << "Marca: " << marca << std::endl;
        std::cout << "Cor: " << cor << std::endl;
        std::cout << "Cordas: " << numeroCordas << std::endl;
        std::cout << "Estado: " << (afinada ? "Afinada" : "Desafinada") << std::endl;
    }
};

int main() {
    // Instanciando (criando) o objeto "minhaGuitarra"
    Guitarra minhaGuitarra("Fender", "Vermelha", 6);

    minhaGuitarra.exibirDetalhes();
    minhaGuitarra.tocarNota("Mi Maior");
    
    std::cout << "\n* Cordas arrebentaram *" << std::endl;
    minhaGuitarra.afinar(); // Usando comportamento de afinar
    minhaGuitarra.tocarNota("Sol");

    return 0;
}

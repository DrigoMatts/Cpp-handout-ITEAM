#include <iostream>
#include <string>

class Animal {
private:
    std::string especie;
    std::string som;

public:
    Animal(std::string especie, std::string som) 
        : especie(especie), som(som) {}

    void emitir_som() {
        std::cout << "O " << especie << " faz: " << som << "!" << std::endl;
    }
};

int main() {
    // Criando instâncias de diferentes animais
    Animal cachorro("Cachorro", "Au au");
    Animal gato("Gato", "Miau");
    Animal corvo("Corvo", "Cro Crow");

    // Chamando o método/saídas.
    cachorro.emitir_som(); 
    gato.emitir_som();     
    corvo.emitir_som();

    return 0;
}

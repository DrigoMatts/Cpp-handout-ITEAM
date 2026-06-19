#include <iostream>
#include <string>

using namespace std;

// Classe base (pai)
class Animal {
protected:
    string nome;

public:
    Animal(string n) : nome(n) {}

    void falar() {
        cout << "O animal faz um som." << endl;
    }
};

// Classe derivada (filha)
class Cachorro : public Animal {
public:
    // Chama o construtor da classe base 'Animal'
    Cachorro(string n) : Animal(n) {}
    
    // Não precisa redefinir falar() - herda da classe pai
};

int main() {
    Cachorro rex("Rex");
    
    // O método falar() é chamado a partir da classe Animal
    rex.falar(); // Saída: O animal faz um som.
    
    return 0;
}

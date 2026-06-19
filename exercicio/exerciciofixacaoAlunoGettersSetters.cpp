#include <iostream>
#include <string>

class Aluno {
private:
    std::string nome;
    double nota;

public:
    // Construtor
    Aluno(std::string n, double nt) {
        nome = n;
        set_nota(nt); // validar a nota inicial
    }

    // Setter com validação
    void set_nota(double nt) {
        if (nt >= 0 && nt <= 10) {
            nota = nt;
        } else {
            std::cout << "Erro: A nota deve estar entre 0 e 10." << std::endl;
        }
    }

    // Getters 
    std::string getNome() const {
        return nome;
    }

    double getNota() const {
        return nota;
    }
};

int main() {
    
    Aluno a("Carlos", 8.5);
    
    a.set_nota(12); // Deve mostrar mensagem de erro
    
    return 0;
}

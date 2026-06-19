#include <iostream>
#include <string>

// Usando o namespace std para não precisar digitar std:: antes de string, cout, endl, etc.
using namespace std;

class Aluno {
private:
    string nome;
    double nota;

public:
    // Construtor
    Aluno(string nome, double nota) {
        this->nome = nome;
        // Validação inicial da nota
        if (nota >= 0 && nota <= 10) {
            this->nota = nota;
        } else {
            this->nota = 0;
            cout << "Nota inicial inválida! Definida como 0." << endl;
        }
    }

    // Os métodos DEVEM ficar dentro da classe
    string get_nome() {
        return nome;
    }

    // Getter da nota
    double get_nota() {
        return nota;
    }

    // Setter da nota com validação
    void set_nota(double nova_nota) {
        if (nova_nota >= 0 && nova_nota <= 10) {
            nota = nova_nota;
            cout << "Nota atualizada para " << nova_nota << endl;
        } else {
            cout << "Nota inválida! Digite um valor entre 0 e 10." << endl;
        }
    }

    void exibir_informacoes() {
        cout << "Aluno: " << nome << " | Nota: " << nota << endl;
    }
}; // A classe termina aqui!

int main() {
    // Testando o código
    Aluno a("Carlos", 8.5);
    a.exibir_informacoes();

    a.set_nota(12); // Deve mostrar erro
    a.exibir_informacoes();

    a.set_nota(9.5); // Deve atualizar
    a.exibir_informacoes();

    return 0;
}
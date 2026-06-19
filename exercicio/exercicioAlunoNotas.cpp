#include <iostream>
#include <string>

class Aluno {
private:
    std::string nome;
    double nota1;
    double nota2;

public:

    Aluno(std::string nome, double nota1, double nota2) {
        this->nome = nome;
        this->nota1 = nota1;
        this->nota2 = nota2;
    }

    // Método para calcular a média
    double calcularMedia() {
        return (nota1 + nota2) / 2.0;
    }

    // Método para verificar e exibir a situação
    void exibirSituacao() {
        double media = calcularMedia();
        std::cout << "Aluno: " << nome << "\n";
        std::cout << "Média: " << media << "\n";
        
        if (media >= 7.0) {
            std::cout << "Situação: APROVADO\n";
        } else {
            std::cout << "Situação: REPROVADO\n";
        }
        std::cout << "-----------------------\n";
    }
};

int main() {
   
    Aluno aluno1("Ana", 8.5, 9.0);
    Aluno aluno2("Bruno", 5.0, 6.0);

    // Mostrando os resultados
    aluno1.exibirSituacao();
    aluno2.exibirSituacao();

    return 0;
}

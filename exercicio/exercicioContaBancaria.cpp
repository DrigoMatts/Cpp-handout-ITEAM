#include <iostream>
#include <string>
#include <locale>

class ContaBancaria {
private:
    std::string titular;
    double saldo;

public:
    // Construtor
    ContaBancaria(std::string nomeTitular, double saldoInicial) {
        titular = nomeTitular;
        saldo = saldoInicial;
    }

    // Método para depositar
    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            std::cout << "Depósito de R$ " << valor << " realizado com sucesso.\n";
        } else {
            std::cout << "Valor de depósito inválido.\n";
        }
    }

    // Método para sacar
    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            std::cout << "Saque de R$ " << valor << " realizado com sucesso.\n";
        } else if (valor > saldo) {
            std::cout << "Saldo insuficiente para saque de R$ " << valor << ".\n";
        } else {
            std::cout << "Valor de saque inválido.\n";
        }
    }

    // Método para consultar o saldo
    void exibirSaldo() {
        std::cout << "Saldo final da conta de " << titular << ": R$ " << saldo << "\n";
    }
};

int main() {
    // Configurando para acentuação em português
    std::setlocale(LC_ALL, "Portuguese");

    // Criando o objeto (titular: Ana, saldo inicial: R$ 500.00)
    ContaBancaria minhaConta("Ana", 500.00);

    // Fazendo um depósito
    minhaConta.depositar(200.00);

    // Fazendo um saque
    minhaConta.sacar(150.00);

    // Mostrando o saldo final
    minhaConta.exibirSaldo();

    return 0;
}

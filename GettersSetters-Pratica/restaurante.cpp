#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Restaurante {
private:
    // Atributos privados (Encapsulamento)
    std::string nome;
    std::vector<std::string> cardapio;

public:
    // Construtor para inicializar o restaurante com um nome
    Restaurante(std::string nome_inicial) {
        // Usamos o próprio setter para garantir a validação de string não vazia
        setNome(nome_inicial);
    }

    // Getter para o nome
    std::string getNome() const {
        return nome;
    }

    // Setter para o nome com validação
    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome do restaurante não pode ser vazio.\n";
        }
    }

    // Adiciona um prato se ele ainda não existir no cardápio
    void adicionarPrato(std::string prato) {
        // Verifica se o prato já está no vetor
        auto it = std::find(cardapio.begin(), cardapio.end(), prato);
        
        if (it == cardapio.end()) {
            cardapio.push_back(prato);
            std::cout << "Prato \"" << prato << "\" adicionado com sucesso!\n";
        } else {
            std::cout << "Aviso: O prato \"" << prato << "\" já existe no cardápio.\n";
        }
    }

    // Exibe todos os pratos disponíveis
    void listarCardapio() const {
        std::cout << "\n--- Cardápio do " << nome << " ---\n";
        if (cardapio.empty()) {
            std::cout << "O cardápio está vazio.\n";
            return;
        }
        for (const auto& prato : cardapio) {
            std::cout << "- " << prato << "\n";
        }
        std::cout << "-----------------------\n";
    }

    // Atende o cliente verificando se o prato está no cardápio
    void atenderCliente(std::string nome_cliente, std::string prato) {
        auto it = std::find(cardapio.begin(), cardapio.end(), prato);
        
        std::cout << "\n[Atendimento] Cliente: " << nome_cliente << " pediu: " << prato << "\n";
        if (it != cardapio.end()) {
            std::cout << "Sucesso: Pedido confirmado! Saindo um(a) " << prato << " para " << nome_cliente << ".\n";
        } else {
            std::cout << "Erro: Desculpe, " << nome_cliente << ", o prato \"" << prato << "\" não existe no nosso cardápio.\n";
        }
    }
};

// --- Execução do Desafio Extra ---
int main() {
    // 1. Criar um restaurante chamado "Sabor Caseiro"
    Restaurante meuRestaurante("Sabor Caseiro");
    std::cout << "Restaurante criado: " << meuRestaurante.getNome() << "\n\n";

    // 2. Adicionar 3 pratos diferentes ao cardápio
    meuRestaurante.adicionarPrato("Feijoada");
    meuRestaurante.adicionarPrato("Lasanha");
    meuRestaurante.adicionarPrato("Frango Grelhado");
    
    // Listando para conferir
    meuRestaurante.listarCardapio();

    // 3. Simular 2 clientes fazendo pedidos (um prato existente e um inexistente)
    meuRestaurante.atenderCliente("Carlos", "Feijoada");       // Prato existe
    meuRestaurante.atenderCliente("Mariana", "Sushi");         // Prato NÃO existe

    // 4. Alterar o nome do restaurante usando o método setNome()
    std::cout << "\n--- Alterando o nome do restaurante ---\n";
    meuRestaurante.setNome("Sabor & Arte");

    // 5. Exibir novamente o nome com getNome()
    std::cout << "Novo nome do restaurante: " << meuRestaurante.getNome() << "\n";

    return 0;
}
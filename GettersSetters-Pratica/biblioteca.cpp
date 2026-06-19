#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Biblioteca {
private:
    // Atributos privados
    std::string nome;
    std::vector<std::string> livros;

public:
    // Construtor que inicializa a biblioteca com um nome
    Biblioteca(std::string nome_inicial) {
        setNome(nome_inicial);
    }

    // Getter para o nome
    std::string getNome() const {
        return nome;
    }

    // Setter para o nome com validação (string não vazia)
    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome da biblioteca não pode ser vazio.\n";
        }
    }

    // Adiciona um livro validando se não é vazio e se já não existe na lista
    void adicionarLivro(std::string titulo) {
        // Validação 1: Título inválido (vazio)
        if (titulo.empty()) {
            std::cout << "Erro: Não é possível adicionar um livro com título vazio.\n";
            return;
        }

        // Validação 2: Verificar se o livro já existe na lista
        auto it = std::find(livros.begin(), livros.end(), titulo);
        
        if (it == livros.end()) {
            livros.push_back(titulo);
            std::cout << "Livro \"" << titulo << "\" adicionado com sucesso!\n";
        } else {
            std::cout << "Erro: O livro \"" << titulo << "\" já está cadastrado nesta biblioteca.\n";
        }
    }

    // Exibe todos os livros cadastrados ou uma mensagem caso esteja vazia
    void listarLivros() const {
        std::cout << "\n--- Livros Disponíveis na " << nome << " ---\n";
        
        if (livros.empty()) {
            std::cout << "Nenhum livro cadastrado.\n";
        } else {
            for (const auto& livro : livros) {
                std::cout << "- " << livro << "\n";
            }
        }
        std::cout << "----------------------------------------\n";
    }
};

// --- Execução do Desafio Extra ---
int main() {
    // 1. Criar uma biblioteca chamada "Biblioteca Central"
    Biblioteca minhaBiblioteca("Biblioteca Central");
    std::cout << "Biblioteca criada: " << minhaBiblioteca.getNome() << "\n\n";

    // 2. Adicionar 3 livros diferentes
    minhaBiblioteca.adicionarLivro("O Senhor dos Anéis");
    minhaBiblioteca.adicionarLivro("1984");
    minhaBiblioteca.adicionarLivro("O Pequeno Príncipe");

    // 3. Tentar adicionar um livro repetido (o sistema deve impedir)
    std::cout << "\nTentando adicionar um livro repetido:\n";
    minhaBiblioteca.adicionarLivro("1984");

    // 4. Exibir a lista de livros
    minhaBiblioteca.listarLivros();

    // 5. Alterar o nome da biblioteca usando o método setNome()
    std::cout << "Alterando o nome da biblioteca...\n";
    minhaBiblioteca.setNome("Biblioteca Municipal");

    // 6. Exibir o novo nome usando getNome()
    std::cout << "Novo nome da biblioteca: " << minhaBiblioteca.getNome() << "\n";

    return 0;
}
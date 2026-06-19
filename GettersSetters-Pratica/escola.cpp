#include <iostream>
#include <string>
#include <vector>

// ==========================================
// CLASSE ALUNO
// ==========================================
class Aluno {
private:
    std::string nome;
    int idade;
    std::string curso;

public:
    // Construtor da classe Aluno
    Aluno(std::string nome_inicial, int idade_inicial, std::string curso_inicial) {
        // Inicializa passando pelas validações dos setters
        setNome(nome_inicial);
        setIdade(idade_inicial);
        setCurso(curso_inicial);
    }

    // Getters e Setters com as validações solicitadas
    std::string getNome() const { return nome; }
    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            nome = "Nome Inválido";
            std::cout << "Erro: O nome do aluno não pode ser vazio.\n";
        }
    }

    int getIdade() const { return idade; }
    void setIdade(int nova_idade) {
        if (nova_idade > 0) {
            idade = nova_idade;
        } else {
            idade = 1; // Valor padrão de fallback
            std::cout << "Erro: A idade deve ser um número maior que 0.\n";
        }
    }

    std::string getCurso() const { return curso; }
    void setCurso(std::string novo_curso) {
        if (!novo_curso.empty()) {
            curso = novo_curso;
        } else {
            curso = "Curso Inválido";
            std::cout << "Erro: O curso não pode ser vazio.\n";
        }
    }

    // Retorna a string formatada de apresentação do aluno
    std::string apresentar() const {
        return "Nome: " + nome + " | Idade: " + std::to_string(idade) + " | Curso: " + curso;
    }
};

// ==========================================
// CLASSE ESCOLA
// ==========================================
class Escola {
private:
    std::string nome;
    std::vector<Aluno> alunos; // Lista que armazena objetos da classe Aluno

public:
    // Construtor da classe Escola
    Escola(std::string nome_inicial) {
        setNome(nome_inicial);
    }

    // Getters e Setters para o nome da escola
    std::string getNome() const { return nome; }
    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome da escola não pode ser vazio.\n";
        }
    }

    // Adiciona um aluno à lista (Em C++, a tipagem estática garante que seja um objeto Aluno)
    void adicionarAluno(const Aluno& novo_aluno) {
        alunos.push_back(novo_aluno);
        std::cout << "Aluno \"" << novo_aluno.getNome() << "\" matriculado com sucesso na escola " << nome << ".\n";
    }

    // Lista todos os alunos chamando o método apresentar() de cada um
    void listarAlunos() const {
        std::cout << "\n--- Lista de Alunos Matriculados - " << nome << " ---\n";
        
        if (alunos.empty()) {
            std::cout << "Nenhum aluno matriculado.\n";
        } else {
            for (const auto& aluno : alunos) {
                std::cout << aluno.apresentar() << "\n";
            }
        }
        std::cout << "--------------------------------------------------\n";
    }
};

// ==========================================
// EXECUÇÃO DO DESAFIO EXTRA
// ==========================================
int main() {
    // 1. Crie uma escola chamada "Escola Futuro"
    Escola minhaEscola("Escola Futuro");

    // 2. Crie 2 alunos com nome, idade e curso
    Aluno aluno1("João", 20, "Informática");
    Aluno aluno2("Maria", 22, "Engenharia");

    // 3. Adicione os alunos à escola
    std::cout << "--- Efetuando Matrículas ---\n";
    minhaEscola.adicionarAluno(aluno1);
    minhaEscola.adicionarAluno(aluno2);

    // 4. Exiba a lista de alunos matriculados
    minhaEscola.listarAlunos();

    // 5. Teste alterações de atributos usando os métodos set
    std::cout << "--- Testando Alterações (Setters) ---\n";
    
    // Atualizando dados de um aluno existente
    std::cout << "Modificando dados do João...\n";
    aluno1.setIdade(21); // Nova idade válida
    aluno1.setCurso("Ciência da Computação"); // Novo curso válido
    
    // Tentando atribuição inválida para testar a proteção do encapsulamento
    aluno1.setIdade(-5); // Deve disparar mensagem de erro

    // Mostrando o resultado atualizado do aluno modificado
    std::cout << "\nDados atualizados do aluno 1:\n";
    std::cout << aluno1.apresentar() << "\n";

    return 0;
}
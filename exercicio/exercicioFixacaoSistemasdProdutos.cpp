#include <iostream>
#include <string>
#include <vector>

// Classe Base
class Produto {
protected:
    std::string nome;
    double preco;

public:
    // Construtor
    Produto(std::string n, double p) : nome(n), preco(p) {}

    virtual ~Produto() {}

    virtual void exibirDados() const {
        std::cout << "Produto: " << nome << " | Preco: R$ " << preco << std::endl;
    }
};

// Subclasse Livro 
class Livro : public Produto {
private:
    std::string autor; // Atributo específico

public:
    // Construtor que inicializa a base e o atributo próprio
    Livro(std::string n, double p, std::string a) 
        : Produto(n, p), autor(a) {}

    // Sobrescrita com override
    void exibirDados() const override {
        std::cout << "Livro: " << nome 
                  << " | Autor: " << autor 
                  << " | Preco: R$ " << preco << std::endl;
    }
};

// Subclasse Eletronico
class Eletronico : public Produto {
private:
    std::string marca; // Atributo específico

public:
    // Construtor 
    Eletronico(std::string n, double p, std::string m) 
        : Produto(n, p), marca(m) {}

    // Sobrescrita com override
    void exibirDados() const override {
        std::cout << "Eletronico: " << nome 
                  << " | Marca: " << marca 
                  << " | Preco: R$ " << preco << std::endl;
    }
};

int main() {
    // Criando 2 objetos de cada subclasse dinamicamente para o polimorfismo
    // Uso de ponteiros da classe base Produto nos permite colocar todos na mesma lista
    std::vector<Produto*> catalogo;

    // Criando os Livros
    catalogo.push_back(new Livro("O Senhor dos Aneis", 59.90, "J.R.R. Tolkien"));
    catalogo.push_back(new Livro("C++ Primordial", 120.00, "Stanley Lippman"));

    // Criando os Eletrônicos
    catalogo.push_back(new Eletronico("Smartphone Galaxy S24", 4500.00, "Samsung"));
    catalogo.push_back(new Eletronico("Notebook ThinkPad", 6200.00, "Lenovo"));

    std::cout << "--- CATALOGO DE PRODUTOS ---" << std::endl;
    for (const auto& produto : catalogo) {
        produto->exibirDados(); // Livro/Eletronico
    }

    for (auto& produto : catalogo) {
        delete produto;
    }
    catalogo.clear();

    return 0;
}
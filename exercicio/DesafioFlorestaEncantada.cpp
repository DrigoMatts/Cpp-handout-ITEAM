#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Personagem {
public:
    string nome;
    int nivelPoder;
    string tipo;

    Personagem(string n, int p, string t) : nome(n), nivelPoder(p), tipo(t) {}

    // Método virtual para permitir polimorfismo na exibição
    virtual void exibir() {
        cout << "Nome: " << nome << " | Tipo: " << tipo << " | Poder: " << nivelPoder << endl;
    }

    virtual ~Personagem() {}
};

class Chefe : public Personagem {
public:
    string reino;

    Chefe(string n, int p, string t, string r) : Personagem(n, p, t), reino(r) {}

    void exibir() override {
        cout << "[CHEFE] Nome: " << nome << " | Tipo: " << tipo 
             << " | Poder: " << nivelPoder << " | Reino: " << reino << endl;
    }
};

struct No {
    Personagem* p;
    No *esquerda, *direita;

    No(Personagem* person) : p(person), esquerda(nullptr), direita(nullptr) {}
};

// Função para inserir personagens na Árvore Binária de Busca (BST)
No* inserir(No* raiz, Personagem* p) {
    if (raiz == nullptr) return new No(p);

    if (p->nivelPoder < raiz->p->nivelPoder)
        raiz->esquerda = inserir(raiz->esquerda, p);
    else
        raiz->direita = inserir(raiz->direita, p);

    return raiz;
}

// Função para percorrer em ordem (Do menos poderoso para o mais poderoso)
void percorrerEmOrdem(No* raiz) {
    if (raiz != nullptr) {
        percorrerEmOrdem(raiz->esquerda);
        raiz->p->exibir();
        percorrerEmOrdem(raiz->direita);
    }
}

int main() {
    No* floresta = nullptr;

    // Adicionando 6 personagens (incluindo 2 Chefes)
    floresta = inserir(floresta, new Personagem("Lupi", 15, "Animal"));
    floresta = inserir(floresta, new Personagem("Mago Merlin", 80, "Mago"));
    floresta = inserir(floresta, new Chefe("Dragão Ancestral", 150, "Fera", "Cavernas"));
    floresta = inserir(floresta, new Personagem("Globin", 5, "Monstro"));
    floresta = inserir(floresta, new Chefe("Rainha Élfica", 120, "Elfo", "Floresta Alta"));
    floresta = inserir(floresta, new Personagem("Arqueiro", 45, "Humano"));

    cout << "--- Personagens da Floresta Encantada (Ordem de Poder) ---\n" << endl;
    percorrerEmOrdem(floresta);

    return 0;
}

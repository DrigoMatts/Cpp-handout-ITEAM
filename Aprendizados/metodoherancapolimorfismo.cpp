#include <iostream>
#include <string>

using namespace std;

class Pessoa {
protected:
    string nome;

public:
    Pessoa(string n) : nome(n) {}
    
    virtual ~Pessoa() = default; 

    virtual void falar() { 
        cout << nome << " esta falando." << endl;
    }
};

class Professor : public Pessoa {
private:
    string disciplina;

public:
    Professor(string n, string d) : Pessoa(n), disciplina(d) {}

    void falar() override { 
        cout << "Professor(a) " << nome << " esta ensinando " << disciplina << "." << endl;
    }
};

class Aluno : public Pessoa {
private:
    int matricula;

public:
    Aluno(string n, int m) : Pessoa(n), matricula(m) {}

    void falar() override {
        cout << "Aluno(a) " << nome << " (matricula: " << matricula << ") esta aprendendo." << endl;
    }
};

void fazerFalar(Pessoa* p) {
    if (p != nullptr) {
        p->falar(); 
    }
}

int main() {
    cout << "--- Objetos na Stack ---" << endl;
    Pessoa p("Maria");
    Professor prof("Carlos", "Matematica");
    Aluno aluno("Ana", 101);

    p.falar();
    prof.falar();
    aluno.falar();

    cout << "\n--- Objetos na Heap (Polimorfismo com Ponteiros) ---" << endl;

    Pessoa* p1 = new Pessoa("Joao");
    Pessoa* p2 = new Professor("Ricardo", "Fisica");
    Pessoa* p3 = new Aluno("Marina", 202);

    fazerFalar(p1);
    fazerFalar(p2);
    fazerFalar(p3);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
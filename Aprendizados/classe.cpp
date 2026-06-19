    #include <iostream>
    #include <string>

    class Gato { 
    private:
        std::string nome;

    public:
        Gato(std::string nome) {
            this ->nome = nome;
        }

        void miar(){
            std::cout <<this->nome << "Diz: miau miau!" <<std::endl;
        }

    };

    int main() { 
    Gato c1(" Garfield ");
    Gato c2(" Larry ");

    c1.miar();
    c2.miar();

    return 0;
    }
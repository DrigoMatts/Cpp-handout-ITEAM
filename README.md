# ⚽ Simulador de Apostas & Aprendizados em C++ 🚀

Bem-vindo ao repositório **Cpp-handout-ITEAM**! Este espaço foi desenvolvido para consolidar os aprendizados práticos e teóricos na linguagem C++, cobrindo desde a lógica de programação essencial e manipulação de memória até os pilares da Programação Orientada a Objetos (POO), culminando no projeto prático de um **Sistema de Apostas / Bolão de Futebol**.

---

## 📂 Estrutura do Repositório

O projeto está dividido de forma organizada em pastas para separar os conceitos fundamentais das aplicações práticas:

### 1. 📂 `Aprendizados/`
Esta pasta contém a base dos estudos de sintaxe, lógica, ponteiros e os primeiros passos em POO:
* **`hello.cpp`** • O clássico ponto de partida para testar o ambiente.
* **`idade.cpp` & `tabuada.cpp`** • Exercícios práticos aplicando estruturas condicionais e laços de repetição (loops).
* **`vetores.cpp`** • Manipulação e estruturação de dados em arrays/vetores.
* **`TrocaDValores.cpp` & `ponteirosexvalores.cpp`** • Diferença entre passagem de parâmetros por valor, por referência e manipulação de ponteiros.
* **`memoria.cpp` & `memoria.txt`** • Estudos e anotações sobre alocação de memória.
* **`classe.cpp`** • Primeiros passos na criação de classes, atributos e objetos.
* **`semEncapsamento.cpp` vs `comEncapsamento.cpp`** • Um comparativo didático demonstrando o risco de expor dados e a necessidade de proteger os atributos.
* **`GettersSetters.cpp`** • Implementação correta dos métodos de acesso e modificação de atributos.
* **`forma_geometrica.cpp`** • Prática de abstração modelando formas e suas propriedades.
* **`cachorroheranca.cpp`** • Exemplo clássico e simples aplicando o pilar de Herança.
* **`metodoherancapolimorfismo.cpp`** • Conceito avançado combinando Herança e Polimorfismo na prática.

### 2. 📂 `GettersSetters-Pratica/`
Exercícios focados estritamente na fixação de encapsulamento (`getters` e `setters`) através da modelagem de cenários reais:
* **`biblioteca.cpp`** • Controle de acervo, livros e empréstimos.
* **`escola.cpp`** • Gerenciamento de alunos, turmas e notas.
* **`restaurante.cpp`** • Administração de mesas, cardápios e pedidos.

### 3. 🏆 Projeto Prático: Simulador de Apostas (Bolão)
O grande destaque do repositório é o sistema que simula a validação de palpites para rodadas de futebol internacional, computando a pontuação com base nos resultados oficiais.

#### 💡 Lógica Criativa com Ponto Flutuante (`float`)
Para armazenar os placares de maneira enxuta, o sistema utiliza números do tipo `float`, onde:
* A **parte inteira** indica os gols do time **mandante** (casa).
* A **parte decimal** indica os gols do time **visitante** (fora).

> 📌 **Exemplo Prático:** > * Um placar `3.0` significa **3 x 0** para o mandante.
> * Um palpite de `1.2` significa **1 x 2** para o visitante.

#### 📝 Regras de Pontuação
O programa calcula o desempenho do apostador e distribui os pontos seguindo este critério:

| Condição de Acerto | Pontuação | Descrição |
| :--- | :---: | :--- |
| **Placar Exato** | `+10 pontos` | O apostador acertou em cheio a quantidade de gols de ambos os times. |
| **Tendência de Vitória** | `+5 pontos` | Errou o placar exato, mas acertou o vencedor (ou se terminou em empate). |
| **Erro Total** | `0 pontos` | O apostador errou tanto o vencedor quanto a quantidade de gols. |

---

## ⚙️ Como Executar o Projeto

Siga as instruções abaixo para configurar, compilar e rodar qualquer um dos arquivos na sua máquina local:

### 1. Pré-requisitos
Antes de começar, certifique-se de possuir um compilador de C++ instalado no seu sistema operativo (como o `g++`).

### 2. Clonar o Repositório
Abra o seu terminal e execute o comando:
```bash
git clone [https://github.com/seu-usuario/nome-do-repositorio.git](https://github.com/seu-usuario/nome-do-repositorio.git)
```

### 3. Compilar o Arquivo

Navegue até o diretório do arquivo que deseja testar e compile-o através do terminal. Por exemplo, para compilar o sistema de apostas (`aposta.cpp`):


### 4. Executar o Programa
Após gerar o executável, basta rodar o comando:
g++ -o programa aposta.cpp

```bash
./programa
```

### 👥 Contribuidores do Projeto Bolão 

Este projeto foi desenvolvido de forma totalmente colaborativa pelos seguintes desenvolvedores:

* 🧑‍💻 Gabriel Leal

* 🧑‍💻 Guilherme Cavalcante

* 🧑‍💻 Rodrigo Matos

Pronto para palpitar e gerenciar os pontos do seu bolão! 🏆
---

*Boa Vista, RR — ITEAM 2026*

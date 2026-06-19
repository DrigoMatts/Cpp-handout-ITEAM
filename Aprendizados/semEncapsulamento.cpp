#include <iostream>

using namespace std;

class ContaBancaria {

public:
    string titular;
    double saldo;

};

int main () {
    ContaBancaria conta;
    conta.titular = "joão";
    conta.saldo = 1000.0;

    conta.saldo = -500.0;
    cout << "Saldo: " << conta.saldo << endl;

    return 0;
}
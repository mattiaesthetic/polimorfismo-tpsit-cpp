#include <iostream>
#include <string>
using namespace std;

class Veicolo {
public:
    virtual ~Veicolo() = default;
    virtual void muovi() const = 0;
    virtual void descrizione() const = 0;
};

class Auto : public Veicolo {
public:
    void muovi() const override { cout << "L'auto accelera sull'asfalto\n"; }
    void descrizione() const override { cout << "Auto: 4 ruote, motore a combustione\n"; }
};

class Bicicletta : public Veicolo {
public:
    void muovi() const override { cout << "La bicicletta avanza pedalando\n"; }
    void descrizione() const override { cout << "Bicicletta: 2 ruote, huss huss huss\n"; }
};

class Treno : public Veicolo {
public:
    void muovi() const override { cout << "Il treno parte dal binario\n"; }
    void descrizione() const override { cout << "Treno: composto da vagoni, viaggia su rotaia\n"; }
};

int main() {
    Veicolo* a = new Auto();
    Veicolo* b = new Bicicletta();
    Veicolo* t = new Treno();

    Veicolo* veicoli[] = {a, b, t};
    for (Veicolo* v : veicoli) {
        v->descrizione();
        v->muovi();
        cout << '\n';
    }

    delete a;
    delete b;
    delete t;
    return 0;
}
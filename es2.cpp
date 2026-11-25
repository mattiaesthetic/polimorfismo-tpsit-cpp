#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Personaggio {
protected:
    string nome;
public:
    explicit Personaggio(string n) : nome(std::move(n)) {}
    virtual ~Personaggio() = default;
    virtual void attacca() const = 0;
    virtual void presentati() const = 0;
};

class Guerriero : public Personaggio {
public:
    using Personaggio::Personaggio;
    void presentati() const override { cout << "Sono " << nome << ", guerriero dalla spada enorme.\n"; }
    void attacca() const override { cout << nome << " sferra un colpo di spadone!\n"; }
};

class Mago : public Personaggio {
public:
    using Personaggio::Personaggio;
    void presentati() const override { cout << "Sono " << nome << ", mago delle non due, non tre ma ben cinque magie.\n"; }
    void attacca() const override { cout << nome << " lancia sette palle di fuoco!\n"; }
};

class Arciere : public Personaggio {
public:
    using Personaggio::Personaggio;
    void presentati() const override { cout << "Sono " << nome << ", arciere dall'occhio infallibile.\n"; }
    void attacca() const override { cout << nome << " someday somehow i'm going to scoccare una freccia!\n"; }
};

void turno(Personaggio* p) {
    p->presentati();
    p->attacca();
    cout << '\n';
}

int main() {
    vector<Personaggio*> party = {
        new Guerriero("Guts"),
        new Mago("Ciccio"),
        new Arciere("Parrot"),
        new Mago("Joker"),
        new Guerriero("Ichigo")
    };

    cout << "Inizio del round\n\n";
    for (Personaggio* p : party)
        turno(p);

    for (Personaggio* p : party)
        delete p;
    return 0;
}
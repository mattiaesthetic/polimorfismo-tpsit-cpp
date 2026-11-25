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
    void presentati() const override { cout << "Sono " << nome << ", guerriero dalla spada affilata.\n"; }
    void attacca() const override { cout << nome << " sferra un colpo di spada!\n"; }
};

class Mago : public Personaggio {
public:
    using Personaggio::Personaggio;
    void presentati() const override { cout << "Sono " << nome << ", mago dei sette sigilli.\n"; }
    void attacca() const override { cout << nome << " lancia una palla di fuoco!\n"; }
};

class Arciere : public Personaggio {
public:
    using Personaggio::Personaggio;
    void presentati() const override { cout << "Sono " << nome << ", arciere dall'occhio infallibile.\n"; }
    void attacca() const override { cout << nome << " scocca una freccia!\n"; }
};
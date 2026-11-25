#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class MetodoPagamento {
public:
    virtual ~MetodoPagamento() = default;
    virtual void paga(double importo) const = 0;

    void pagaConCommissione(double importo, double percCommissione) const {
        double commissione = importo * percCommissione / 100.0;
        double totale = importo + commissione;
        cout << "Importo " << importo << "euro + commissione "
             << percCommissione << "% (" << commissione << "euro) -> totale "
             << totale << "euro\n";
        paga(totale);
    }
};

class CartaCredito : public MetodoPagamento {
public:
    void paga(double importo) const override {
        cout << "Pagato " << importo << "euro con carta di credito\n";
    }
};

class PayPal : public MetodoPagamento {
public:
    void paga(double importo) const override {
        cout << "Pagato " << importo << "euro tramite account PayPal\n";
    }
};

class Contanti : public MetodoPagamento {
public:
    void paga(double importo) const override {
        cout << "Pagato " << importo << "euro in contanti\n";
    }
};

int main() {
    cout << fixed << setprecision(2);

    vector<MetodoPagamento*> metodi = {
        new CartaCredito(), new PayPal(), new Contanti()
    };
    vector<double> commissioni = {1.5, 3.0, 0.0};

    for (size_t i = 0; i < metodi.size(); ++i) {
        metodi[i]->pagaConCommissione(100.0, commissioni[i]);
        cout << '\n';
    }

    for (auto* m : metodi) delete m;
    return 0;
}
//
// Created by matti on 25/11/2026.
//

#include "Veicolo.h"

#include <iostream>
#include <string>
using namespace std;

class Veicolo {
public:
    virtual ~Veicolo() = default;          // distruttore virtuale: indispensabile con delete via puntatore base
    virtual void muovi() const = 0;
    virtual void descrizione() const = 0;
};
#ifndef MANO_H
#define MANO_H

#include <iostream>
#include <vector>
#include "./Carta.h"

using namespace std;

class Mano {
public:
    vector<Carta> cartas;

    void agregarCarta(Carta carta);
    void mostrar();
    Carta jugarCarta(int index);
    
};

#endif // MANO_H
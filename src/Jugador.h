#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include "./Mano.h"

using namespace std;

class Jugador {
public:
    string nombre;
    Mano mano;
    int rondasGanadas;

    Jugador(string n);
    void mostrarCartas();
    Carta jugarCarta(int index);
};

#endif // JUGADOR_H
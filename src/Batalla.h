#ifndef BATALLA_H
#define BATALLA_H

#include <iostream>
#include <vector>
#include "./Jugador.h"

using namespace std;

class Batalla {
public:
    int jugarRonda(vector<Jugador>& jugadores, int& jugadorActual); // Cambiar a pasar por referencia
};

#endif // BATALLA_H
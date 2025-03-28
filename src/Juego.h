#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./Mazo.h"
#include "./Jugador.h"
#include "./Batalla.h"

using namespace std;

class Juego {
private:
    Mazo mazo;
    vector<Jugador> jugadores;
    Batalla batalla;
    int rondas;
    int jugadorActual; 

public:
    Juego(vector<string> nombres);
    void repartirCartas();
    void jugar();
    void mostrarGanador();
};

#endif // JUEGO_H
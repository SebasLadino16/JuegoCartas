#include "./Jugador.h"

Jugador::Jugador(string n) {
    this->nombre = n;
    this->rondasGanadas = 0;
}

void Jugador::mostrarCartas() {
    cout << nombre << " tiene las siguientes cartas:" << endl;
    mano.mostrar();
}

Carta Jugador::jugarCarta(int index) {
    return mano.jugarCarta(index);
}
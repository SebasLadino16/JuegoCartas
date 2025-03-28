#include "./Carta.h"

Carta::Carta()
{
    this->poder = 0;
    this->color = 0;
    this->estado = false; // Inicialmente, la carta está disponible
}

Carta::Carta(int poder, int color)
{
    this->poder = poder;
    this->color = color;
    this->estado = false; // Inicialmente, la carta está disponible
}

void Carta::mostrar() {
    if (estado) {
        cout << WHITE << "X" << RESET << " "; // Mostrar como "X" si la carta ha sido jugada
    } else {
        cout << paleta[color] << poder << RESET << " "; // Mostrar el poder de la carta
    }
}
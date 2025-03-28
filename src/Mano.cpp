#include "./Mano.h"

void Mano::agregarCarta(Carta carta) {
    cartas.push_back(carta);
}

void Mano::mostrar() {
    for (size_t i = 0; i < cartas.size(); i++) {
        cout << i + 1 << ": ";
        cartas[i].mostrar();
    }
}

Carta Mano::jugarCarta(int index) {
    if (index < 0 || index >= cartas.size()) {
        throw std::out_of_range("Índice fuera de rango al jugar la carta.");
    }
    
    // Verifica si la carta ya ha sido jugada
    if (cartas[index].estado) {
        throw std::invalid_argument("Esta carta ya fue usada. Intenta jugar otra carta.");
    }

    Carta carta = cartas[index];
    cartas[index].estado = true; // Marcar la carta como jugada
    return carta;
}
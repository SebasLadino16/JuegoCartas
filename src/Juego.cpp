#include "./Juego.h"

Juego::Juego(vector<string> nombres) : rondas(0), jugadorActual(0) { // Inicializa jugadorActual
    for (const auto& nombre : nombres) {
        jugadores.emplace_back(nombre);
    }
    mazo.barajar();
    repartirCartas();
}

void Juego::repartirCartas() {
    for (int i = 0; i < 9; i++) {
        for (auto& jugador : jugadores) {
            Carta cartaRepartida = mazo.repartir();
            jugador.mano.agregarCarta(cartaRepartida);
        }
    }
}

void Juego::jugar() {
    while (rondas < 9) {
        cout << "Ronda " << rondas + 1 << endl;
        jugadorActual = batalla.jugarRonda(jugadores, jugadorActual); // Obtener el índice del ganador

        rondas++;

        // Verificar si algún jugador ha ganado 5 rondas
        for (const auto& jugador : jugadores) {
            if (jugador.rondasGanadas >= 5) {
                cout << jugador.nombre << " ha ganado 5 rondas y es el ganador del juego!" << endl;
                return;
            }
        }
    }
    mostrarGanador();
}

void Juego::mostrarGanador() {
    Jugador* ganador = nullptr;
    for (auto& jugador : jugadores) {
        if (ganador == nullptr || jugador.rondasGanadas > ganador->rondasGanadas) {
            ganador = &jugador;
        }
    }
    if (ganador) {
        cout << "El ganador del juego es: " << ganador->nombre << " con " << ganador->rondasGanadas << " rondas ganadas!" << endl;
    }
}
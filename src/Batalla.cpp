#include "./Batalla.h"
#include "./Carta.h" 

int Batalla::jugarRonda(vector<Jugador>& jugadores, int& jugadorActual) {
    Palo paloActual;
    Carta cartaGanadora(0, -1); // Inicializa con una carta de poder 0
    Jugador* ganador = nullptr;
    int ganadorIndex = -1; // Inicializa el índice del ganador

    for (int i = 0; i < jugadores.size(); i++) {
        int jugadorIndex = (jugadorActual + i) % jugadores.size();
        Jugador& jugador = jugadores[jugadorIndex];

        jugador.mostrarCartas();
        
        // Mostrar índices disponibles
        cout << jugador.nombre << ", selecciona una carta (";
        for (size_t j = 0; j < jugador.mano.cartas.size(); j++) {
            if (jugador.mano.cartas[j].estado) {
                cout << "X"; // Marcar como jugada
            } else {
                cout << (j + 1); // Mostrar índice
            }
            if (j < jugador.mano.cartas.size() - 1) {
                cout << ", "; 
            }
        }
        cout << "): ";

        int seleccion;
        cin >> seleccion;
        seleccion--; // Ajustar a índice 0

        // Declaración de cartaJugando fuera del bloque try
        Carta cartaJugando;

        // Validar la selección
        while (true) {
            try {
                // Intentar jugar la carta
                cartaJugando = jugador.jugarCarta(seleccion);
                cout << jugador.nombre << " juega: ";
                cartaJugando.mostrar();
                cout << "\n"; 
                break; // Para poder salir del bucle si se juega la carta correctamente
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl; // Mostrar mensaje de error
                cout << "Selecciona otra carta (";
                for (size_t j = 0; j < jugador.mano.cartas.size(); j++) {
                    if (jugador.mano.cartas[j].estado) {
                        cout << "X"; // Marcar como jugada
                    } else {
                        cout << (j + 1); // Mostrar índice
                    }
                    if (j < jugador.mano.cartas.size() - 1) {
                        cout << ", "; // Separar con comas
                    }
                }
                cout << "): ";
                cin >> seleccion;
                seleccion--; // Ajustar a índice 0
            }
        }

        // Bloque pra determinar si gana la ronda
        if (i == 0) {
            paloActual = static_cast<Palo>(cartaJugando.color);
            cartaGanadora = cartaJugando;
            ganador = &jugador;
            ganadorIndex = jugadorIndex; // Guarda el índice del ganador
        } else {
            if (cartaJugando.color == paloActual && cartaJugando.poder > cartaGanadora.poder) {
                cartaGanadora = cartaJugando;
                ganador = &jugador;
                ganadorIndex = jugadorIndex; // Guarda el índice del ganador
            }
        }
    }

    if (ganador) {
        cout << "\nEl ganador de la ronda es: " << ganador->nombre << "\n";
        ganador->rondasGanadas++;
    }

    return ganadorIndex; // Devolver el índice del jugador que ganó
}
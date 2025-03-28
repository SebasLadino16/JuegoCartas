#include <iostream>
#include <vector>
#include "./Juego.h"

using namespace std;

int main() {
    srand(time(NULL));

    vector<string> nombres = {"Jugador 1", "Jugador 2", "Jugador 3", "Jugador 4"};
    Juego juego(nombres);
    juego.jugar();

    return 0;
}
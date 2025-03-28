#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>

using namespace std;

#define BG_RED "\x1B[41m"
#define BG_BLUE "\x1B[44m"
#define BG_GREEN "\x1B[42m"
#define BG_BLACK "\x1B[40m"
#define WHITE "\x1B[37m"
#define RESET "\x1b[0m"

enum Palo { ROJO, VERDE, AZUL, NEGRO }; 

class Carta {
public:
    string paleta[4] = {BG_RED, BG_BLUE, BG_BLACK, BG_GREEN};
    int poder;
    int color; // 0: Rojo, 1: Verde, 2: Azul, 3: Negro
    bool estado;// true si la carta ha sido jugada, false si está disponible

    Carta();
    Carta(int poder, int color);
    void mostrar();
};

#endif // CARTA_H
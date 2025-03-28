#include "./Carta.h"
#include <iostream>
using namespace std;

class Mazo
{
    public:
        int n = 35;        //n es el indice de cada carta
        Carta Cartas[36];
        Mazo();
        void barajar();
        Carta repartir();
        void mostrar();
};
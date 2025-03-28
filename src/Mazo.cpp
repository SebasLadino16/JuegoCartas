#include "./Mazo.h"
//#include <stdexcept>

Mazo::Mazo()
{
    int indice = 0;
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            indice = (4*i) + j;
            Cartas[indice].poder = i + 1;
            Cartas[indice].color = j;
        }
    }
}


void Mazo::barajar()
{
    Carta temporal;
    int indiceUno;
    int indiceDos;
    
    for(int i = 0; i < 50; i++)
    {
        indiceUno = rand()%36;
        indiceDos = rand()%36;
        
        temporal = Cartas[indiceUno];
        Cartas[indiceUno] = Cartas[indiceDos];
        Cartas[indiceDos] = temporal;
        
    }
    
}

Carta Mazo::repartir()
{
    if (n >= 0) 
    { 
        Carta cartaRepartida = Cartas[n];
        n--;
        return cartaRepartida;
    } 
    else 
    {
        return Carta(); // Si no hay cartas disponibles, devolvemos una carta vacía
    } 
 
}

void Mazo::mostrar() {
    int indice = 0;
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            indice = (4 * i) + j;
            Cartas[indice].mostrar();
        }
    }
}
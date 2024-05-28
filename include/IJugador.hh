#ifndef IJUGADOR_HH
#define IJUGADOR_HH
#include <string>

using namespace std;

class IJugador{
    public:
    IJugador(string nombre, bool primerJugador): nombre(nombre), primerJugador(primerJugador){}
    string nombre;
    int partidasGanadas;
    bool primerJugador;
};
#endif
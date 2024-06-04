#ifndef IAAVANZADA_HH
#define IAAVANZADA_HH
#include <IJugador.hh>
#include <string>
#include <Tablero.hh>
#include <array>

using namespace std;

class IAAvanzada : public IJugador{
    public:
    IAAvanzada(string nombre, bool primerJugador, int maxDepth);
    int movimientoIA(Tablero tablero);
    array<int, 2> miniMax(Tablero &tablero, int depth, int alpha, int beta, char player);
    int maxDepth;
    char jugadorHumano;
    char computadora;
};
#endif
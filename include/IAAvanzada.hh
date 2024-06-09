#ifndef IAAVANZADA_HH
#define IAAVANZADA_HH
#include <IJugador.hh>
#include <Tablero.hh>
#include <array>
#include <string>

using namespace std;

class IAAvanzada : public IJugador {
 public:
  IAAvanzada(string nombre, bool primerJugador);
  int movimientoIA(Tablero tablero);
  array<int, 2> miniMax(Tablero &tablero, int depth, int alpha, int beta,
                        Color player);
  int maxDepth;
  int maximizeOrMinimize;
  Color jugadorHumano;
  Color computadora;
};
#endif
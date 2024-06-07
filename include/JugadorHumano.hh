#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH
#include <IJugador.hh>
#include <random>
#include <string>

using namespace std;

class JugadoHumano : public IJugador {
 public:
  JugadoHumano(string nombre, bool primerJugador);
  Color fichaJugador;
};
#endif
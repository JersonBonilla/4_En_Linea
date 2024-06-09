#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH
#include <IJugador.hh>
#include <random>
#include <string>

using namespace std;

class JugadorHumano : public IJugador {
 public:
  JugadorHumano(string nombre, bool primerJugador);
  Color fichaJugador;
};
#endif
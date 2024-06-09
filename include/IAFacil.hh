#ifndef IAFACIL_HH
#define IAFACIL_HH
#include <IJugador.hh>
#include <Tablero.hh>
#include <string>

using namespace std;

class IAFacil : public IJugador {
 public:
  IAFacil(string nombre, bool primerJugador);
  int movimientoIA(Tablero &tablero);
  Color fichaIA;
};
#endif
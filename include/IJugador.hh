#ifndef IJUGADOR_HH
#define IJUGADOR_HH
#include <string>
#include <Tablero.hh>

using namespace std;

class IJugador {
 public:
  IJugador(string nombre, bool primerJugador)
      : nombre(nombre), primerJugador(primerJugador) {}
  int getPartidasGanadas() { return partidasGanadas; }
  string getNombre() { return nombre; }
  bool getPrimerJugador() { return primerJugador; }
  void incrementarPartidasGanadas() { partidasGanadas++; }
  virtual int movimientoIA(Tablero &tablero) { return 0; }

 protected:
  int partidasGanadas = 0;
  string nombre;
  bool primerJugador;
};
#endif
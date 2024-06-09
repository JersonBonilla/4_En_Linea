#ifndef IJUGADOR_HH
#define IJUGADOR_HH
#include <string>

using namespace std;

enum Color { VACIO = 0, AMARILLO = 1, ROJO = 2, PRUEBA = 3 };

class IJugador {
 public:
  IJugador(string nombre, bool primerJugador)
      : nombre(nombre), primerJugador(primerJugador) {}
  int getPartidasGanadas() { return partidasGanadas; }
  string getNombre() { return nombre; }
  bool getPrimerJugador() { return primerJugador; }
  void incrementarPartidasGanadas() { partidasGanadas++; }

 protected:
  int partidasGanadas = 0;
  string nombre;
  bool primerJugador;
};
#endif
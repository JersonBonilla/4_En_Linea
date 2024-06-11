#include <JugadorHumano.hh>

/*Constructor of class JugadorHumano, the parameters asked for are string name
and bool primerJugador.
*/
JugadorHumano::JugadorHumano(string nombre, bool primerJugador)
    : IJugador(nombre, primerJugador) {
  if (primerJugador) {
    fichaJugador = Color::AMARILLO;
  } else {
    fichaJugador = Color::ROJO;
  }
}

int JugadorHumano::movimientoIA(Tablero &tablero) {
  return -1;
}
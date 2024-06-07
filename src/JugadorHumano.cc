#include <JugadorHumano.hh>

/*Constructor of class JugadorHumano, the parameters asked for are string name
and bool primerJugador.
*/
JugadoHumano::JugadoHumano(string nombre, bool primerJugador)
    : IJugador(nombre, primerJugador) {
  if (primerJugador) {
    fichaJugador = Color::AMARILLO;
  } else {
    fichaJugador = Color::ROJO;
  }
}
#include <time.h>

#include <IAFacil.hh>
#include <Tablero.hh>
#include <iostream>
#include <random>

using namespace std;
/*Constructor of class IAFacil, the parameters asked for are string name and
bool primerJugador.
*/
IAFacil::IAFacil(string nombre, bool primerJugador)
    : IJugador(nombre, primerJugador) {
  if (primerJugador) {
    fichaIA = Color::AMARILLO;
  } else {
    fichaIA = Color::ROJO;
  }
}

// Makes a random moves and returns it if its valid.
int IAFacil::movimientoIA(Tablero &tablero) {
  int numberoColumnas = tablero.getColumnas() - 1;
  int movimientoRandom = 0;
  while (true) {
    movimientoRandom = rand() % (numberoColumnas + 1);
    if (!tablero.validarMovimiento(movimientoRandom)) {
      continue;
    } else {
      break;
    }
  }
  return movimientoRandom;
}
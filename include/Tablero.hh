#ifndef TABLERO_HH
#define TABLERO_HH
#include <IJugador.hh>
#include <string>
#include <vector>
using namespace std;

class Tablero {
 public:
  Tablero(int filas, int columnas);
  vector<vector<Color>> getTableroPrivado();
  bool validarMovimiento(int columna);
  void LlenarCasilla(int columna, Color ficha);
  bool ComprobarGanador(Color ficha);
  bool ComprobarEmpate();
  int getFilas();
  int getColumnas();
  int getCasillasDisponibles();
  int getTurnos();
  Color getJugador1();
  Color getJugador2();
  Color getFichaVacia();
  void limpiarTablero();

 private:
  int filas;
  int columnas;
  int casillasDisponibles;
  vector<vector<Color>> tableroPrivado;
  int turnos = 0;
  Color jugador1 = Color::AMARILLO;
  Color jugador2 = Color::ROJO;
  Color fichaVacia = Color::VACIO;
};
#endif
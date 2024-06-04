#ifndef TABLERO_HH
#define TABLERO_HH
#include <string>
#include <vector>
using namespace std;

class Tablero {
 public:
  Tablero(int filas, int columnas, char jugador1, char jugador2);
  vector<vector<char>> getTableroPrivado();
  void setTableroPrivado(vector<vector<char>> nuevoTableroPrivado);
  bool validarMovimiento(int columna);
  void LlenarCasilla(int columna, char ficha);
  bool ComprobarGanador(char ficha);
  bool ComprobarEmpate();
  int getFilas();
  int getColumnas();
  int getCasillasDisponibles();
  char getJugador1();
  char getJugador2();
  int getTurnos();
  void aumentarTurnosEn1();

 private:
  int filas;
  int columnas;
  int casillasDisponibles;
  vector<vector<char>> tableroPrivado;
  char jugador1;
  char jugador2;
  int turnos = 0;
};
#endif
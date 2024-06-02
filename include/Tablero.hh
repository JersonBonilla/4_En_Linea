#ifndef TABLERO_HH
#define TABLERO_HH
#include <string>
#include <vector>
using namespace std;

class Tablero {
 public:
  Tablero(int filas, int columnas);
  vector<vector<char>> getTableroPrivado();
  bool validarMovimiento(int columna);
  void LlenarCasilla(int columna, char ficha);
  bool ComprobarGanador(char ficha);
  bool ComprobarEmpate();
  int getFilas();
  int getColumnas();
  int getCasillasDisponibles();

 private:
  int filas;
  int columnas;
  int casillasDisponibles;
  vector<vector<char>> tableroPrivado;
};
#endif
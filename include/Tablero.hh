#ifndef TABLERO_HH
#define TABLERO_HH
#include <string>
#include <vector>
using namespace std;

enum Color { VACIO = 0, AMARILLO = 1, ROJO = 2, PRUEBA = 3 };

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
  void limpiarTablero();
  int getUltimaFila();
  int getUltimaColumna();

 private:
  int filas;
  int columnas;
  int casillasDisponibles;
  vector<vector<Color>> tableroPrivado;
  int turnos = 0;
  int ultimaFila;
  int ultimaColumna;
};
#endif
#ifndef TABLERO_HH
#define TABLERO_HH
#include <string>
#include <vector>
using namespace std;

class Tablero {
 public:
  Tablero(int filas, int columnas);
  vector<vector<char>> getTableroPrivado();
  void setTableroPrivado(vector<vector<char>> tableroActualizado);
  void LlenarCasilla(int columna, vector<vector<char>> tableroPublico,
                     char ficha);
  bool ComprobarGanador(vector<vector<char>> tableroPublico, char ficha);
  bool ComprobarEmpate(vector<vector<char>> tableroPublico);
  int getFilas();
  int getColumnas();

 private:
  int filas;
  int columnas;
  vector<vector<char>> tableroPrivado;
};
#endif
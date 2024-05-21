#include <Tablero.hh>
using namespace std;

/*Constructor of class Tablero, the parameters asked for are int filas and int
columnas. Assigns to filas and columnas their respective values and creates a
new vector where every value is another vector. This one is then assigned to
tableroPrivado.
*/
Tablero::Tablero(int filas, int columnas) : filas(filas), columnas(columnas) {
  vector<vector<char>> nuevoTablero(filas, vector<char>(columnas, '0'));
  tableroPrivado = nuevoTablero;
}

// Returns tableroPrivado.
vector<vector<char>> Tablero::getTableroPrivado() { return tableroPrivado; }

// Sets tableroActualizado to tableroPrivado.
void Tablero::setTableroPrivado(vector<vector<char>> tableroActualizado) {
  tableroPrivado = tableroActualizado;
}

// Fills the specific space of the column in n with char ficha only if its
// available.
void Tablero::LlenarCasilla(int columna, vector<vector<char>> tableroPublico,
                            char ficha) {
  for (int f = filas; f >= 0; f--) {
    bool casillaOcupada = false;
    if (tableroPublico[f][columna] != '0') {
      casillaOcupada = true;
    } else {
      tableroPublico[f][columna] = ficha;
      f = -1;
    }
  }
}

// Check if someone has already won by connecting four in a row.
bool Tablero::ComprobarGanador(vector<vector<char>> tableroPublico,
                               char ficha) {
  // Check horizontal spaces
  for (int f = 0; f < filas; f++) {
    int contador = 0;
    for (int c = 0; c < columnas; c++) {
      if (tableroPublico[f][c] == ficha) {
        contador++;
        if (contador == 4) {
          return true;
        }
      } else {
        contador = 0;
      }
    }
  }

  // Check vertical spaces
  for (int c = 0; c < columnas; c++) {
    int contador = 0;
    for (int f = 0; f < filas; f++) {
      if (tableroPublico[f][c] == ficha) {
        contador++;
        if (contador == 4) {
          return true;
        }
      } else {
        contador = 0;
      }
    }
  }

  // Check diagonal spaces (Top right to bottom left)
  for (int f = 0; f < filas - 3; f++) {
    for (int c = 3; c < columnas; c++) {
      if (tableroPublico[f][c] == ficha &&
          tableroPublico[f + 1][c - 1] == ficha &&
          tableroPublico[f + 2][c - 2] == ficha &&
          tableroPublico[f + 3][c - 3] == ficha) {
        return true;
      }
    }
  }

  // Check diagonal spaces (Top left to bottom right)
  for (int f = 0; f < filas - 3; f++) {
    for (int c = 0; c < columnas - 3; c++) {
      if (tableroPublico[f][c] == ficha &&
          tableroPublico[f + 1][c + 1] == ficha &&
          tableroPublico[f + 2][c + 2] == ficha &&
          tableroPublico[f + 3][c + 3] == ficha) {
        return true;
      }
    }
  }
  return false;
}

// Checks if a draw has happened.
bool Tablero::ComprobarEmpate(vector<vector<char>> tableroPublico) {
  int contadorEmpate = 0;
  int numeroCasillasTotales = filas * columnas;
  for (int f = 0; f < tableroPublico.size(); f++) {
    for (int c = 0; c < tableroPublico[f].size(); c++) {
      if (tableroPrivado[f][c] != '0') {
        contadorEmpate++;
      }
      if (contadorEmpate == numeroCasillasTotales) {
        return true;
      }
    }
  }
  return false;
}

// Returns the value of filas.
int Tablero::getFilas() { return filas; }

// Returns the value of columnas.
int Tablero::getColumnas() { return columnas; }

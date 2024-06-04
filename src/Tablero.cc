#include <Tablero.hh>
using namespace std;

/*Constructor of class Tablero, the parameters asked for are int filas and int
columnas. Assigns to filas and columnas their respective values and creates a
new vector where every value is another vector. This one is then assigned to
tableroPrivado.
*/
Tablero::Tablero(int filas, int columnas, char jugador1, char jugador2) : filas(filas), columnas(columnas), jugador1(jugador1), jugador2(jugador2) {
  vector<vector<char>> nuevoTablero(filas, vector<char>(columnas, '-'));
  tableroPrivado = nuevoTablero;
  casillasDisponibles = filas * columnas;
}

// Returns tableroPrivado.
vector<vector<char>> Tablero::getTableroPrivado() { return tableroPrivado; }

// Checks if it is a valid move.
bool Tablero::validarMovimiento(int columna) {
  if (tableroPrivado[0][columna] != '-') {
    return false;
  }
  return true;
}

// Fills the specific space of the column in n with char ficha only if its
// available.
void Tablero::LlenarCasilla(int columna, char ficha) {
  for (int f = filas - 1; f >= 0; f--) {
    bool casillaOcupada = false;
    if (tableroPrivado[f][columna] != '-') {
      casillaOcupada = true;
    } else {
      tableroPrivado[f][columna] = ficha;
      casillasDisponibles--;
      break;
    }
  }
}

// Check if someone has already won by connecting four in a row.
bool Tablero::ComprobarGanador(char ficha) {
  // Check horizontal spaces
  for (int f = 0; f < filas; f++) {
    int contador = 0;
    for (int c = 0; c < columnas; c++) {
      if (tableroPrivado[f][c] == ficha) {
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
      if (tableroPrivado[f][c] == ficha) {
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
      if (tableroPrivado[f][c] == ficha &&
          tableroPrivado[f + 1][c - 1] == ficha &&
          tableroPrivado[f + 2][c - 2] == ficha &&
          tableroPrivado[f + 3][c - 3] == ficha) {
        return true;
      }
    }
  }

  // Check diagonal spaces (Top left to bottom right)
  for (int f = 0; f < filas - 3; f++) {
    for (int c = 0; c < columnas - 3; c++) {
      if (tableroPrivado[f][c] == ficha &&
          tableroPrivado[f + 1][c + 1] == ficha &&
          tableroPrivado[f + 2][c + 2] == ficha &&
          tableroPrivado[f + 3][c + 3] == ficha) {
        return true;
      }
    }
  }
  return false;
}

// Checks if a draw has happened.
bool Tablero::ComprobarEmpate() {
  if (casillasDisponibles == 0) {
    return true;
  }
  return false;
}

// Returns the value of filas.
int Tablero::getFilas() { return filas; }

// Returns the value of columnas.
int Tablero::getColumnas() { return columnas; }

// Returns the value of casillasDisponibles.
int Tablero::getCasillasDisponibles() { return casillasDisponibles; }

// Returns jugador1
char Tablero::getJugador1() { return jugador1; }

// Returns jugador2
char Tablero::getJugador2() { return jugador2; }

// Returns turnos
int Tablero::getTurnos() { return turnos; }

// Increases turns by 1
void Tablero::aumentarTurnosEn1() { turnos++; }
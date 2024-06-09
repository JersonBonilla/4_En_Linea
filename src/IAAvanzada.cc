#include <limits.h>
#include <stdio.h>

#include <IAAvanzada.hh>
#include <Tablero.hh>
#include <array>
#include <iostream>
#include <sstream>
#include <vector>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

using namespace std;
IAAvanzada::IAAvanzada(string nombre, bool primerJugador)
    : IJugador(nombre, primerJugador), maxDepth(maxDepth) {
  if (primerJugador) {
    computadora = Color::AMARILLO;
    jugadorHumano = Color::ROJO;
    maximizeOrMinimize = 1;
  } else {
    computadora = Color::ROJO;
    jugadorHumano = Color::AMARILLO;
    maximizeOrMinimize = -1;
  }
  maxDepth = 3;
}

// para determinar si va por un movimiento ganador o para bloquear al oponente
int heuristicFunction(int good, int bad, int empty) {
  int score = 0;
  if (good == 4) {
    score += 500001;
  }  // preferencia para ir por un movimiento Ganador
  else if (good == 3 && empty == 1) {
    score += 5000;
  } else if (good == 2 && empty == 2) {
    score += 500;
  } else if (bad == 2 && empty == 2) {
    score -= 501;
  }  // preferencia a bloquear
  else if (bad == 3 && empty == 1) {
    score -= 5001;
  }  // preferencia a bloquear
  else if (bad == 4) {
    score -= 500000;
  }
  return score;
}

// vector es la fila o columna para revisar, y player contra quien se juega
int scoreSet(vector<Color> vector, Color player, Color jugadorHumano,
             Color computadora) {
  int good = 0;   // puntos a favor de player
  int bad = 0;    // puntos en contra de player
  int empty = 0;  // puntos neutros
  for (int i = 0; i < vector.size(); i++) {
    good += (vector[i] == player) ? 1 : 0;
    bad += (vector[i] == jugadorHumano || vector[i] == computadora) ? 1 : 0;
    empty += (vector[i] == Color::VACIO) ? 1 : 0;
  }
  // bad calculado:
  bad -= good;
  return heuristicFunction(good, bad, empty);
}

// To tabulate the value of the current board
int tabScore(vector<vector<Color>> board, Color player, Color jugadorHumano,
             Color computadora) {
  int score = 0;
  int numeroFilas = board.size();
  int numeroColumnas = board[0].size();
  vector<Color> vectorFilas(numeroColumnas);
  vector<Color> vectorColumnas(numeroFilas);
  vector<Color> set(4);

  // Buscar secuencias de 4 piezas sea player, jugadorHumano o computadora
  // horizontal
  for (int f = 0; f < numeroFilas; f++) {
    for (int c = 0; c < numeroColumnas; c++) {
      vectorFilas[c] = board[f][c];  // una fila sola
    }
    for (int c = 0; c < numeroColumnas - 3; c++) {
      set[0] = board[f][c];
      set[1] = board[f][c + 1];
      set[2] = board[f][c + 2];
      set[3] = board[f][c + 3];
      score += scoreSet(set, player, jugadorHumano,
                        computadora);  // encontrar la puntacion
    }
  }
  // vertical
  for (int c = 0; c < numeroColumnas; c++) {
    for (int f = 0; f < numeroFilas; f++) {
      vectorColumnas[f] = board[f][c];
    }
    for (int f = 0; f < numeroFilas - 3; f++) {
      set[0] = board[f][c];
      set[1] = board[f + 1][c];
      set[2] = board[f + 2][c];
      set[3] = board[f + 3][c];
      score += scoreSet(set, player, jugadorHumano, computadora);
    }
  }
  // diagonals
  for (int f = 0; f < numeroFilas - 3; f++) {
    for (int c = 0; c < numeroColumnas; c++) {
      vectorFilas[c] = board[f][c];
    }
    for (int c = 0; c < numeroColumnas - 3; c++) {
      set[0] = board[f][c];
      set[1] = board[f + 1][c + 1];
      set[2] = board[f + 2][c + 2];
      set[3] = board[f + 3][c + 3];
      score += scoreSet(set, player, jugadorHumano, computadora);
    }
  }

  for (int f = 0; f < numeroFilas - 3; f++) {
    for (int c = 0; c < numeroColumnas; c++) {
      vectorFilas[c] = board[f][c];
    }
    for (int c = 3; c < numeroColumnas; c++) {
      set[0] = board[f][c];
      set[1] = board[f + 1][c - 1];
      set[2] = board[f + 2][c - 2];
      set[3] = board[f + 3][c - 3];
      score += scoreSet(set, player, jugadorHumano, computadora);
    }
  }
  return score;
}

array<int, 2> IAAvanzada::miniMax(Tablero &tablero, int depth, int alpha,
                                  int beta, Color player) {
  vector<vector<Color>> board = tablero.getTableroPrivado();
  int numeroFilas = tablero.getFilas();
  int numeroColumnas = tablero.getColumnas();
  int turnos = tablero.getTurnos();

  // si estamos en la ultima capa de profundidad permitida devolvemos
  if (depth == 0) {
    return array<int, 2>{
        tabScore(board, computadora, jugadorHumano, computadora),
        maximizeOrMinimize};
  }
  // si es una IA
  if (player == computadora) {
    // buscamos el menor valor posible
    array<int, 2> movimientoTemporal = {INT_MIN, maximizeOrMinimize};
    // si el jugador esta a punto de ganar.
    if (tablero.ComprobarGanador(jugadorHumano)) {
      // hacemos que sea como el peor score posible, para forzar que bloquee
      return movimientoTemporal;
    }
    // sino, evaluamos con normalidad.
    for (int c = 0; c < numeroColumnas; c++) {
      // solo si la casilla no esta llena
      if (board[0][c] == Color::VACIO) {
        // hacemos copia del tablero
        Tablero newBoard = tablero;
        // probar el movimiento
        newBoard.LlenarCasilla(c, player);
        // hallar movimiento basado en el nuevo estado del tablero
        int score = miniMax(newBoard, depth - 1, alpha, beta, jugadorHumano)[0];
        // si el score es mejor, cambiar y considerarlo el nuevo mejor
        // movimiento
        if (score > movimientoTemporal[0]) {
          movimientoTemporal = {score, c};
        }
        alpha = max(alpha, movimientoTemporal[0]);
        // para hacer el pruning
        if (alpha >= beta) {
          break;
        }
      }
    }
    // devolver el mejor movimiento posible
    return movimientoTemporal;
  } else {
    // Ahora buscamos movimientos que reduzcan el score, porque queremos hacer
    // minimize a jugador
    array<int, 2> movimientoTemporal = {INT_MAX, maximizeOrMinimize};
    if (tablero.ComprobarGanador(computadora)) {
      // Si esta a punto de ganar, devolvemos.
      return movimientoTemporal;
    }
    for (int c = 0; c < numeroColumnas; c++) {
      if (board[0][c] == Color::VACIO) {
        Tablero newBoard = tablero;
        newBoard.LlenarCasilla(c, player);
        int score = miniMax(newBoard, depth - 1, alpha, beta, computadora)[0];
        if (score < movimientoTemporal[0]) {
          movimientoTemporal = {score, c};
        }
        beta = min(beta, movimientoTemporal[0]);
        if (alpha >= beta) {
          break;
        }
      }
    }
    return movimientoTemporal;
  }
}

int IAAvanzada::movimientoIA(Tablero tablero) {
  return miniMax(tablero, maxDepth, 0 - INT_MAX, INT_MAX, computadora)[1];
}
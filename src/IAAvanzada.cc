#include <IAAvanzada.hh>
#include <Tablero.hh>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits.h>
#include <array>
#include <sstream>

#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;
IAAvanzada::IAAvanzada(int maxDepth) : IJugador(nombre, primerJugador),  maxDepth(maxDepth){
}

vector<vector<char>> copiarTablero(vector<vector<char>> board) {
    int numeroFilas = board.size();
    int numeroColumnas = board[0].size();
	vector<vector<char>> nuevoBoard(numeroFilas, vector<char>(numeroColumnas));
	for (int f = 0; f < numeroFilas; f++) {
		for (int c = 0; c < numeroColumnas; c++) {
			nuevoBoard[f][c] = board[f][c]; // copiar casilla por casilla
		}
	}
	return nuevoBoard;
}

bool movimientoGanador(vector<vector<char>> &board, char player) {
	int secuenciaParaGanar = 0; // contar piezas contiguas
	int numeroFilas = board.size();
    int numeroColumnas = board[0].size();

    // vertical
	for (int c = 0; c < numeroColumnas; c++) {
		for (int f = 0; f < numeroFilas - 3; f++) {
			for (int i = 0; i < 4; i++) {
				if (board[f + i][c] == player) {
					secuenciaParaGanar++;
				}
				if (secuenciaParaGanar == 4) { return true; }
			}
			secuenciaParaGanar = 0;
		}
	}

    // horizontal
	for (int c = 0; c < numeroColumnas - 3; c++) { 
		for (int f = 0; f < numeroColumnas; f++) {
			for (int i = 0; i < 4; i++) {
				if (board[f][c + i] == player) { 
					secuenciaParaGanar++;
				}
				if (secuenciaParaGanar == 4) { return true; }
			}
			secuenciaParaGanar = 0; // resetear contador
		}
	}

	//diagonals
	for (int c = 0; c < numeroColumnas - 3; c++) {
		for (int f = 3; f < numeroFilas; f++) {
			for (int i = 0; i < 4; i++) {
				if (board[f - i][c + i] == player) {
					secuenciaParaGanar++;
				}
				if (secuenciaParaGanar == 4) { return true; }
			}
			secuenciaParaGanar = 0;
		}
	}

	for (int c = 0; c < numeroColumnas - 3; c++) {
		for (int r = 0; r < numeroFilas - 3; r++) {
			for (int i = 0; i < 4; i++) {
				if (board[r + i][c + i] == player) {
					secuenciaParaGanar++;
				}
				if (secuenciaParaGanar == 4) { return true; }
			}
			secuenciaParaGanar = 0;
		}
	}
	return false; // si no hay movimiento ganador, devuelve false.
}

//para determinar si va por un movimiento ganador o para bloquear al oponente
int heuristicFunction(int good, int bad, int empty) {
	int score = 0;
	if (good == 4) { score += 500001; } // preferencia para ir por un movimientoGanador
	else if (good == 3 && empty == 1) { score += 5000; }
	else if (good == 2 && empty == 2) { score += 500; }
	else if (bad == 2 && empty == 2) { score -= 501; } // preferencia a bloquear
	else if (bad == 3 && empty == 1) { score -= 5001; } // preferencia a bloquear
	else if (bad == 4) { score -= 500000; }
	return score;
}

int scoreSet(vector<char> vector, char player) {
	int good = 0; // puntos a favor de player
	int bad = 0; // puntos en contra de player
	int empty = 0; // puntos neutros
	for (int i = 0; i < vector.size(); i++) {
		good += (vector[i] == player) ? 1 : 0;
		bad += (vector[i] == '1' || vector[i] == '2') ? 1 : 0;
		empty += (vector[i] == 0) ? 1 : 0;
	}
	// bad was calculated as (bad + good), so remove good
	bad -= good;
	return heuristicFunction(good, bad, empty);
}

//To tabulate the value of the current board
int tabScore(vector<vector<char>> board, char player) {
	int score = 0;
    int numeroFilas = board.size();
    int numeroColumnas = board[0].size();
	vector<char> vectorFilas(numeroColumnas);
	vector<char> vectorColumnas(numeroFilas);
	vector<char> set(4);
	
    //Buscar secuencias de 4 piezas 
	for (int f = 0; f < numeroFilas; f++) {
		for (int c = 0; c < numeroColumnas; c++) {
			vectorFilas[c] = board[f][c]; 
		}
		for (int c = 0; c < numeroColumnas - 3; c++) {
			for (int i = 0; i < 4; i++) {
				set[i] = vectorColumnas[c + i]; // para toda posible combinacion de 4 piezas
			}
			score += scoreSet(set, player); // encontrar la puntacion 
		}
	}
	// vertical
	for (int c = 0; c < numeroColumnas; c++) {
		for (int f = 0; f < numeroFilas; f++) {
			vectorColumnas[f] = board[f][c];
		}
		for (int f = 0; f < numeroFilas - 3; f++) {
			for (int i = 0; i < 4; i++) {
				set[i] = vectorColumnas[f + i];
			}
			score += scoreSet(set, player);
		}
	}
	// diagonals
	for (int f = 0; f < numeroFilas - 3; f++) {
		for (int c = 0; c < numeroColumnas; c++) {
			vectorFilas[c] = board[f][c];
		}
		for (int c = 0; c < numeroColumnas - 3; c++) {
			for (int i = 0; i < 4; i++) {
				set[i] = board[f + i][c + i];
			}
			score += scoreSet(set, player);
		}
	}
	for (int f = 0; f < numeroFilas - 3; f++) {
		for (int c = 0; c < numeroColumnas; c++) {
			vectorFilas[c] = board[f][c];
		}
		for (int c = 0; c < numeroColumnas - 3; c++) {
			for (int i = 0; i < 4; i++) {
				set[i] = board[r + 3 - i][c + i];
			}
			score += scoreSet(set, player);
		}
	}
	return score;
}
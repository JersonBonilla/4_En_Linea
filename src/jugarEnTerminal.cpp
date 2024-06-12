#include <IAAvanzada.hh>
#include <IAFacil.hh>
#include <IJugador.hh>
#include <JugadorHumano.hh>
#include <Tablero.hh>
#include <iostream>
#include <memory>

void MostrarTablero(vector<vector<Color>> nuevoTablero) {
  cout << "--------------------" << endl;
  // Loop para pasar por cada fila
  for (int f = 0; f < nuevoTablero.size(); f++) {
    // Loop para pasar por cada elemento de la fila, es decir, cada columna
    for (int c = 0; c < nuevoTablero[f].size(); c++) {
      Color casilla = nuevoTablero[f][c];
      if (casilla == Color::VACIO) {
        cout << "|"
             << " "
             << "|";
      } else if (casilla == Color::AMARILLO) {
        cout << "|"
             << "X"
             << "|";
      } else {
        cout << "|"
             << "O"
             << "|";
      }
    }
    cout << endl;
  }

  for (int i = 0; i < nuevoTablero[0].size(); i++) {
    cout << " " << i << " ";
  }
  cout << " " << endl;
  cout << " " << endl;
}

int main() {
  srand(time(0));
  int expresionUsuario = 0;
  int revancha = 0;
  string nombre = "";
  IJugador* jugador1;
  IJugador* jugador2;
  string estadoFinalPartida = "";
  int filasUsuario = 0;
  int columnasUsuario = 0;
  cout << "1. Jugar" << endl;
  cout << "2. Salir" << endl;
  cin >> expresionUsuario;
  cout << "" << endl;
  if (expresionUsuario == 1) {
    // Pedimos, nombre y configuracion del primer jugador
    cout << "Digite el nombre para el jugador 1:" << endl;
    cin >> nombre;
    cout << "Escoja configuracion para el jugador 1:" << endl;
    cout << "1. Jugador humano" << endl;
    cout << "2. IA facil" << endl;
    cout << "3. IA Avanzada" << endl;
    cin >> expresionUsuario;
    if (expresionUsuario == 1) {
      jugador1 = new JugadorHumano(nombre, true);
    } else if (expresionUsuario == 2) {
      jugador1 = new IAFacil(nombre, true);
    } else {
      jugador1 = new IAAvanzada(nombre, true);
    }

    cout << "" << endl;

    // Pedimos, nombre y configuracion del segundo jugador
    cout << "Digite el nombre para el jugador 2:" << endl;
    cin >> nombre;
    cout << "Escoja configuracion para el jugador 1:" << endl;
    cout << "1. Jugador humano" << endl;
    cout << "2. IA facil" << endl;
    cout << "3. IA Avanzada" << endl;
    cin >> expresionUsuario;
    if (expresionUsuario == 1) {
      jugador2 = new JugadorHumano(nombre, false);
    } else if (expresionUsuario == 2) {
      jugador2 = new IAFacil(nombre, false);
    } else {
      jugador2 = new IAAvanzada(nombre, false);
    }
    cout << "" << endl;
    // Pedir numero de filas y columnas
    cout << "Digite el numero de filas: " << endl;
    cin >> filasUsuario;
    cout << "Digite el numero de columnas: " << endl;
    cin >> columnasUsuario;
    Tablero nuevoTablero(filasUsuario, columnasUsuario);
    while (true) {
      // Mostrar partidas ganadas
      cout << "Partidas ganadas de " << jugador1->getNombre() << " : "
           << jugador1->getPartidasGanadas() << endl;
      cout << "Partidas ganadas de " << jugador2->getNombre() << " : "
           << jugador2->getPartidasGanadas() << endl;

      MostrarTablero(nuevoTablero.getTableroPrivado());
      while (true) {
        // Turno del jugador1
        cout << "Turno de: " << jugador1->getNombre() << endl;
        int movimiento = jugador1->movimientoIA(nuevoTablero);
        if (movimiento == -1) {
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          movimiento = expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
            movimiento = expresionUsuario;
          }
        } else {
          cout << movimiento << endl;
        }
        nuevoTablero.LlenarCasilla(movimiento, Color::AMARILLO);
        MostrarTablero(nuevoTablero.getTableroPrivado());
        // Comprobar empate o gane
        if (nuevoTablero.ComprobarGanador(Color::AMARILLO)) {
          estadoFinalPartida += "Ganador: ";
          estadoFinalPartida += jugador1->getNombre();
          estadoFinalPartida += "(";
          estadoFinalPartida += "X";
          estadoFinalPartida += ")";
          jugador1->incrementarPartidasGanadas();
          break;
        } else if (nuevoTablero.ComprobarEmpate()) {
          estadoFinalPartida = "Empate";
          break;
        }

        // Turno del jugador 2
        cout << "Turno de: " << jugador2->getNombre() << endl;
        movimiento = jugador2->movimientoIA(nuevoTablero);
        if (movimiento == -1) {
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          movimiento = expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
            movimiento = expresionUsuario;
          }
        } else {
          cout << movimiento << endl;
        }
        nuevoTablero.LlenarCasilla(movimiento, Color::ROJO);
        MostrarTablero(nuevoTablero.getTableroPrivado());
        // Comprobar empate o gane
        if (nuevoTablero.ComprobarGanador(Color::ROJO)) {
          estadoFinalPartida += "Ganador: ";
          estadoFinalPartida += jugador2->getNombre();
          estadoFinalPartida += "(";
          estadoFinalPartida += "O";
          estadoFinalPartida += ")";
          jugador2->incrementarPartidasGanadas();
          break;
        } else if (nuevoTablero.ComprobarEmpate()) {
          estadoFinalPartida = "Empate";
          break;
        }
      }
      cout << estadoFinalPartida << endl;
      cout << "" << endl;
      // Manejar revanchas
      cout << "Revancha" << endl;
      cout << "1. Si" << endl;
      cout << "2. No" << endl;
      cin >> revancha;
      if (revancha == 2) {
        break;
      }
      estadoFinalPartida = "";
      nuevoTablero.limpiarTablero();
    }
  }
  delete jugador1;
  delete jugador2;
  return 0;
}
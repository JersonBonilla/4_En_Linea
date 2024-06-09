#include <IAAvanzada.hh>
#include <IAFacil.hh>
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
  string nombre1 = "";
  string nombre2 = "";
  string estadoFinalPartida = "";
  JugadorHumano* jH1;
  JugadorHumano* jH2;
  IAFacil* IAF1;
  IAFacil* IAF2;
  IAAvanzada* IAA1;
  IAAvanzada* IAA2;
  bool primerJugadorHumano = false;
  bool segundoJugadorHumano = false;
  bool primerJugadorIAFacil = false;
  bool segundoJugadorIAFacil = false;
  bool primerJugadorIAAvanzada = false;
  bool segundoJugadorIAAvanzada = false;
  int filasUsuario = 0;
  int columnasUsuario = 0;
  cout << "1. Jugar" << endl;
  cout << "2. Salir" << endl;
  cin >> expresionUsuario;
  cout << "" << endl;
  if (expresionUsuario == 1) {
    // Pedimos, nombre y configuracion del primer jugador
    cout << "Digite el nombre para el jugador 1:" << endl;
    cin >> nombre1;
    cout << "Escoja configuracion para el jugador 1:" << endl;
    cout << "1. Jugador humano" << endl;
    cout << "2. IA facil" << endl;
    cout << "3. IA Avanzada" << endl;
    cin >> expresionUsuario;
    if (expresionUsuario == 1) {
      jH1 = new JugadorHumano(nombre1, true);
      primerJugadorHumano = true;
    } else if (expresionUsuario == 2) {
      IAF1 = new IAFacil(nombre1, true);
      primerJugadorIAFacil = true;
    } else {
      IAA1 = new IAAvanzada(nombre1, true);
      primerJugadorIAAvanzada = true;
    }

    cout << "" << endl;

    // Pedimos, nombre y configuracion del segundo jugador
    cout << "Digite el nombre para el jugador 2:" << endl;
    cin >> nombre2;
    cout << "Escoja configuracion para el jugador 1:" << endl;
    cout << "1. Jugador humano" << endl;
    cout << "2. IA facil" << endl;
    cout << "3. IA Avanzada" << endl;
    cin >> expresionUsuario;
    if (expresionUsuario == 1) {
      jH2 = new JugadorHumano(nombre2, false);
      segundoJugadorHumano = true;
    } else if (expresionUsuario == 2) {
      IAF2 = new IAFacil(nombre2, false);
      segundoJugadorIAFacil = true;
    } else {
      IAA2 = new IAAvanzada(nombre2, false);
      segundoJugadorIAAvanzada = true;
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
      if (primerJugadorHumano && segundoJugadorHumano) {
        cout << "Partidas ganadas de " << jH1->getNombre() << " : "
             << jH1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << jH2->getNombre() << " : "
             << jH2->getPartidasGanadas() << endl;
      }
      if (primerJugadorHumano && segundoJugadorIAFacil) {
        cout << "Partidas ganadas de " << jH1->getNombre() << " : "
             << jH1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << IAF2->getNombre() << " : "
             << IAF2->getPartidasGanadas() << endl;
      }
      if (primerJugadorIAFacil && segundoJugadorHumano) {
        cout << "Partidas ganadas de " << IAF1->getNombre() << " : "
             << IAF1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << jH2->getNombre() << " : "
             << jH2->getPartidasGanadas() << endl;
      }
      if (primerJugadorIAFacil && segundoJugadorIAFacil) {
        cout << "Partidas ganadas de " << IAF1->getNombre() << " : "
             << IAF1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << IAF2->getNombre() << " : "
             << IAF2->getPartidasGanadas() << endl;
      }
      if (primerJugadorIAFacil && segundoJugadorIAAvanzada) {
        cout << "Partidas ganadas de " << IAF1->getNombre() << " : "
             << IAF1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << IAA2->getNombre() << " : "
             << IAA2->getPartidasGanadas() << endl;
      }
      if (primerJugadorIAAvanzada && segundoJugadorIAFacil) {
        cout << "Partidas ganadas de " << IAA1->getNombre() << " : "
             << IAA1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << IAF2->getNombre() << " : "
             << IAF2->getPartidasGanadas() << endl;
      }
      if (primerJugadorHumano && segundoJugadorIAAvanzada) {
        cout << "Partidas ganadas de " << jH1->getNombre() << " : "
             << jH1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << IAA2->getNombre() << " : "
             << IAA2->getPartidasGanadas() << endl;
      }
      if (primerJugadorIAAvanzada && segundoJugadorHumano) {
        cout << "Partidas ganadas de " << IAA1->getNombre() << " : "
             << IAA1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << jH2->getNombre() << " : "
             << jH2->getPartidasGanadas() << endl;
      }
      if (primerJugadorIAAvanzada && segundoJugadorIAAvanzada) {
        cout << "Partidas ganadas de " << IAA1->getNombre() << " : "
             << IAA1->getPartidasGanadas() << endl;
        cout << "Partidas ganadas de " << IAA2->getNombre() << " : "
             << IAA2->getPartidasGanadas() << endl;
      }

      while (true) {
        MostrarTablero(nuevoTablero.getTableroPrivado());
        // Jugador humano vs jugador humano
        if (primerJugadorHumano && segundoJugadorHumano) {
          // Turno jugador 1
          cout << "Turno de: " << jH1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
          }
          nuevoTablero.LlenarCasilla(expresionUsuario, jH1->fichaJugador);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(jH1->fichaJugador)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += jH1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (jH1->fichaJugador == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            jH1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno del jugador 2
          cout << "Turno de: " << jH2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
          }
          nuevoTablero.LlenarCasilla(expresionUsuario, jH2->fichaJugador);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(jH2->fichaJugador)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += jH2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (jH2->fichaJugador == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            jH2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }
        }

        // Jugador humano vs IAFacil
        else if (primerJugadorHumano && segundoJugadorIAFacil) {
          // Turno del jugador1
          cout << "Turno de: " << jH1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
          }
          nuevoTablero.LlenarCasilla(expresionUsuario, jH1->fichaJugador);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(jH1->fichaJugador)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += jH1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (jH1->fichaJugador == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            jH1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno jugador 2
          cout << "Turno de: " << IAF2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento = IAF2->movimientoIA(nuevoTablero);
          cout << movimiento << endl;
          nuevoTablero.LlenarCasilla(movimiento, IAF2->fichaIA);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(IAF2->fichaIA)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAF2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAF2->fichaIA == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAF2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

        }
        // IAFacil vs jugador humano
        else if (primerJugadorIAFacil && segundoJugadorHumano) {
          // Turno del jugador 1
          cout << "Turno de: " << IAF1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento = IAF1->movimientoIA(nuevoTablero);
          cout << movimiento << endl;
          nuevoTablero.LlenarCasilla(movimiento, IAF1->fichaIA);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(IAF1->fichaIA)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAF1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAF1->fichaIA == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAF1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno jugador 2
          cout << "Turno de: " << jH2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
          }
          nuevoTablero.LlenarCasilla(expresionUsuario, jH2->fichaJugador);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(jH2->fichaJugador)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += jH2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (jH2->fichaJugador == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            jH2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }
        }
        // IAFacil vs IAFacil
        else if (primerJugadorIAFacil && segundoJugadorIAFacil) {
          // Turno del jugador1
          cout << "Turno de: " << IAF1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento1 = IAF1->movimientoIA(nuevoTablero);
          cout << movimiento1 << endl;
          nuevoTablero.LlenarCasilla(movimiento1, IAF1->fichaIA);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(IAF1->fichaIA)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAF1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAF1->fichaIA == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAF1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno del jugador2
          cout << "Turno de: " << IAF2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento2 = IAF2->movimientoIA(nuevoTablero);
          cout << movimiento2 << endl;
          nuevoTablero.LlenarCasilla(movimiento2, IAF2->fichaIA);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(IAF2->fichaIA)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAF2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAF2->fichaIA == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAF2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }
        }
        // IAFacil vs IAvanzada
        else if (primerJugadorIAFacil && segundoJugadorIAAvanzada) {
          // Turno del jugador 1
          cout << "Turno de: " << IAF1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento1 = IAF1->movimientoIA(nuevoTablero);
          cout << movimiento1 << endl;
          nuevoTablero.LlenarCasilla(movimiento1, IAF1->fichaIA);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(IAF1->fichaIA)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAF1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAF1->fichaIA == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAF1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno del jugador 2
          cout << "Turno de: " << IAA2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento2 = IAA2->movimientoIA(nuevoTablero);
          cout << movimiento2 << endl;
          nuevoTablero.LlenarCasilla(movimiento2, IAA2->computadora);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(IAA2->computadora)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAA2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAA2->computadora == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAA2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }
          // IAvanzada vs IAFacil
        } else if (primerJugadorIAAvanzada && segundoJugadorIAFacil) {
          // Turno del jugador 1
          cout << "Turno de: " << IAA1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento1 = IAA1->movimientoIA(nuevoTablero);
          cout << movimiento1 << endl;
          nuevoTablero.LlenarCasilla(movimiento1, IAA1->computadora);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(IAA1->computadora)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAA1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAA1->computadora == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAA1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }
          // Turno del jugador 2
          cout << "Turno de: " << IAF2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento2 = IAF2->movimientoIA(nuevoTablero);
          cout << movimiento2 << endl;
          nuevoTablero.LlenarCasilla(movimiento2, IAF2->fichaIA);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          // Comprobar ganador o empate
          if (nuevoTablero.ComprobarGanador(IAF2->fichaIA)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAF2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAF2->fichaIA == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAF2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Jugador humano vs IAAvanzada
        } else if (primerJugadorHumano && segundoJugadorIAAvanzada) {
          // Turno del jugador1
          cout << "Turno de: " << jH1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
          }

          nuevoTablero.LlenarCasilla(expresionUsuario, jH1->fichaJugador);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(jH1->fichaJugador)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += jH1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (jH1->fichaJugador == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            jH1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno del jugador 2
          cout << "Turno de: " << IAA2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento = IAA2->movimientoIA(nuevoTablero);
          cout << movimiento << endl;
          nuevoTablero.LlenarCasilla(movimiento, IAA2->computadora);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(IAA2->computadora)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAA2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAA2->computadora == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAA2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // IAAvanzada vs Jugador Humano
        } else if (primerJugadorIAAvanzada && segundoJugadorHumano) {
          // Turno del jugador1
          cout << "Turno de: " << IAA1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento = IAA1->movimientoIA(nuevoTablero);
          cout << movimiento << endl;
          nuevoTablero.LlenarCasilla(movimiento, IAA1->computadora);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(IAA1->computadora)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAA1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAA1->computadora == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAA1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno jugador2
          cout << "Turno de: " << jH2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          cin >> expresionUsuario;
          while (!nuevoTablero.validarMovimiento(expresionUsuario)) {
            cout << "Columna Invalida" << endl;
            cout << "Digite una columna: " << endl;
            cin >> expresionUsuario;
          }
          nuevoTablero.LlenarCasilla(expresionUsuario, jH2->fichaJugador);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(jH2->fichaJugador)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += jH2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (jH2->fichaJugador == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            jH2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }
          // IAAvanzada vs IAAvanzada
        } else if (primerJugadorIAAvanzada && segundoJugadorIAAvanzada) {
          // Turno del jugador1
          cout << "Turno de: " << IAA1->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento1 = IAA1->movimientoIA(nuevoTablero);
          if (movimiento1 == -1) {
            delete jH1;
            delete jH2;
            delete IAF1;
            delete IAF2;
            delete IAA1;
            delete IAA2;
            return 0;
          }
          cout << movimiento1 << endl;
          nuevoTablero.LlenarCasilla(movimiento1, IAA1->computadora);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(IAA1->computadora)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAA1->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAA1->computadora == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAA1->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

          // Turno jugador2
          cout << "Turno de: " << IAA2->getNombre() << endl;
          cout << "Digite una columna: " << endl;
          int movimiento2 = IAA2->movimientoIA(nuevoTablero);
          if (movimiento2 == -1) {
            delete jH1;
            delete jH2;
            delete IAF1;
            delete IAF2;
            delete IAA1;
            delete IAA2;
            return 0;
          }
          cout << movimiento2 << endl;
          nuevoTablero.LlenarCasilla(movimiento2, IAA2->computadora);
          MostrarTablero(nuevoTablero.getTableroPrivado());
          if (nuevoTablero.ComprobarGanador(IAA2->computadora)) {
            estadoFinalPartida += "Ganador: ";
            estadoFinalPartida += IAA2->getNombre();
            estadoFinalPartida += "(";
            string ficha = "";
            if (IAA2->computadora == Color::AMARILLO) {
              ficha = "X";
            } else {
              ficha = "O";
            }
            estadoFinalPartida += ficha;
            estadoFinalPartida += ")";
            IAA2->incrementarPartidasGanadas();
            break;
          } else if (nuevoTablero.ComprobarEmpate()) {
            estadoFinalPartida = "Empate";
            break;
          }

        } else {
          delete jH1;
          delete jH2;
          delete IAF1;
          delete IAF2;
          delete IAA1;
          delete IAA2;
          return 0;
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
  delete jH1;
  delete jH2;
  delete IAF1;
  delete IAF2;
  delete IAA1;
  delete IAA2;
  return 0;
}
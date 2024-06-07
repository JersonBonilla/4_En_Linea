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
      } else {
        cout << "|" << casilla << "|";
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
  string estadoFinalPartida = "";

  cout << "1: Jugador vs jugador" << endl;
  // Opciones IA facil
  cout << "2: Jugador vs IAFacil" << endl;
  cout << "3: IAFacil vs Jugador" << endl;
  cout << "4: IAFacil vs IAFacil" << endl;

  // Opciones IA avanzada
  cout << "5: Jugador vs IAAvanzada" << endl;
  cout << "6: IAAvanzada vs Jugador" << endl;
  cout << "7: IAAvanzada vs IAvanzada" << endl;
  cin >> expresionUsuario;

  if (expresionUsuario == 1) {
    Tablero NuevoTablero(6, 7);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    JugadoHumano jH1("Jugador1", true);
    JugadoHumano jH2("Jugador2", false);
    while (true) {
      // Turno del jugador1
      cout << "Turno de: " << jH1.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while (!NuevoTablero.validarMovimiento(expresionUsuario)) {
        cout << "Columna Invalida" << endl;
        cout << "Digite una columna: " << endl;
        cin >> expresionUsuario;
      }

      NuevoTablero.LlenarCasilla(expresionUsuario, jH1.fichaJugador);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(jH1.fichaJugador)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += jH1.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (jH1.fichaJugador == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }

      // TurnoJugador2
      cout << "Turno del jugador 2" << endl;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while (!NuevoTablero.validarMovimiento(expresionUsuario)) {
        cout << "Columna Invalida" << endl;
        cout << "Digite una columna: " << endl;
        cin >> expresionUsuario;
      }
      NuevoTablero.LlenarCasilla(expresionUsuario, jH2.fichaJugador);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(jH2.fichaJugador)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += jH2.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (jH2.fichaJugador == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
    }
  }

  // 2: Jugador vs IAFacil
  else if (expresionUsuario == 2) {
    Tablero NuevoTablero(6, 7);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    JugadoHumano jH1("Jugador1", true);
    IAFacil IA2("IAFacil2", false);
    while (true) {
      // Turno del jugador1
      cout << "Turno de: " << jH1.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while (!NuevoTablero.validarMovimiento(expresionUsuario)) {
        cout << "Columna Invalida" << endl;
        cout << "Digite una columna: " << endl;
        cin >> expresionUsuario;
      }

      NuevoTablero.LlenarCasilla(expresionUsuario, jH1.fichaJugador);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(jH1.fichaJugador)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += jH1.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (jH1.fichaJugador == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }

      // Turno del jugador2
      cout << "Turno de: " << IA2.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      int movimiento = IA2.movimientoIA(NuevoTablero);
      cout << movimiento << endl;
      NuevoTablero.LlenarCasilla(movimiento, IA2.fichaIA);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IA2.fichaIA)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IA2.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IA2.fichaIA == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
    }
  }

  // 3: IAFacil vs Jugador
  else if (expresionUsuario == 3) {
    Tablero NuevoTablero(6, 7);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    IAFacil IA1("IAFacil1", true);
    JugadoHumano jH2("Jugador2", false);
    while (true) {
      // Turno del jugador1
      cout << "Turno de: " << IA1.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      int movimiento = IA1.movimientoIA(NuevoTablero);
      cout << movimiento << endl;
      NuevoTablero.LlenarCasilla(movimiento, IA1.fichaIA);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IA1.fichaIA)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IA1.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IA1.fichaIA == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }

      // Turno del jugador2
      cout << "Turno de: " << jH2.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while (!NuevoTablero.validarMovimiento(expresionUsuario)) {
        cout << "Columna Invalida" << endl;
        cout << "Digite una columna: " << endl;
        cin >> expresionUsuario;
      }
      NuevoTablero.LlenarCasilla(expresionUsuario, jH2.fichaJugador);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(jH2.fichaJugador)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += jH2.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (jH2.fichaJugador == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
    }
  }

  // 4: IAFacil vs IAFacil
  else if (expresionUsuario == 4) {
    Tablero NuevoTablero(6, 7);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    IAFacil IA1("IAFacil1", true);
    IAFacil IA2("IAFacil2", false);
    while (true) {
      // Turno del jugador1
      cout << "Turno de: " << IA1.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      int movimiento1 = IA1.movimientoIA(NuevoTablero);
      cout << movimiento1 << endl;
      NuevoTablero.LlenarCasilla(movimiento1, IA1.fichaIA);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IA1.fichaIA)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IA1.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IA1.fichaIA == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }

      // Turno del jugador2
      cout << "Turno de: " << IA2.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      int movimiento2 = IA2.movimientoIA(NuevoTablero);
      cout << movimiento2 << endl;
      NuevoTablero.LlenarCasilla(movimiento2, IA2.fichaIA);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IA2.fichaIA)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IA2.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IA2.fichaIA == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
    }
  }

  // 5: Jugador vs IAAvanzada
  else if (expresionUsuario == 5) {
    Tablero NuevoTablero(6, 7);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    JugadoHumano jH1("Jugador1", true);
    IAAvanzada IAAvanzada("IA1", false, 5);
    cout << "La profundidad de la IA es: " << IAAvanzada.maxDepth << endl;
    while (true) {
      // Turno del jugador1
      cout << "Turno de: " << jH1.getNombre() << endl;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while (!NuevoTablero.validarMovimiento(expresionUsuario)) {
        cout << "Columna Invalida" << endl;
        cout << "Digite una columna: " << endl;
        cin >> expresionUsuario;
      }

      NuevoTablero.LlenarCasilla(expresionUsuario, jH1.fichaJugador);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(jH1.fichaJugador)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += jH1.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (jH1.fichaJugador == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }

      // Turno del jugador2
      cout << "Turno de: " << IAAvanzada.getNombre() << endl;
      cout << "Digite una columna: " << endl;
      int movimiento = IAAvanzada.movimientoIA(NuevoTablero);
      cout << movimiento << endl;
      NuevoTablero.LlenarCasilla(movimiento, IAAvanzada.computadora);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IAAvanzada.computadora)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IAAvanzada.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IAAvanzada.computadora == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
    }
  }

  // 6: IAAvanzada vs Jugador
  else if (expresionUsuario == 6) {
    Tablero NuevoTablero(6, 7);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    IAAvanzada IAAvanzada("IA1", true, 5);
    JugadoHumano jH2("Jugador2", false);
    cout << "La profundidad de la IA es: " << IAAvanzada.maxDepth << endl;
    while (true) {
      // Turno del jugador1
      cout << "Turno de: " << IAAvanzada.getNombre() << endl;
      cout << "Digite una columna: " << endl;
      int movimiento = IAAvanzada.movimientoIA(NuevoTablero);
      cout << movimiento << endl;
      NuevoTablero.LlenarCasilla(movimiento, IAAvanzada.computadora);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IAAvanzada.computadora)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IAAvanzada.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IAAvanzada.computadora == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }

      // Turno jugador2
      cout << "Turno de: " << jH2.getNombre() << endl;
      ;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while (!NuevoTablero.validarMovimiento(expresionUsuario)) {
        cout << "Columna Invalida" << endl;
        cout << "Digite una columna: " << endl;
        cin >> expresionUsuario;
      }
      NuevoTablero.LlenarCasilla(expresionUsuario, jH2.fichaJugador);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(jH2.fichaJugador)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += jH2.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (jH2.fichaJugador == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
    }
  }

  // 7: IAAvanzada vs IAvanzada
  else if (expresionUsuario == 7) {
    Tablero NuevoTablero(6, 7);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    IAAvanzada IAA1("IA1", true, 5);
    IAAvanzada IAA2("IA2", false, 5);
    cout << "La profundidad de la IA1 es: " << IAA1.maxDepth << endl;
    cout << "La profundidad de la IA2 es: " << IAA2.maxDepth << endl;
    while (true) {
      // Turno del jugador1
      cout << "Turno de: " << IAA1.getNombre() << endl;
      cout << "Digite una columna: " << endl;
      int movimiento1 = IAA1.movimientoIA(NuevoTablero);
      if (movimiento1 == -1) {
        return 0;
      }
      cout << movimiento1 << endl;
      NuevoTablero.LlenarCasilla(movimiento1, IAA1.computadora);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IAA1.computadora)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IAA1.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IAA1.computadora == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
      cout << "Turno numero: " << NuevoTablero.getTurnos() << endl;

      // Turno jugador2
      cout << "Turno de: " << IAA2.getNombre() << endl;
      cout << "Digite una columna: " << endl;
      int movimiento2 = IAA2.movimientoIA(NuevoTablero);
      if (movimiento2 == -1) {
        return 0;
      }
      cout << movimiento2 << endl;
      NuevoTablero.LlenarCasilla(movimiento2, IAA2.computadora);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if (NuevoTablero.ComprobarGanador(IAA2.computadora)) {
        estadoFinalPartida += "Ganador: ";
        estadoFinalPartida += IAA2.getNombre();
        estadoFinalPartida += "(";
        string ficha = "";
        if (IAA2.computadora == Color::AMARILLO) {
          ficha = "1";
        } else {
          ficha = "2";
        }
        estadoFinalPartida += ficha;
        estadoFinalPartida += ")";
        break;
      } else if (NuevoTablero.ComprobarEmpate()) {
        estadoFinalPartida = "Empate";
        break;
      }
      cout << "Turno numero: " << NuevoTablero.getTurnos() << endl;
    }
  }

  cout << estadoFinalPartida << endl;
  return 0;
}

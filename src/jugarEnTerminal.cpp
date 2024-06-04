#include <Tablero.hh>
#include <IAAvanzada.hh>
#include <iostream>

void MostrarTablero(vector<vector<char>> nuevoTablero)
{
    cout << "--------------------" << endl;
    // Loop para pasar por cada fila
    for (int f = 0; f < nuevoTablero.size(); f++){
        // Loop para pasar por cada elemento de la fila, es decir, cada columna
        for (int c = 0; c < nuevoTablero[f].size(); c++)
        {
          char casilla = nuevoTablero[f][c];
          cout << "|" << casilla << "|";
        }
        cout << endl;
    }

    for(int i = 0; i < nuevoTablero[0].size(); i++){
      cout << " " << i << " ";
    }
    cout << " " << endl;
    cout << " " << endl;
}


int main() {
  int expresionUsuario = 0;
  char jugador1 = '1';
  char jugador2 = '2';
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
  cout << "8: ProbarClonar" << endl;
  cin >> expresionUsuario;
  
  if (expresionUsuario == 1){
      Tablero NuevoTablero(6, 7, jugador1, jugador2);
      MostrarTablero(NuevoTablero.getTableroPrivado());
    while(true){
      // Turno del jugador1
      cout << "Turno del jugador 1" << endl;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while(!NuevoTablero.validarMovimiento(expresionUsuario)){
        cout << "ColumnaInvalida" << endl;
        cout << "Digite una columna: " << endl;
      }

      NuevoTablero.LlenarCasilla(expresionUsuario, jugador1);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if(NuevoTablero.ComprobarGanador(jugador1)){
        estadoFinalPartida += "Ganador: jugador 1 (";
        estadoFinalPartida += jugador1;
        estadoFinalPartida += ")";
        break;
      }
      else if(NuevoTablero.ComprobarEmpate()){
        estadoFinalPartida = "Empate";
        break;
      }

      // TurnoJugador2
      cout << "Turno del jugador 2" << endl;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while(!NuevoTablero.validarMovimiento(expresionUsuario)){
        cout << "ColumnaInvalida" << endl;
        cout << "Digite una columna: " << endl;
        cin >> expresionUsuario;
      }
      NuevoTablero.LlenarCasilla(expresionUsuario, jugador2);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if(NuevoTablero.ComprobarGanador(jugador2)){
        estadoFinalPartida += "Ganador: jugador 2 (";
        estadoFinalPartida += jugador2;
        estadoFinalPartida += ")";
        break;
      }
      else if(NuevoTablero.ComprobarEmpate()){
        estadoFinalPartida = "Empate";
        break;
      }
    }
  }

  // 2: Jugador vs IAFacil
  else if (expresionUsuario == 2){
    while(true){

    }
  }

  // 3: IAFacil vs Jugador
  else if (expresionUsuario == 3){

  }

  // 4: IAFacil vs IAFacil
  else if (expresionUsuario == 4){

  }

  // 5: Jugador vs IAAvanzada 
  else if (expresionUsuario == 5){
    Tablero NuevoTablero(6, 7, jugador1, jugador2);
    MostrarTablero(NuevoTablero.getTableroPrivado());
    IAAvanzada IAAvanzada("IA1", false, 5);
    cout << "La profundidad de la IA es: " << IAAvanzada.maxDepth << endl; 
    while(true){
      // Turno del jugador1
      cout << "Turno del jugador 1" << endl;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
      while(!NuevoTablero.validarMovimiento(expresionUsuario)){
        cout << "Columna Invalida" << endl;
        cout << "Digite una columna: " << endl; 
      }

      NuevoTablero.LlenarCasilla(expresionUsuario, jugador1);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if(NuevoTablero.ComprobarGanador(jugador1)){
        estadoFinalPartida += "Ganador: jugador 1 (";
        estadoFinalPartida += jugador1;
        estadoFinalPartida += ")";
        break;
      }
      else if(NuevoTablero.ComprobarEmpate()){
        estadoFinalPartida = "Empate";
        break;
      }
      NuevoTablero.aumentarTurnosEn1();

      // Turno del jugador2
      cout << "Turno del jugador 2" << endl;
      int movimiento = IAAvanzada.movimientoIA(NuevoTablero);
      cout << movimiento << endl;
      NuevoTablero.LlenarCasilla(movimiento, jugador2);
      MostrarTablero(NuevoTablero.getTableroPrivado());
      if(NuevoTablero.ComprobarGanador(jugador2)){
        estadoFinalPartida += "Ganador: jugador 2 (";
        estadoFinalPartida += jugador2;
        estadoFinalPartida += ")";
        break;
      }
      else if(NuevoTablero.ComprobarEmpate()){
        estadoFinalPartida = "Empate";
        break;
      }
      NuevoTablero.aumentarTurnosEn1();
    }
  }

  // 6: IAAvanzada vs Jugador
  else if (expresionUsuario == 6){
  }

  // 7: IAAvanzada vs IAvanzada
  else if (expresionUsuario == 7){

  }

  // 8:Probar clonar
  else if (expresionUsuario == 8){
    Tablero NuevoTablero(6, 7, jugador1, jugador2);
    NuevoTablero.LlenarCasilla(3, '1');
    NuevoTablero.aumentarTurnosEn1();
    
    Tablero tableroClonado = NuevoTablero;
    cout << "Columnas nuevo tablero: " << tableroClonado.getColumnas() << endl;
    cout << "Filas nuevo tablero: " << tableroClonado.getFilas() << endl;
    cout << "Casillas nuevoTablero: " << tableroClonado.getCasillasDisponibles() << endl;
    cout << "Turnos nuevoTablero: " << tableroClonado.getTurnos() << endl;

  }

  cout << estadoFinalPartida << endl;
  return 0;
}

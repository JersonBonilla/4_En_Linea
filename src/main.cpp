#include <wx/wx.h>
#include <Tablero.hh>
#include <iostream>

using namespace std;

/*class MyApp : public wxApp {
 public:
  virtual bool OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Hello, World!");
    frame->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(MyApp);*/

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
  Tablero NuevoTablero(6,7);
  MostrarTablero(NuevoTablero.getTableroPrivado());
  char jugador1 = '1';
  char jugador2 = '2';
  string estadoFinalPartida = "";
  
  while(true){
    //Turno del jugador1
    cout << "Turno del jugador 1" << endl;
    cout << "Digite una columna: " << endl;
    cin >> expresionUsuario;
    while(!NuevoTablero.validarMovimiento(expresionUsuario)){
      cout << "ColumnaInvalida" << endl;
      cout << "Digite una columna: " << endl;
      cin >> expresionUsuario;
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

    //TurnoJugador2
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
  cout << estadoFinalPartida << endl;
  return 0;
}


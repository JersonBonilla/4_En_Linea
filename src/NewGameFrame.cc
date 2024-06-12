#include <wx/wx.h>

#include <DrawingCanvas.hh>
#include <MainMenuDialog.hh>
#include <NewGameFrame.hh>
#include <ReplayDialog.hh>
#include <memory>

wxDEFINE_EVENT(EVT_PLAYED, wxCommandEvent);
using namespace std;
// Constructor del frame principal del juego
NewGameFrame::NewGameFrame()
    : wxFrame(nullptr, wxID_ANY, "4 En linea", wxDefaultPosition,
              wxDefaultSize) {
  wxMenu* menuFile = new wxMenu;
  menuFile->Append(wxID_EXIT);

  wxMenu* menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);

  wxMenuBar* menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");
  SetMenuBar(menuBar);
  CreateStatusBar();
  SetStatusText("Bienvenido a 4 en linea!");
  Bind(wxEVT_MENU, &NewGameFrame::OnAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &NewGameFrame::OnExit, this, wxID_EXIT);
  Bind(EVT_PLAYED, &NewGameFrame::OnPlayed, this);
  showConfigurationDialog();
  makePlay();
}

// Metodo que muestra el dialog de configuración del juego
void NewGameFrame::showConfigurationDialog() {
  MainMenuDialog dialog(this);
  if (dialog.ShowModal() == wxID_OK) {
    buildGame(dialog.GetPlayer1Name(), dialog.GetPlayer2Name(),
              dialog.GetWidth(), dialog.GetLength(), dialog.GetPlayer1Type(),
              dialog.GetPlayer2Type());
  } else {
    Close(true);
  }
}

// Metodo que construye la ventana del juego
void NewGameFrame::buildGame(wxString player1Name, wxString player2Name,
                             int width, int length, int player1Type,
                             int player2Type) {
  switch (player1Type) {
    case 0:
      // Añadir cast de Persona
      jugador1 = new JugadorHumano("jugador1", true);
      break;
    case 1:
      // Añadir cast de IAFacil
      jugador1 = new IAFacil("jugador1", true);
      break;
    case 2:
      // Añadir cast de IADificil
      jugador1 = new IAAvanzada("jugador1", true);
      break;
  }

  switch (player2Type) {
    case 0:
      // Añadir cast de Persona
      jugador2 = new JugadorHumano("jugador2", false);
      break;
    case 1:
      // Añadir cast de IAFacil
      jugador2 = new IAFacil("jugador2", false);
      break;
    case 2:
      // Añadir cast de IADificil
      jugador2 = new IAAvanzada("jugador2", false);
      break;
  }

  wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* jugador1Sizer = new wxBoxSizer(wxVERTICAL);
  jugador1NameLbl = new wxStaticText(this, wxID_ANY, player1Name);
  jugador1WinsLbl = new wxStaticText(this, wxID_ANY, "Victorias: 0");
  jugador1Sizer->Add(jugador1NameLbl);
  jugador1Sizer->Add(jugador1WinsLbl);
  wxBoxSizer* jugador2Sizer = new wxBoxSizer(wxVERTICAL);
  jugador2NameLbl = new wxStaticText(this, wxID_ANY, player2Name);
  jugador2WinsLbl = new wxStaticText(this, wxID_ANY, "Victorias: 0");
  jugador2Sizer->Add(jugador2NameLbl);
  jugador2Sizer->Add(jugador2WinsLbl);

  wxBoxSizer* playersSizer = new wxBoxSizer(wxHORIZONTAL);
  playersSizer->Add(jugador1Sizer);
  playersSizer->AddStretchSpacer();
  playersSizer->Add(jugador2Sizer);

  mainSizer->Add(playersSizer, wxSizerFlags().Expand());
  tablero = make_shared<Tablero>(length, width);
  canvas = new DrawingCanvas(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                             tablero);
  mainSizer->Add(canvas, wxSizerFlags().Expand().Proportion(3));

  this->SetSizerAndFit(mainSizer);
}

// Metodo encargado de manejar cuando un jugador gana, si se accede a revancha
// llama a updateGame() de lo contrario crea un juego nuevo.
void NewGameFrame::OnWin() {
  ReplayDialog dialog(
      this, wxString::Format("Ha ganado el jugador %d",
                             (tablero->getTurnos() % 2 == 0) ? 2 : 1));
  if (dialog.ShowModal() == wxID_OK) {
    if (tablero->getTurnos() % 2 == 0){
      jugador2->incrementarPartidasGanadas();
    }else{
      jugador1->incrementarPartidasGanadas();
    }
    updateGame();
    SetStatusText("Tablero limpiado");
  } else {
    delete (jugador1NameLbl);
    delete (jugador1WinsLbl);
    delete (jugador2NameLbl);
    delete (jugador2WinsLbl);
    delete (canvas);
    delete (jugador1);
    delete (jugador2);
    showConfigurationDialog();
    SetStatusText("Bienvenido a 4 en linea!");
  }
}

// Metodo que maneja cuando se encuentra un empate, si se accede a revancha
// llama a updateGame() de lo contrario crea un juego nuevo.
void NewGameFrame::OnTie() {
  ReplayDialog dialog(this, wxString::Format("Empate"));
  if (dialog.ShowModal() == wxID_OK) {
    updateGame();
    SetStatusText("Tablero limpiado");
  } else {
    delete (jugador1NameLbl);
    delete (jugador1WinsLbl);
    delete (jugador2NameLbl);
    delete (jugador2WinsLbl);
    delete (canvas);
    delete (jugador1);
    delete (jugador2);
    showConfigurationDialog();
    SetStatusText("Bienvenido a 4 en linea!");
  }
}

// Metodo que maneja el evento de haber insertado una ficha en el tablero,
// revisa si se ha dado algún estado ganador si no pide la jugadad del siguiente
// en ronda.
void NewGameFrame::OnPlayed(wxCommandEvent& event) {
  if (!tablero->ComprobarEmpate()) {
    if (tablero->ComprobarGanador(
            (tablero->getTurnos() % 2 == 0) ? Color::AMARILLO : Color::ROJO)) {
      OnWin();
    }
  } else if (tablero->ComprobarEmpate()) {
    OnTie();
  } else {
    makePlay();

  }
}

// Limpia el tablero y actualiza las victorias del ultimo jugador que ganó.
void NewGameFrame::updateGame() {
  if(tablero->getTurnos() % 2 == 0 ){
    jugador2WinsLbl->SetLabel(wxString::Format("Victorias: %d",
  jugador2->getPartidasGanadas())); }else{
    jugador1WinsLbl->SetLabel(wxString::Format("Victorias: %d",
  jugador1->getPartidasGanadas()));
  }
  tablero->limpiarTablero();
  Refresh();
}

// Envia una jugada de la ia al tablero, si el jugador no fuera IA su movimiento
// retorna -1, no hace nada.
void NewGameFrame::makePlay() {
  int move = 0;
  if (tablero->getTurnos() == 0) {
    move = jugador1->movimientoIA(*tablero);
  } else if (tablero->getTurnos() % 2 == 0) {
    move = jugador1->movimientoIA(*tablero);
  } else {
    move = jugador2->movimientoIA(*tablero);
  }
  if (move > -1 && tablero->getTurnos() == 0){
    tablero->LlenarCasilla(move, Color::ROJO);
    Refresh();
    wxCommandEvent playEvent(EVT_PLAYED);
    playEvent.SetString("");
    wxPostEvent(this, playEvent);
  } else if (move > -1){
    tablero->LlenarCasilla(move, (tablero->getTurnos() % 2 == 0) ? Color::AMARILLO : Color::ROJO);
  }
}

void NewGameFrame::OnExit(wxCommandEvent& event) { Close(true); }

void NewGameFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

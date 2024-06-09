#include <wx/wx.h>

#include <DrawingCanvas.hh>
#include <MainMenuDialog.hh>
#include <NewGameFrame.hh>
#include <ReplayDialog.hh>

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
  showConfigurationDialog();
}

// Metodo que muestra el dialog de configuración del juego
void NewGameFrame::showConfigurationDialog() {
  MainMenuDialog dialog(this);
  if (dialog.ShowModal() == wxID_OK) {
    buildGame(dialog.GetPlayer1Name(), dialog.GetPlayer2Name(),
              dialog.GetWidth(), dialog.GetLength());
  } else {
    Close(true);
  }
}

// Metodo que construye la ventana del juego
void NewGameFrame::buildGame(wxString player1Name, wxString player2Name,
                             int width, int length) {
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
  // Boton para probar funcionalidad
  // TODO: Agregar conexión con la parte lógica cuando este terminada.
  /*wxButton* winButton =
      new wxButton(this, wxID_ANY, "Ganar", wxDefaultPosition, wxDefaultSize);
  mainSizer->Add(winButton, wxSizerFlags().Expand().Proportion(3));
  winButton->Bind(wxEVT_BUTTON, &NewGameFrame::OnWin, this);*/
  tablero = Tablero(width, length);
  Tablero& tableroToSend = tablero;
  canvas = new DrawingCanvas(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                             tableroToSend);
  mainSizer->Add(canvas, wxSizerFlags().Expand().Proportion(3));

  this->SetSizerAndFit(mainSizer);
}

// Metodo encargado de manejar cuando un jugador gana
void NewGameFrame::OnWin(wxCommandEvent& event) {
  ReplayDialog dialog(this);
  if (dialog.ShowModal() == wxID_OK) {
    // TODO: Agregar Clean al tablero para la revancha
    SetStatusText("Tablero limpiado");
  } else {
    // TODO: Agregar un metodo restartGame
    showConfigurationDialog();
  }
}

void NewGameFrame::OnExit(wxCommandEvent& event) { Close(true); }

void NewGameFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
               wxOK | wxICON_INFORMATION);
}

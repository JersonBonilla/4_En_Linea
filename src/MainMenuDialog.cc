#include <wx/spinctrl.h>
#include <wx/wx.h>

#include <MainMenuDialog.hh>

// Metodo que crea los elementos necesarios para configurar el juego
void MainMenuDialog::BuildDialog() {
  wxArrayString tipoJugadores;
  tipoJugadores.Add("Persona");
  tipoJugadores.Add("IA Facil");
  tipoJugadores.Add("IA Avanzada");

  // Texto Jugador 1
  jugador1Lbl = new wxStaticText(this, wxID_ANY, "Jugador 1:");
  // Nombre Jugador 1
  nombreJugador1Txt = new wxTextCtrl(this, wxID_ANY, "Nombre",
                                     wxDefaultPosition, wxSize(200, -1));
  // RadioBox Jugador 1
  tipoJugador1Rb =
      new wxRadioBox(this, wxID_ANY, "Tipo de jugador", wxDefaultPosition,
                     wxSize(300, -1), tipoJugadores);

  // Texto Jugador 2
  jugador2Lbl = new wxStaticText(this, wxID_ANY, "Jugador 2:");
  // Nombre Jugador 2
  nombreJugador2Txt = new wxTextCtrl(this, wxID_ANY, "Nombre",
                                     wxDefaultPosition, wxSize(200, -1));
  // RadioBox Jugador 2
  tipoJugador2Rb =
      new wxRadioBox(this, wxID_ANY, "Tipo de jugador", wxDefaultPosition,
                     wxSize(300, -1), tipoJugadores);

  // Texto Tamaño del tablero
  tableroConfigLbl = new wxStaticText(this, wxID_ANY, "Tamaño del tablero ");
  // Texto largo
  largoLbl = new wxStaticText(this, wxID_ANY, "Filas: ");
  // Spin largo
  largoSc = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition,
                           wxSize(125, -1), wxALIGN_LEFT, 4, 10, 4);
  // Texto ancho
  anchoLbl = new wxStaticText(this, wxID_ANY, "Columnas: ");
  // Spin ancho
  anchoSc = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition,
                           wxSize(125, -1), wxALIGN_LEFT, 4, 10, 4);
  wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
  // Elementos jugador 1
  wxBoxSizer* jugador1NombreSizer = new wxBoxSizer(wxHORIZONTAL);
  jugador1NombreSizer->Add(jugador1Lbl);
  jugador1NombreSizer->Add(nombreJugador1Txt);
  mainSizer->Add(jugador1NombreSizer,
                 wxSizerFlags().Expand().Border(wxLEFT, 10));
  mainSizer->Add(tipoJugador1Rb, wxSizerFlags().Border(wxLEFT | wxDOWN, 15));
  // Elementos jugador 2
  wxBoxSizer* jugador2NombreSizer = new wxBoxSizer(wxHORIZONTAL);
  jugador2NombreSizer->Add(jugador2Lbl);
  jugador2NombreSizer->Add(nombreJugador2Txt);
  mainSizer->Add(jugador2NombreSizer,
                 wxSizerFlags().Expand().Border(wxLEFT, 10));
  mainSizer->Add(tipoJugador2Rb, wxSizerFlags().Border(wxLEFT | wxDOWN, 15));
  mainSizer->Add(tableroConfigLbl, wxSizerFlags().Expand());
  mainSizer->AddStretchSpacer();
  // Elementos largo tablero
  wxBoxSizer* largoSizer = new wxBoxSizer(wxHORIZONTAL);
  largoSizer->Add(largoLbl);
  largoSizer->Add(largoSc);
  mainSizer->Add(largoSizer,
                 wxSizerFlags().Expand().Border(wxLEFT | wxDOWN, 15));
  // Elementos ancho tablero
  wxBoxSizer* anchoSizer = new wxBoxSizer(wxHORIZONTAL);
  anchoSizer->Add(anchoLbl);
  anchoSizer->Add(anchoSc);
  mainSizer->Add(anchoSizer,
                 wxSizerFlags().Expand().Border(wxLEFT | wxDOWN, 15));
  mainSizer->AddStretchSpacer();
  mainSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0, wxALIGN_CENTER | wxALL);
  SetSizerAndFit(mainSizer);
}

// Metodo para retornar el nombre del primer jugador
wxString MainMenuDialog::GetPlayer1Name() {
  return nombreJugador1Txt->GetLineText(0);
}

// Metodo para retornar el nombre del segundo jugador
wxString MainMenuDialog::GetPlayer2Name() {
  return nombreJugador2Txt->GetLineText(0);
}

int MainMenuDialog::GetWidth() { return anchoSc->GetValue(); }
int MainMenuDialog::GetLength() { return largoSc->GetValue(); }
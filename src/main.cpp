
#include <wx/spinctrl.h>
#include <wx/wx.h>

class MyApp : public wxApp {
 public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

// Menu de la configuración del juego
class MainMenuDialog : public wxDialog {
 public:
  MainMenuDialog(wxWindow* parent, wxWindowID id = wxID_ANY,
                 const wxString& title = "Nuevo juego",
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxSize(800, 600),
                 long style = wxDEFAULT_DIALOG_STYLE)
      : wxDialog(parent, id, title, pos, size, style) {
    BuildDialog();
  }
  wxString GetPlayer1Name();
  wxString GetPlayer2Name();

 private:
  void BuildDialog();
  wxStaticText* jugador1Lbl;
  wxTextCtrl* nombreJugador1Txt;
  wxRadioBox* tipoJugador1Rb;
  wxStaticText* jugador2Lbl;
  wxTextCtrl* nombreJugador2Txt;
  wxRadioBox* tipoJugador2Rb;
  wxStaticText* tableroConfigLbl;
  wxStaticText* largoLbl;
  wxSpinCtrl* largoSc;
  wxStaticText* anchoLbl;
  wxSpinCtrl* anchoSc;
};

// Dialog con pregunta de revancha
class ReplayDialog : public wxDialog {
 public:
  ReplayDialog(wxWindow* parent, wxWindowID id = wxID_ANY,
               const wxString& title = "",
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = wxDEFAULT_DIALOG_STYLE)
      : wxDialog(parent, id, title, pos, size, style) {
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxStaticText* replay = new wxStaticText(this, wxID_ANY, "Revancha?");
    mainSizer->Add(replay);
    mainSizer->Add(CreateButtonSizer(wxOK | wxCANCEL), 0,
                   wxALIGN_CENTER | wxALL);
    SetSizerAndFit(mainSizer);
  }
};

// Frame principal del juego
class NewGameFrame : public wxFrame {
 public:
  NewGameFrame();

 private:
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void showConfigurationDialog();
  void buildGame(wxString player1Name, wxString player2Name);
  void OnWin(wxCommandEvent& event);
  wxStaticText* jugador1NameLbl;
  wxStaticText* jugador1WinsLbl;
  wxStaticText* jugador2NameLbl;
  wxStaticText* jugador2WinsLbl;
};

bool MyApp::OnInit() {
  NewGameFrame* frame = new NewGameFrame();
  frame->Show(true);
  return true;
}

// Constructor del frame principal del juego
NewGameFrame::NewGameFrame()
    : wxFrame(nullptr, wxID_ANY, "4 En linea", wxDefaultPosition,
              wxSize(800, 600)) {
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
    buildGame(dialog.GetPlayer1Name(), dialog.GetPlayer2Name());
  } else {
    Close(true);
  }
}

// Metodo que construye la ventana del juego
void NewGameFrame::buildGame(wxString player1Name, wxString player2Name) {
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
  wxButton* winButton =
      new wxButton(this, wxID_ANY, "Ganar", wxDefaultPosition, wxDefaultSize);
  mainSizer->Add(winButton, wxSizerFlags().Expand().Proportion(3));

  this->SetSizerAndFit(mainSizer);
  winButton->Bind(wxEVT_BUTTON, &NewGameFrame::OnWin, this);
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
  largoLbl = new wxStaticText(this, wxID_ANY, "Largo: ");
  // Spin largo
  largoSc = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition,
                           wxSize(125, -1), wxALIGN_LEFT, 4, 10, 4);
  // Texto ancho
  anchoLbl = new wxStaticText(this, wxID_ANY, "Ancho: ");
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
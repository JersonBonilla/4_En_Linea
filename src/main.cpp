#include <wx/spinctrl.h>
#include <wx/wx.h>

class MyApp : public wxApp {
 public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame {
 public:
  MyFrame();

 private:
  void OnHello(wxCommandEvent& event);
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
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
  wxButton* startGameBtn;
};

enum { ID_Hello = 1 };

bool MyApp::OnInit() {
  MyFrame* frame = new MyFrame();
  frame->Show(true);
  return true;
}

MyFrame::MyFrame()
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

  wxArrayString tipoJugadores;
  tipoJugadores.Add("Persona");
  tipoJugadores.Add("IA Facil");
  tipoJugadores.Add("IA Avanzada");

  // Boton Comenzar Juego.
  startGameBtn = new wxButton(this, wxID_ANY, "Empezar Juego",
                                        wxDefaultPosition, wxSize(200, 100));
  // Texto Jugador 1
  jugador1Lbl =
      new wxStaticText(this, wxID_ANY, "Jugador 1:");
  // Nombre Jugador 1
  nombreJugador1Txt = new wxTextCtrl(
      this, wxID_ANY, "Nombre", wxDefaultPosition, wxSize(200, -1));
  // RadioBox Jugador 1
  tipoJugador1Rb =
      new wxRadioBox(this, wxID_ANY, "Tipo de jugador", wxDefaultPosition,
                     wxSize(300, -1), tipoJugadores);

  // Texto Jugador 2
  jugador2Lbl =
      new wxStaticText(this, wxID_ANY, "Jugador 2:");
  // Nombre Jugador 2
  nombreJugador2Txt = new wxTextCtrl(
      this, wxID_ANY, "Nombre", wxDefaultPosition, wxSize(200, -1));
  // RadioBox Jugador 2
  tipoJugador2Rb =
      new wxRadioBox(this, wxID_ANY, "Tipo de jugador", wxDefaultPosition,
                     wxSize(300, -1), tipoJugadores);

  // Texto Tamaño del tablero
  tableroConfigLbl =
      new wxStaticText(this, wxID_ANY, "Tamaño del tablero ");
  // Texto largo
  largoLbl =
      new wxStaticText(this, wxID_ANY, "Largo: ");
  // Spin largo
  largoSc = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition,
                                       wxSize(125, -1), wxALIGN_LEFT, 4, 10, 4);
  // Texto ancho
  anchoLbl =
      new wxStaticText(this, wxID_ANY, "Ancho: ");
  // Spin ancho
  anchoSc = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition,
                                       wxSize(125, -1), wxALIGN_LEFT, 4, 10, 4);

  wxBoxSizer* frameSizer = new wxBoxSizer(wxVERTICAL);
  // Elementos jugador 1
  wxBoxSizer* jugador1NombreSizer = new wxBoxSizer(wxHORIZONTAL);
  jugador1NombreSizer->Add(jugador1Lbl);
  jugador1NombreSizer->Add(nombreJugador1Txt);
  frameSizer->Add(jugador1NombreSizer, wxSizerFlags().Expand().Border(wxLEFT, 10));
  frameSizer->Add(tipoJugador1Rb, wxSizerFlags().Border(wxLEFT | wxDOWN, 15));
  // Elementos jugador 2
  wxBoxSizer* jugador2NombreSizer = new wxBoxSizer(wxHORIZONTAL);
  jugador2NombreSizer->Add(jugador2Lbl);
  jugador2NombreSizer->Add(nombreJugador2Txt);
  frameSizer->Add(jugador2NombreSizer, wxSizerFlags().Expand().Border(wxLEFT, 10));
  frameSizer->Add(tipoJugador2Rb, wxSizerFlags().Border(wxLEFT | wxDOWN, 15));
  frameSizer->Add(tableroConfigLbl, wxSizerFlags().Expand());
  frameSizer->AddStretchSpacer();
  // Elementos largo tablero
  wxBoxSizer* largoSizer = new wxBoxSizer(wxHORIZONTAL);
  largoSizer->Add(largoLbl);
  largoSizer->Add(largoSc);
  frameSizer->Add(largoSizer, wxSizerFlags().Expand().Border(wxLEFT | wxDOWN, 15));
  // Elementos ancho tablero
  wxBoxSizer* anchoSizer = new wxBoxSizer(wxHORIZONTAL);
  anchoSizer->Add(anchoLbl);
  anchoSizer->Add(anchoSc);
  frameSizer->Add(anchoSizer, wxSizerFlags().Expand().Border(wxLEFT | wxDOWN, 15));
  // Elementos Boton
  wxBoxSizer* startGameSizer = new wxBoxSizer(wxHORIZONTAL);
  startGameSizer->AddStretchSpacer();
  startGameSizer->Add(startGameBtn);
  startGameSizer->AddStretchSpacer();
  frameSizer->AddStretchSpacer();
  frameSizer->Add(startGameSizer, wxSizerFlags().Expand().Proportion(1));
  SetSizerAndFit(frameSizer);
  Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event) { Close(true); }

void MyFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
               wxOK | wxICON_INFORMATION);
}
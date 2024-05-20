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
  wxButton* startGameBtn = new wxButton(this, wxID_ANY, "Empezar Juego",
                                        wxPoint(300, 400), wxSize(200, 100));
  // Texto Jugador 1
  wxStaticText* jugador1Lbl =
      new wxStaticText(this, wxID_ANY, "Jugador 1:", wxPoint(10, 20));
  // Nombre Jugador 1
  wxTextCtrl* nombreJugador1Txt = new wxTextCtrl(
      this, wxID_ANY, "Nombre", wxPoint(90, 12), wxSize(200, -1));
  // RadioBox Jugador 1
  wxRadioBox* tipoJugador1Rb =
      new wxRadioBox(this, wxID_ANY, "Tipo de jugador", wxPoint(15, 50),
                     wxSize(300, -1), tipoJugadores);

  // Texto Jugador 2
  wxStaticText* jugador2Lbl =
      new wxStaticText(this, wxID_ANY, "Jugador 2:", wxPoint(10, 150));
  // Nombre Jugador 2
  wxTextCtrl* nombreJugador2Txt = new wxTextCtrl(
      this, wxID_ANY, "Nombre", wxPoint(90, 142), wxSize(200, -1));
  // RadioBox Jugador 2
  wxRadioBox* tipoJugador2Rb =
      new wxRadioBox(this, wxID_ANY, "Tipo de jugador", wxPoint(20, 180),
                     wxSize(300, -1), tipoJugadores);

  // Texto Tamaño del tablero
  wxStaticText* tableroConfigLbl =
      new wxStaticText(this, wxID_ANY, "Tamaño del tablero ", wxPoint(10, 250));
  // Texto largo
  wxStaticText* largoLbl =
      new wxStaticText(this, wxID_ANY, "Largo: ", wxPoint(10, 300));
  // Spin largo
  wxSpinCtrl* largoSc = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(62, 290),
                                       wxSize(125, -1), wxALIGN_LEFT, 4, 10, 4);
  // Texto ancho
  wxStaticText* anchoLbl =
      new wxStaticText(this, wxID_ANY, "Ancho: ", wxPoint(10, 350));
  // Spin ancho
  wxSpinCtrl* anchoSc = new wxSpinCtrl(this, wxID_ANY, "", wxPoint(62, 340),
                                       wxSize(125, -1), wxALIGN_LEFT, 4, 10, 4);

  Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
  Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event) { Close(true); }

void MyFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("This is a wxWidgets Hello World example", "About Hello World",
               wxOK | wxICON_INFORMATION);
}
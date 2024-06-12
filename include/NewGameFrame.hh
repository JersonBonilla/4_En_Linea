#ifndef NEWGAMEFRAME_HH
#define NEWGAMEFRAME_HH
#include <wx/wx.h>

#include <DrawingCanvas.hh>
#include <Tablero.hh>
#include <memory>

using namespace std;
// Frame principal del juego
class NewGameFrame : public wxFrame {
 public:
  NewGameFrame();

 private:
  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnPlayed(wxCommandEvent& event);
  void showConfigurationDialog();
  void buildGame(wxString player1Name, wxString player2Name, int width,
                 int length, int player1Type, int player2Type);
  void updateGame();
  void OnWin();
  void OnTie();
  void makePlay();
  wxStaticText* jugador1NameLbl;
  wxStaticText* jugador1WinsLbl;
  wxStaticText* jugador2NameLbl;
  wxStaticText* jugador2WinsLbl;
  DrawingCanvas* canvas;
  shared_ptr<Tablero> tablero;
  unique_ptr<IJugador> jugador1;
  unique_ptr<IJugador> jugador2;
};
#endif
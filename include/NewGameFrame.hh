#ifndef NEWGAMEFRAME_HH
#define NEWGAMEFRAME_HH
#include <wx/wx.h>
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
#endif
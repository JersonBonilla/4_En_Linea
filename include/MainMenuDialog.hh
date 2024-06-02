#ifndef MAINMENUDIALOG_HH
#define MAINMENUDIALOG_HH
#include <wx/spinctrl.h>
#include <wx/wx.h>
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
#endif
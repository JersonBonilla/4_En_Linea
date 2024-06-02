#ifndef REPLAYDIALOG_HH
#define REPLAYDIALOG_HH
#include <wx/wx.h>
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
#endif
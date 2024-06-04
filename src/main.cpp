#include <wx/wx.h>
#include <Tablero.hh>
#include <IAAvanzada.hh>
#include <iostream>

using namespace std;

class MyApp : public wxApp {
 public:
  virtual bool OnInit() {
    wxFrame* frame = new wxFrame(NULL, wxID_ANY, "Hello, World!");
    frame->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(MyApp);

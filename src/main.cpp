#include <wx/wx.h>
#include <Tablero.hh>
#include <IAAvanzada.hh>
#include <iostream>

using namespace std;

#include <NewGameFrame.hh>
class MyApp : public wxApp {
 public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  NewGameFrame* frame = new NewGameFrame();
  frame->SetClientSize(800, 600);
  frame->Center();
  frame->Show(true);
  return true;
}

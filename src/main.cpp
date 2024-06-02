#include <wx/wx.h>
#include <NewGameFrame.hh>
class MyApp : public wxApp {
 public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  NewGameFrame* frame = new NewGameFrame();
  frame->Show(true);
  return true;
}

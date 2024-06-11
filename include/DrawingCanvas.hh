#ifndef DRAWINGCANVAS_HH
#define DRAWINGCANVAS_HH
#include <wx/wx.h>

#include <Tablero.hh>
#include <memory>
#include <vector>

using namespace std;
wxDECLARE_EVENT(EVT_PLAYED, wxCommandEvent);
class DrawingCanvas : public wxWindow {
 public:
  DrawingCanvas(wxWindow *Parent, wxWindowID id, const wxPoint &pos,
                const wxSize &size, shared_ptr<Tablero> tablero);
  virtual ~DrawingCanvas() noexcept {}

 private:
  void onPaint(wxPaintEvent &);
  void onMouseDown(wxMouseEvent &);
  bool isDrawing{};
  int boardWidth = 0;
  int boardLength = 0;
  shared_ptr<Tablero> playableTablero;
};

#endif
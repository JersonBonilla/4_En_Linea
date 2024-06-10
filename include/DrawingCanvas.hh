#ifndef DRAWINGCANVAS_HH
#define DRAWINGCANVAS_HH
#include <wx/wx.h>

#include <Tablero.hh>
#include <vector>

using namespace std;

class DrawingCanvas : public wxWindow {
 public:
  DrawingCanvas(wxWindow *Parent, wxWindowID id, const wxPoint &pos,
                const wxSize &size, Tablero &tablero);
  virtual ~DrawingCanvas() noexcept {}

 private:
  void onPaint(wxPaintEvent &);
  void onMouseDown(wxMouseEvent &);
  bool isDrawing{};
  int boardWidth = 0;
  int boardLength = 0;
  Tablero playableTablero;
};

#endif
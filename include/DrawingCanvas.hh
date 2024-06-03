#ifndef DRAWINGCANVAS_HH
#define DRAWINGCANVAS_HH
#include <wx/wx.h>
#include <vector>

using namespace std;

class DrawingCanvas : public wxWindow {
  public:
    DrawingCanvas(wxWindow* Parent, wxWindowID id, const wxPoint &pos, const wxSize &size);
    virtual ~DrawingCanvas() noexcept{}

  private:
    void onPaint(wxPaintEvent &);
    void onMouseDown(wxMouseEvent &);
    void onMouseMove(wxMouseEvent &);
    void onMouseUp(wxMouseEvent &);
    void onMouseLeave(wxMouseEvent &);
    bool isDrawing{};
    vector<vector<wxPoint2DDouble>> squiggles;
};  

#endif
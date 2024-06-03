#include <wx/dcbuffer.h>
#include <wx/graphics.h>

#include <DrawingCanvas.hh>

DrawingCanvas::DrawingCanvas(wxWindow *parent, wxWindowID id,
                             const wxPoint &pos, const wxSize &size)
    : wxWindow(parent, id, pos, size) {
  this->SetBackgroundStyle(wxBG_STYLE_PAINT);
  this->Bind(wxEVT_PAINT, &DrawingCanvas::onPaint, this);
  this->Bind(wxEVT_LEFT_DOWN, &DrawingCanvas::onMouseDown, this);
  this->Bind(wxEVT_MOTION, &DrawingCanvas::onMouseMove, this);
  this->Bind(wxEVT_LEFT_UP, &DrawingCanvas::onMouseUp, this);
  this->Bind(wxEVT_LEAVE_WINDOW, &DrawingCanvas::onMouseLeave, this);
}

void DrawingCanvas::onPaint(wxPaintEvent &) {
  wxAutoBufferedPaintDC dc(this);
  dc.Clear();
  wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
  if (gc) {
    for (const auto &pointsVector : squiggles) {
      if (pointsVector.size() > 1) {
        gc->SetPen(wxPen(*wxBLACK));
        gc->StrokeLines(pointsVector.size(), pointsVector.data());
      }
    }
    delete gc;
  }
}

void DrawingCanvas::onMouseDown(wxMouseEvent &) {
  squiggles.push_back({});
  isDrawing = true;
}

void DrawingCanvas::onMouseMove(wxMouseEvent &event) {
  if (isDrawing) {
    auto pt = event.GetPosition();
    auto &currentSquiggle = squiggles.back();
    currentSquiggle.push_back(pt);
    Refresh();
  }
}

void DrawingCanvas::onMouseUp(wxMouseEvent &) { isDrawing = false; }

void DrawingCanvas::onMouseLeave(wxMouseEvent &) { isDrawing = false; }

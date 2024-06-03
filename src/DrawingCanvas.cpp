#include <wx/dcbuffer.h>
#include <wx/graphics.h>

#include <DrawingCanvas.hh>

DrawingCanvas::DrawingCanvas(wxWindow *parent, wxWindowID id,
                             const wxPoint &pos, const wxSize &size,
                             double width, double length)
    : wxWindow(parent, id, pos, size) {
  boardWidth = width;
  boardLength = length;
  this->SetBackgroundStyle(wxBG_STYLE_PAINT);
  this->Bind(wxEVT_PAINT, &DrawingCanvas::onPaint, this);
  this->Bind(wxEVT_LEFT_DOWN, &DrawingCanvas::onMouseDown, this);
  this->Bind(wxEVT_MOTION, &DrawingCanvas::onMouseMove, this);
  this->Bind(wxEVT_LEFT_UP, &DrawingCanvas::onMouseUp, this);
  this->Bind(wxEVT_LEAVE_WINDOW, &DrawingCanvas::onMouseLeave, this);
}

// Metodo llamado cada vez que se necesita redibujar la pantalla
void DrawingCanvas::onPaint(wxPaintEvent &) {
  wxAutoBufferedPaintDC dc(this);
  dc.Clear();
  wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
  if (gc) {
    gc->SetPen(wxPen(*wxBLACK));
    wxGraphicsPath path = gc->CreatePath();
    // Se encarga de calcular y agregar al path las lineas de las filas
    auto size = this->GetClientSize();
    double xSpaces = size.GetHeight() / boardLength;
    double xCurrentPosition = xSpaces;
    for (int i = 0; i < boardLength; i++) {
      path.MoveToPoint(0, xCurrentPosition);
      path.AddLineToPoint(size.GetWidth(), xCurrentPosition);
      xCurrentPosition += xSpaces;
    }
    // Se encarga de calcular y agregar al path las lineas de las columnas
    double ySpaces = size.GetWidth() / boardWidth;
    double yCurrentPosition = ySpaces;
    for (int i = 0; i < boardWidth; i++) {
      path.MoveToPoint(yCurrentPosition, 0);
      path.AddLineToPoint(yCurrentPosition, size.GetHeight());
      yCurrentPosition += ySpaces;
    }

    gc->StrokePath(path);
    // TODO: Esto es para pintar con el mouse, eliminar
    for (const auto &pointsVector : squiggles) {
      if (pointsVector.size() > 1) {
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

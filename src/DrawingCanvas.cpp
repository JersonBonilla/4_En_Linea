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
    // Recibe el tamaño dibujable del cliente (ancho, alto)
    auto size = this->GetClientSize();
    // Guarda la distancia entre cada linea de las filas del tablero con alto/cantidad de filas
    double xDistance = size.GetHeight() / boardLength;
    for (int i = 1; i < boardLength; i++) {
      path.MoveToPoint(0, xDistance*i);
      path.AddLineToPoint(size.GetWidth(), xDistance*i);
    }
    // Se encarga de calcular y agregar al path las lineas de las columnas
    // Guarda la distancia entre cada linea de las columnas del tablero con ancho/cantidad de columnas
    double yDistance = size.GetWidth() / boardWidth;
    for (int i = 1; i < boardWidth; i++) {
      path.MoveToPoint(yDistance*i, 0);
      path.AddLineToPoint(yDistance*i, size.GetHeight());
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

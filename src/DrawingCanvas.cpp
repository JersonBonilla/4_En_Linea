#include <wx/dcbuffer.h>
#include <wx/graphics.h>

#include <DrawingCanvas.hh>
#include <Tablero.hh>
#include <vector>

using namespace std;

DrawingCanvas::DrawingCanvas(wxWindow *parent, wxWindowID id,
                             const wxPoint &pos, const wxSize &size,
                             Tablero &tablero)
    : wxWindow(parent, id, pos, size) {
  playableTablero = tablero;
  boardWidth = playableTablero.getColumnas();
  boardLength = playableTablero.getFilas();
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
  wxGraphicsContext *gcFirstPlayer = wxGraphicsContext::Create(dc);
  wxGraphicsContext *gcSecondPlayer = wxGraphicsContext::Create(dc);
  if (gc) {
    gc->SetPen(wxPen(*wxBLACK));
    wxGraphicsPath path = gc->CreatePath();
    // Se encarga de calcular y agregar al path las lineas de las filas
    // Recibe el tamaño dibujable del cliente (ancho, alto)
    auto size = this->GetClientSize();
    // Guarda la distancia entre cada linea de las filas del tablero con
    // alto/cantidad de filas
    double xDistance = size.GetHeight() / boardWidth;
    for (int i = 1; i < boardWidth; i++) {
      path.MoveToPoint(0, xDistance * i);
      path.AddLineToPoint(size.GetWidth(), xDistance * i);
    }
    // Se encarga de calcular y agregar al path las lineas de las columnas
    // Guarda la distancia entre cada linea de las columnas del tablero con
    // ancho/cantidad de columnas
    double yDistance = size.GetWidth() / boardLength;
    for (int i = 1; i < boardLength; i++) {
      path.MoveToPoint(yDistance * i, 0);
      path.AddLineToPoint(yDistance * i, size.GetHeight());
    }

    double radius = 0;
    // Establece el radio como la mitad del espacio menor entre filas o columnas
    if (xDistance <= yDistance) {
      radius = xDistance / 2;
    } else {
      radius = yDistance / 2;
    }
    // Añade al path los circulos de las jugadas del primer jugador
    gcFirstPlayer->SetPen(wxPen(*wxRED));
    wxGraphicsPath firstPlayerPath = gcFirstPlayer->CreatePath();
    // Formula del circulo: x = linea de columna anterior a la jugada + (la
    // distancia entre columnas/2) y = linea de fila anterior a la jugada + (la
    // distancia entre filas/2)
    firstPlayerPath.AddCircle((yDistance * 0) + (yDistance / 2),
                              (xDistance * 3) + (xDistance / 2), radius);
    // Añade circulos cada vez mas pequeños al circulo anteriormente creado para
    // colorear
    for (int i = (int)radius; i >= 0; i--) {
      firstPlayerPath.AddCircle((yDistance * 0) + (yDistance / 2),
                                (xDistance * 3) + (xDistance / 2), i);
    }

    gc->StrokePath(path);
    gcFirstPlayer->StrokePath(firstPlayerPath);
    delete gc;
    delete gcFirstPlayer;
    delete gcSecondPlayer;
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

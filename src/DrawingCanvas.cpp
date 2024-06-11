#include <wx/dcbuffer.h>
#include <wx/graphics.h>

#include <DrawingCanvas.hh>
#include <Tablero.hh>
#include <cmath>
#include <memory>
#include <vector>
using namespace std;
DrawingCanvas::DrawingCanvas(wxWindow *parent, wxWindowID id,
                             const wxPoint &pos, const wxSize &size,
                             shared_ptr<Tablero> tablero)
    : wxWindow(parent, id, pos, size) {
  playableTablero = tablero;
  boardWidth = playableTablero->getColumnas();
  boardLength = playableTablero->getFilas();
  this->SetBackgroundStyle(wxBG_STYLE_PAINT);
  this->Bind(wxEVT_PAINT, &DrawingCanvas::onPaint, this);
  this->Bind(wxEVT_LEFT_DOWN, &DrawingCanvas::onMouseDown, this);
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
    double xDistance = size.GetHeight() / boardLength;
    for (int i = 1; i < boardLength; i++) {
      path.MoveToPoint(0, xDistance * i);
      path.AddLineToPoint(size.GetWidth(), xDistance * i);
    }
    // Se encarga de calcular y agregar al path las lineas de las columnas
    // Guarda la distancia entre cada linea de las columnas del tablero con
    // ancho/cantidad de columnas
    double yDistance = size.GetWidth() / boardWidth;
    for (int i = 1; i < boardWidth; i++) {
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
    // Crea el de las jugadas del primer jugador
    gcFirstPlayer->SetPen(wxPen(*wxRED));
    wxGraphicsPath firstPlayerPath = gcFirstPlayer->CreatePath();
    // Crea el de las jugadas del segundo jugador
    gcSecondPlayer->SetPen(wxPen(*wxYELLOW));
    wxGraphicsPath secondPlayerPath = gcSecondPlayer->CreatePath();
    // Formula del circulo: x = linea de columna anterior a la jugada + (la
    // distancia entre columnas/2) y = linea de fila anterior a la jugada + (la
    // distancia entre filas/2)
    vector<vector<Color>> jugadas = playableTablero->getTableroPrivado();
    for (int filas = 0; filas < boardLength; filas++) {
      for (int columnas = 0; columnas < boardWidth; columnas++) {
        if (jugadas[filas][columnas] == Color::ROJO) {
          firstPlayerPath.AddCircle((yDistance * columnas) + (yDistance / 2),
                                    (xDistance * filas) + (xDistance / 2),
                                    radius);
          // Añade circulos cada vez mas pequeños al circulo anteriormente
          // creado para colorear
          for (int i = (int)radius; i >= 0; i--) {
            firstPlayerPath.AddCircle((yDistance * columnas) + (yDistance / 2),
                                      (xDistance * filas) + (xDistance / 2), i);
          }
        } else if (jugadas[filas][columnas] == Color::AMARILLO) {
          secondPlayerPath.AddCircle((yDistance * columnas) + (yDistance / 2),
                                     (xDistance * filas) + (xDistance / 2),
                                     radius);
          // Añade circulos cada vez mas pequeños al circulo anteriormente
          // creado para colorear
          for (int i = (int)radius; i >= 0; i--) {
            secondPlayerPath.AddCircle((yDistance * columnas) + (yDistance / 2),
                                       (xDistance * filas) + (xDistance / 2),
                                       i);
          }
        }
      }
    }
    gc->StrokePath(path);
    gcFirstPlayer->StrokePath(firstPlayerPath);
    gcSecondPlayer->StrokePath(secondPlayerPath);
    delete gc;
    delete gcFirstPlayer;
    delete gcSecondPlayer;
  }
}

// Evento que maneja la selección de columna
void DrawingCanvas::onMouseDown(wxMouseEvent &event) {
  auto mousePosition = event.GetX();
  auto size = this->GetClientSize();
  double columnDistance = size.GetWidth() / boardWidth;
  // La posición de la columna es calculada con la formula:
  // función suelo((posicion en x del mouse-tamaño total de la
  // ventana)/distancia entre columnas) + cantidad de columnas
  int columnPosition =
      floor(((mousePosition - size.GetWidth()) / columnDistance) + boardWidth);
  if (playableTablero->validarMovimiento(columnPosition)) {
    // AMARILLO = segundo jugador, ROJO = primer jugador, se calcula el turno en
    // base a la cantidad de turnos jugados si es par es turno del jugador 2, si
    // no del jugador 1
    playableTablero->LlenarCasilla(
        columnPosition,
        ((playableTablero->getTurnos() % 2 != 0) ? Color::AMARILLO
                                                 : Color::ROJO));
    wxLogStatus(wxString::Format("Turno %d", playableTablero->getTurnos()));
  } else {
    wxLogStatus("Jugada incorrecta");
  }
  Refresh();
  // Post del evento de jugada
  wxCommandEvent playEvent(EVT_PLAYED);
  playEvent.SetString(" ");
  wxPostEvent(this->GetParent(), playEvent);
}
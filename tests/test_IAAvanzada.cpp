#include <gtest/gtest.h>

#include <IAAvanzada.hh>
#include <Tablero.hh>

TEST(IAAvanzadaTest, Constructor) {
  IAAvanzada IAPrueba("Nombre", true);
  ASSERT_EQ(IAPrueba.getNombre(), "Nombre");
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 0);
  ASSERT_TRUE(IAPrueba.getPrimerJugador());
}

TEST(IAAvanzadaTest, Constructor2) {
  IAAvanzada IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.getNombre(), "Nombre");
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 0);
  ASSERT_FALSE(IAPrueba.getPrimerJugador());
}

TEST(IAAvanzadaTest, MovimientoIA) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", false);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[0][0], Color::ROJO);
}

TEST(IAAvanzadaTest, MovimientoIA2) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", false);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[3][3], Color::ROJO);
}

TEST(IAAvanzadaTest, MovimientoIA3) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", false);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3| || || || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3|X|| || || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| ||X|| || |
    3|X||O|| || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  /*0| || || || |
    1| || ||X|| |
    2| ||X||X|| |
    3|X||O||O||O|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  tableroPrueba.LlenarCasilla(3, Color::AMARILLO);
  /*0| || || || |
    1| || ||X||X|
    2| ||X||X||O|
    3|X||O||O||O|
      0  1  2  3 */
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[0][3], Color::ROJO);
}

TEST(IAAvanzadaTest, MovimientoIA4) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", false);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3| || || || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(3, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3| || || ||X|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| || ||X|| |
    3| || ||O||X|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  /*0| || || || |
    1| ||X|| || |
    2| ||X||X|| |
    3|O||O||O||X|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  /*0| || || || |
    1|X||X|| || |
    2|O||X||X|| |
    3|O||O||O||X|
      0  1  2  3 */
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[0][0], Color::ROJO);
}

TEST(IAAvanzadaTest, MovimientoIA5) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", false);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[0][0], Color::ROJO);
}

TEST(IAAvanzadaTest, MovimientoIA6) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", false);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[3][3], Color::ROJO);
}

TEST(IAAvanzadaTest, MovimientoIA7) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", true);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3| || || || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3|X|| || || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| ||X|| || |
    3|X||O|| || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  /*0| || || || |
    1| || ||X|| |
    2| ||X||X|| |
    3|X||O||O||O|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  tableroPrueba.LlenarCasilla(3, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  /*0| || || || |
    1| || ||X||X|
    2|O||X||X||O|
    3|X||O||O||O|
      0  1  2  3 */
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[0][3], Color::AMARILLO);
}

TEST(IAAvanzadaTest, MovimientoIA8) {
  Tablero tableroPrueba(4, 4);
  IAAvanzada IAPrueba("Nombre", true);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3| || || || |
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(3, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| || || || |
    3| || || ||X|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  /*0| || || || |
    1| || || || |
    2| || ||X|| |
    3| || ||O||X|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  /*0| || || || |
    1| ||X|| || |
    2| ||X||X|| |
    3|O||O||O||X|
      0  1  2  3 */
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  /*0| || || || |
    1|X||X|| || |
    2|O||X||X|| |
    3|O||O||O||X|
      0  1  2  3 */
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  tableroPrueba.LlenarCasilla(movimiento, IAPrueba.computadora);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[0][0], Color::AMARILLO);
}

TEST(IAAvanzadaTest, IncrementarPartidasGanadas) {
  IAAvanzada IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 0);
  IAPrueba.incrementarPartidasGanadas();
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 1);
}

TEST(IAAvanzadaTest, maxDepth) {
  IAAvanzada IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.maxDepth, 3);
}

TEST(IAAvanzadaTest, maximizeOrMinimize1) {
  IAAvanzada IAPrueba("Nombre", true);
  ASSERT_EQ(IAPrueba.maximizeOrMinimize, 1);
}

TEST(IAAvanzadaTest, maximizeOrMinimize2) {
  IAAvanzada IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.maximizeOrMinimize, -1);
}

TEST(IAAvanzadaTest, DeterminarFichas) {
  IAAvanzada IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.jugadorHumano, Color::AMARILLO);
  ASSERT_EQ(IAPrueba.computadora, Color::ROJO);
}

TEST(IAAvanzadaTest, DeterminarFichas2) {
  IAAvanzada IAPrueba("Nombre", true);
  ASSERT_EQ(IAPrueba.jugadorHumano, Color::ROJO);
  ASSERT_EQ(IAPrueba.computadora, Color::AMARILLO);
}
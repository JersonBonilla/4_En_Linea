#include <gtest/gtest.h>

#include <Tablero.hh>

TEST(TableroTest, Constructor) {
  Tablero tableroPrueba(6, 7);
  ASSERT_EQ(tableroPrueba.getFilas(), 6);
  ASSERT_EQ(tableroPrueba.getColumnas(), 7);
  ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 42);
  ASSERT_EQ(tableroPrueba.getTableroPrivado().size(), 6);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[0].size(), 7);
}

TEST(TableroTest, LlenarCasilla) {
  Tablero tableroPrueba(10, 10);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[9][0], Color::AMARILLO);
}

TEST(TableroTest, LlenarCasilla2) {
  Tablero tableroPrueba(10, 10);
  tableroPrueba.LlenarCasilla(9, Color::AMARILLO);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[9][9], Color::AMARILLO);
}

TEST(TableroTest, ComprobarGanadorVertical) {
  Tablero tableroPrueba(5, 5);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  ASSERT_TRUE(tableroPrueba.ComprobarGanador(Color::AMARILLO));
}

TEST(TableroTest, ComprobarGanadorHorizontal) {
  Tablero tableroPrueba(5, 5);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(3, Color::AMARILLO);
  ASSERT_TRUE(tableroPrueba.ComprobarGanador(Color::AMARILLO));
}
TEST(TableroTest, ComprobarGanadorDiagonalDerechaArribaIzquierdaAbajo) {
  Tablero tableroPrueba(5, 5);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  tableroPrueba.LlenarCasilla(3, Color::ROJO);
  tableroPrueba.LlenarCasilla(3, Color::AMARILLO);
  ASSERT_TRUE(tableroPrueba.ComprobarGanador(Color::AMARILLO));
}

TEST(TableroTest, ComprobarGanadorDiagonalIzquierdaArribaDerechaAbajo) {
  Tablero tableroPrueba(5, 5);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(3, Color::AMARILLO);
  ASSERT_TRUE(tableroPrueba.ComprobarGanador(Color::AMARILLO));
}

TEST(TableroTest, ComprobarGanadorNoGanador) {
  Tablero tableroPrueba(5, 5);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::ROJO);
  tableroPrueba.LlenarCasilla(1, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(2, Color::ROJO);
  tableroPrueba.LlenarCasilla(2, Color::AMARILLO);
  ASSERT_FALSE(tableroPrueba.ComprobarGanador(Color::AMARILLO));
}

TEST(TableroTest, ComprobarCasillasDisponiblesTrasMovimiento) {
  Tablero tableroPrueba(4, 4);
  ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 16);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 15);
}

TEST(TableroTest, ComprobarEmpate) {
  Tablero tableroPrueba(4, 4);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(3, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(3, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(3, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(3, Color::PRUEBA);
  ASSERT_TRUE(tableroPrueba.ComprobarEmpate());
}

TEST(TableroTest, ComprobarNoEmpate) {
  Tablero tableroPrueba(4, 4);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(0, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(1, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(2, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(3, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(3, Color::PRUEBA);
  tableroPrueba.LlenarCasilla(3, Color::PRUEBA);
  ASSERT_FALSE(tableroPrueba.ComprobarEmpate());
}

TEST(TableroTest, MovimientoInvalido) {
  Tablero tableroPrueba(4, 4);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  ASSERT_FALSE(tableroPrueba.validarMovimiento(0));
}

TEST(TableroTest, MovimientoValido) {
  Tablero tableroPrueba(4, 4);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  ASSERT_TRUE(tableroPrueba.validarMovimiento(0));
}

TEST(TableroTest, ComprobarTurnos) {
  Tablero tableroPrueba(4, 4);
  ASSERT_EQ(tableroPrueba.getTurnos(), 0);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  ASSERT_EQ(tableroPrueba.getTurnos(), 1);
  tableroPrueba.LlenarCasilla(0, Color::ROJO);
  ASSERT_EQ(tableroPrueba.getTurnos(), 2);
}

TEST(TableroTest, ComprobarJugador1) {
  Tablero tableroPrueba(4, 4);
  ASSERT_EQ(tableroPrueba.getJugador1(), Color::AMARILLO);
}

TEST(TableroTest, ComprobarJugador2) {
  Tablero tableroPrueba(4, 4);
  ASSERT_EQ(tableroPrueba.getJugador2(), Color::ROJO);
}

TEST(TableroTest, ComprobarVacio) {
  Tablero tableroPrueba(4, 4);
  ASSERT_EQ(tableroPrueba.getFichaVacia(), Color::VACIO);
}

TEST(TableroTest, LimpiarTablero) {
  Tablero tableroPrueba(10, 10);
  ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 100);
  tableroPrueba.LlenarCasilla(0, Color::AMARILLO);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[9][0], Color::AMARILLO);
  ASSERT_EQ(tableroPrueba.getTurnos(), 1);
  ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 99);
  tableroPrueba.limpiarTablero();
  ASSERT_EQ(tableroPrueba.getTurnos(), 0);
  ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 100);
  ASSERT_EQ(tableroPrueba.getTableroPrivado()[9][0], Color::VACIO);
}
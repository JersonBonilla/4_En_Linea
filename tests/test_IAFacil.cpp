#include <gtest/gtest.h>

#include <IAFacil.hh>
#include <Tablero.hh>

TEST(IAFacilTest, Constructor) {
  IAFacil IAPrueba("Nombre", true);
  ASSERT_EQ(IAPrueba.getNombre(), "Nombre");
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 0);
  ASSERT_TRUE(IAPrueba.getPrimerJugador());
}

TEST(IAFacilTest, Constructor2) {
  IAFacil IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.getNombre(), "Nombre");
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 0);
  ASSERT_FALSE(IAPrueba.getPrimerJugador());
}

TEST(IAFacilTest, MovimientoIA) {
  srand(time(0));
  Tablero tableroPrueba(6, 7);
  IAFacil IAPrueba("Nombre", false);
  int movimiento = IAPrueba.movimientoIA(tableroPrueba);
  bool funciona = false;
  if (movimiento <= 6 && movimiento >= 0) {
    funciona = true;
  }
  ASSERT_TRUE(funciona);
}

TEST(IAFacilTest, IncrementarPartidasGanadas) {
  IAFacil IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 0);
  IAPrueba.incrementarPartidasGanadas();
  ASSERT_EQ(IAPrueba.getPartidasGanadas(), 1);
}

TEST(IAFacilTest, Ficha) {
  IAFacil IAPrueba("Nombre", true);
  ASSERT_EQ(IAPrueba.fichaIA, Color::AMARILLO);
}

TEST(IAFacilTest, Ficha2) {
  IAFacil IAPrueba("Nombre", false);
  ASSERT_EQ(IAPrueba.fichaIA, Color::ROJO);
}
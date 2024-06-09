#include <gtest/gtest.h>

#include <JugadorHumano.hh>
#include <Tablero.hh>

TEST(JugadorHumanoTest, Constructor) {
  JugadorHumano JPrueba("Nombre", true);
  ASSERT_EQ(JPrueba.getNombre(), "Nombre");
  ASSERT_EQ(JPrueba.getPartidasGanadas(), 0);
  ASSERT_TRUE(JPrueba.getPrimerJugador());
}

TEST(JugadorHumanoTest, Constructor2) {
  JugadorHumano JPrueba("Nombre", false);
  ASSERT_EQ(JPrueba.getNombre(), "Nombre");
  ASSERT_EQ(JPrueba.getPartidasGanadas(), 0);
  ASSERT_FALSE(JPrueba.getPrimerJugador());
}

TEST(JugadorHumanoTest, IncrementarPartidasGanadas) {
  JugadorHumano JPrueba("Nombre", false);
  ASSERT_EQ(JPrueba.getPartidasGanadas(), 0);
  JPrueba.incrementarPartidasGanadas();
  ASSERT_EQ(JPrueba.getPartidasGanadas(), 1);
}

TEST(JugadorHumanoTest, Ficha) {
  JugadorHumano JPrueba("Nombre", true);
  ASSERT_EQ(JPrueba.fichaJugador, Color::AMARILLO);
}

TEST(JugadorHumanoTest, Ficha2) {
  JugadorHumano JPrueba("Nombre", false);
  ASSERT_EQ(JPrueba.fichaJugador, Color::ROJO);
}
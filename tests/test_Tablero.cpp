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
    tableroPrueba.LlenarCasilla(0,'x');
    ASSERT_EQ(tableroPrueba.getTableroPrivado()[9][0], 'x');
}

TEST(TableroTest, LlenarCasilla2) {
    Tablero tableroPrueba(10, 10);
    tableroPrueba.LlenarCasilla(9,'x');
    ASSERT_EQ(tableroPrueba.getTableroPrivado()[9][9], 'x');
}

TEST(TableroTest, ComprobarGanadorVertical) {
    Tablero tableroPrueba(5, 5);
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(0,'x');
    ASSERT_TRUE(tableroPrueba.ComprobarGanador('x'));
}

TEST(TableroTest, ComprobarGanadorHorizontal) {
    Tablero tableroPrueba(5, 5);
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(1,'x');
    tableroPrueba.LlenarCasilla(2,'x');
    tableroPrueba.LlenarCasilla(3,'x');
    ASSERT_TRUE(tableroPrueba.ComprobarGanador('x'));
}
TEST(TableroTest, ComprobarGanadorDiagonalDerechaArribaIzquierdaAbajo) {
    Tablero tableroPrueba(5, 5);
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(1,'o');
    tableroPrueba.LlenarCasilla(1,'x');
    tableroPrueba.LlenarCasilla(2,'o');
    tableroPrueba.LlenarCasilla(2,'o');
    tableroPrueba.LlenarCasilla(2,'x');
    tableroPrueba.LlenarCasilla(3,'o');
    tableroPrueba.LlenarCasilla(3,'o');
    tableroPrueba.LlenarCasilla(3,'o');
    tableroPrueba.LlenarCasilla(3,'x');
    ASSERT_TRUE(tableroPrueba.ComprobarGanador('x'));
}

TEST(TableroTest, ComprobarGanadorDiagonalIzquierdaArribaDerechaAbajo) {
    Tablero tableroPrueba(5, 5);
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(1,'o');
    tableroPrueba.LlenarCasilla(1,'o');
    tableroPrueba.LlenarCasilla(1,'x');
    tableroPrueba.LlenarCasilla(2,'o');
    tableroPrueba.LlenarCasilla(2,'x');
    tableroPrueba.LlenarCasilla(3,'x');
    ASSERT_TRUE(tableroPrueba.ComprobarGanador('x'));
}

TEST(TableroTest, ComprobarGanadorNoGanador) {
    Tablero tableroPrueba(5, 5);
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(1,'o');
    tableroPrueba.LlenarCasilla(1,'o');
    tableroPrueba.LlenarCasilla(1,'x');
    tableroPrueba.LlenarCasilla(2,'o');
    tableroPrueba.LlenarCasilla(2,'x');
    ASSERT_FALSE(tableroPrueba.ComprobarGanador('x'));
}

TEST(TableroTest, ComprobarCasillasDisponiblesTrasMovimiento) {
    Tablero tableroPrueba(4, 4);
    ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 16);
    tableroPrueba.LlenarCasilla(0,'x');
    ASSERT_EQ(tableroPrueba.getCasillasDisponibles(), 15);
}

TEST(TableroTest, ComprobarEmpate) {
    Tablero tableroPrueba(4, 4);
    tableroPrueba.LlenarCasilla(0,'0');
    tableroPrueba.LlenarCasilla(0,'1');
    tableroPrueba.LlenarCasilla(0,'2');
    tableroPrueba.LlenarCasilla(0,'3');
    tableroPrueba.LlenarCasilla(1,'4');
    tableroPrueba.LlenarCasilla(1,'5');
    tableroPrueba.LlenarCasilla(1,'6');
    tableroPrueba.LlenarCasilla(1,'7');
    tableroPrueba.LlenarCasilla(2,'8');
    tableroPrueba.LlenarCasilla(2,'9');
    tableroPrueba.LlenarCasilla(2,'1');
    tableroPrueba.LlenarCasilla(2,'2');
    tableroPrueba.LlenarCasilla(3,'3');
    tableroPrueba.LlenarCasilla(3,'4');
    tableroPrueba.LlenarCasilla(3,'5');
    tableroPrueba.LlenarCasilla(3,'6');
    ASSERT_TRUE(tableroPrueba.ComprobarEmpate());
}

TEST(TableroTest, ComprobarNoEmpate) {
    Tablero tableroPrueba(4, 4);
    tableroPrueba.LlenarCasilla(0,'0');
    tableroPrueba.LlenarCasilla(0,'1');
    tableroPrueba.LlenarCasilla(0,'2');
    tableroPrueba.LlenarCasilla(0,'3');
    tableroPrueba.LlenarCasilla(1,'4');
    tableroPrueba.LlenarCasilla(1,'5');
    tableroPrueba.LlenarCasilla(1,'6');
    tableroPrueba.LlenarCasilla(1,'7');
    tableroPrueba.LlenarCasilla(2,'8');
    tableroPrueba.LlenarCasilla(2,'9');
    tableroPrueba.LlenarCasilla(2,'1');
    tableroPrueba.LlenarCasilla(2,'2');
    tableroPrueba.LlenarCasilla(3,'3');
    tableroPrueba.LlenarCasilla(3,'4');
    tableroPrueba.LlenarCasilla(3,'5');
    ASSERT_FALSE(tableroPrueba.ComprobarEmpate());
}

TEST(TableroTest, MovimientoInvalido) {
    Tablero tableroPrueba(4, 4);
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(0,'o');
    ASSERT_FALSE(tableroPrueba.validarMovimiento(0));
}

TEST(TableroTest, MovimientoValido) {
    Tablero tableroPrueba(4, 4);
    tableroPrueba.LlenarCasilla(0,'x');
    tableroPrueba.LlenarCasilla(0,'o');
    tableroPrueba.LlenarCasilla(0,'x');
    ASSERT_TRUE(tableroPrueba.validarMovimiento(0));
}
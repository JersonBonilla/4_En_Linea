#include <gtest/gtest.h>
#include <Tablero.hh>

TEST(TableroTest, Constructor) {
    Tablero tableroPrueba(6, 7);
    int numeroFilas = tableroPrueba.getFilas();
    int numeroColumnas = tableroPrueba.getColumnas();
    vector<vector<char>> tableroPublicoPrueba;
    tableroPublicoPrueba = tableroPrueba.getTableroPrivado();
    ASSERT_EQ(numeroFilas, 6);
    ASSERT_EQ(numeroColumnas, 7);
    ASSERT_EQ(tableroPublicoPrueba.size(), 6);
    ASSERT_EQ(tableroPublicoPrueba[0].size(), 7);
}
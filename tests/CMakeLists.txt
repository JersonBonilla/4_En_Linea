enable_testing()
find_package(GTest REQUIRED)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(unit_tests
# TODO: Añadan acá todos los archivos de pruebas
    test_Tablero.cpp
    test_IAFacil.cpp
    test_IAAvanzada.cpp
    test_JugadorHumano.cpp
# TODO: Añadan acá el código fuente de su proyecto. Por ejemplo:
#    ../src/aaa.cpp
    ../src/Tablero.cc
    ../src/IAFacil.cc
    ../src/IAAvanzada.cc
    ../src/JugadorHumano.cc
)

target_link_libraries(unit_tests
    GTest::gtest
    GTest::gtest_main)

add_test(AllTests unit_tests)

target_include_directories(unit_tests PUBLIC ${INCLUDE_DIR})


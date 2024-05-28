enable_testing()
find_package(GTest REQUIRED)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(unit_tests
# TODO: Añadan acá todos los archivos de pruebas
    test_Tablero.cpp
# TODO: Añadan acá el código fuente de su proyecto. Por ejemplo:
#    ../src/aaa.cpp
    ../src/Tablero.cc
)

target_link_libraries(unit_tests
    GTest::gtest
    GTest::gtest_main)

add_test(AllTests unit_tests)

target_include_directories(unit_tests PUBLIC ${INCLUDE_DIR})


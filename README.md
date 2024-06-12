# Miembros Jerson Bonilla - C31225 y Marco Fernandez - C32885
# Proyecto: 4 en línea

## i. Pasos para compilar el programa
### Requisitos
Asegúrese de tener instalados los índices más recientes de apt. Ejecute:

```bash
sudo apt-get update
```

El proyecto requiere CMake 3.24. En caso de no tener instalada esta versión, ejecute los siguientes comandos:

```bash
# Desinstalar cmake
sudo apt-get purge cmake

# Instalar la versión más reciente de CMake desde snap
sudo snap install cmake --classic
```

Para acelerar la compilación, también se recomienda utilizar Ninja:

```bash
sudo apt-get install ninja-build
```

Para instalar wxWidgets, se recomienda seguir los siguientes pasos:

```bash
sudo apt-get install libwxgtk3.0-gtk3-dev
```

Para instalar Google Test, se recomienda seguir los siguientes pasos:

```bash
sudo apt-get install libgtest-dev
```

### Compilación
Dentro de la carpeta del proyecto, en la consola de comandos, ejecute los siguientes comandos: 

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

## ii. Cómo usar el programa
### En la terminal
Si desea usar el programa dentro de la terminal, es decir, el andamiaje, ejecute el siguiente comando:

```bash
./build/src/Jugar_En_Terminal
```

### Con la interfaz gráfica
Si desea usar el programa con la interfaz gráfica, es decir, el ejecutable principal, ejecute el siguiente comando:

```bash
./build/src/4_En_Linea
```

## iii. Funcionalidad implementada
1. Lógica del tablero (Jerson Bonilla)
2. Lógica de la clase Ijugador (Jerson Bonilla)
3. Lógica de la clases que heredan de IJugador: JugadorHumano, IAFacil e IAAvanzada (Jerson Bonilla)
4. Algoritmos de las inteligencias artificiales:
    1. La IAFacil devuelve movimientos aleatorios. (Jerson Bonilla)
    2. La IAvanzada implementa el algoritmo Minimax, que realiza una evaluación del tablero y devuelve un movimiento con base en su estado actual. (Jerson Bonilla)
5. Andamiaje en terminal (Jerson Bonilla)
6. Validación de datos en la terminal (Jerson Bonilla)
7. Tamaño variable del tablero: de 4 a 10 filas y de 4 a 10 columnas  (Jerson Bonilla)
8. Reinicio del tablero
9. Pruebas unitarias: Tablero, JugadorHumano, IAFacil, IAAvanzada (Jerson Bonilla)
10. Interfaz gráfica:
    1. Ménu de nuevo juego (Marco Fernández)
    2. Ingreso de los nombre de los jugadores (Marco Fernández)
    3. Selección del tipo de jugadores (Marco Fernández)
    4. Botón para seleccionar las filas: permite de 4 hasta 10 (Marco Fernández)
    5. Botón para seleccionar las columnas: permite de 4 hasta 10 (Marco Fernández)
11. Dibujo del tablero (Marco Fernández)
12. Recepción de movimientos por parte del usuario mediante la selección de columna al pulsar el ratón (Marco Fernández)
13. Dibujo de las fichas (Marco Fernández)
14. Detección de victorias (Marco Fernández)
15. Detección de empates (Marco Fernández)
16. Implementación de revanchas y creación de nueva partida con la misma configuración (Marco Fernández)
17. Creación de nueva partida con una nueva configuración (Marco Fernández)
18. Conexión entre los métodos de IJugador e interfaz gráfica (Marco Fernández y Jerson Bonilla)

## iv. Funcionalidad no implementada
1. Niveles intermedios de inteligencia artificial.
2. Cronometración del tiempo tomado por el algortimo Minimax.
3. Pruebas para la interfaz gráfica.

## v. Errores conocidos
1. En ocasiones al enfrentar dos inteligencias artificiales entre sí, tras varias partidas, pueden llegar a ocurrir errores al cargar el tablero en caso de una revancha.
2. Al hacer una revancha, la ventana correspondiente a la nueva partida se crea un poco pequeña en una esquina, sin embargo, basta con agrandarla para poder visualizarla de nuevo con comodidad.
3. Es posible que la IAAvanzada no envíe el mejor movimiento en caso de ser el primer jugador.
4. Es posible que realizar muchos clicks con el ratón muy rápidamente cause algún problema con la emisión de movimientos en juegos de humano contra IA.
5. La interfaz parece no soportar caracteres especiales como la tilde (´), "¿", "ç", entre otros.

## vi. Ejecutar las pruebas
Para ejecutar las pruebas unitarias, use el siguiente comando en la terminal:

```bash
./build/tests/unit_tests
```

## vii. Imagenes del juego
### En la terminal
![](images/Screenshot%20from%202024-06-12%2011-35-52.png)

*Selección de jugadores y tablero*

![](images/Screenshot%20from%202024-06-12%2011-36-04.png)

*Inicio de la partida*

![](images/Screenshot%20from%202024-06-12%2011-36-27.png)

*Finalización de la partida*

![](images/Screenshot%20from%202024-06-12%2011-36-32.png)

*Revancha y estadísticas de los jugadores*

![](images/Screenshot%20from%202024-06-12%2011-36-54.png)

*Salir*

### Con la interfaz gráfica
![](images/Screenshot%20from%202024-06-12%2011-37-09.png)

*Menú de selección*

![](images/Screenshot%20from%202024-06-12%2011-37-50.png)

*Selección de jugadores*

![](images/Screenshot%20from%202024-06-12%2011-37-53.png)

*Dibujo del tablero*

![](images/Screenshot%20from%202024-06-12%2011-38-01.png)

*Emisión del movimiento y dibujo de la ficha*

![](images/Screenshot%20from%202024-06-12%2011-38-05.png)

*Emisión del segundo movimiento y dibujo de la ficha*

![](images/Screenshot%20from%202024-06-12%2011-38-15.png)

*Botón de revancha que aparece tras terminar una partida*

![](images/Screenshot%20from%202024-06-12%2011-39-11.png)

*Botón de revancha sobre el tablero*

![](images/Screenshot%20from%202024-06-12%2011-40-11.png)

*Selección de dos IAs como jugadores*

![](images/Screenshot%20from%202024-06-12%2011-40-15.png)

*Estado final del juego entre dos IAs*

![](images/Screenshot%20from%202024-06-12%2011-40-20.png)

*Revancha entre dos IAs*

![](images/Screenshot%20from%202024-06-12%2011-40-54.png)

*Botón de about*

![](images/Screenshot%20from%202024-06-12%2011-41-01.png)

*Información del botón de about*

## viii. Más información importante
1. Se escogió la ficha amarilla para el primer jugador y la roja para el segundo.
2. Al enfrentarse dos IAs, los movimientos se emiten muy rápidamente, por lo que sólo se muestra el estado final de la partida, cuando se utiliza la interfaz gráfica. Sin embargo, es posible observar la evolución de una partida entre IAs al ejecutar el programa en la terminal, puesto que tras cada movimiento se vuelve a imprimir el tablero.

# Divide y vencerás

Proyecto del **Módulo 1** de la materia **Análisis y Diseño de Algoritmos Avanzados**.

El proyecto compara distintos métodos para obtener la mediana de un conjunto de números y contiene una miniaplicación web que muestra de forma visual el funcionamiento de la partición de **Lomuto** mediante QuickSort.

## Equipo

- Elvia Rebeca Martínez Ponce
- José Luis Gutiérrez Quintero
- Sergio Sebastián Cortez Yepez

## Profesor

- Dr. Juan Manuel Ahuactin Larios


## Estructura del proyecto

```text
Divide-y-venceras-main/
│
├── Parte-1/
│   ├── Compile.py
│   ├── lomuto.cpp
│   ├── med-de-med.cpp
│   ├── ord-selec.cpp
│   └── inputs/
│       ├── input_gen.py
│       └── input*_*.txt
│
├── Parte-2/
│   ├── index.html
│   ├── script.js
│   ├── styles.css
│   └── Lomuto/
│       └── imágenes utilizadas por la visualización
│
└── README.md
```

## Requisitos

Para ejecutar la *Parte 1* se necesita:

- Un compilador compatible con **C++17**. Por ejemplo, `g++` de MinGW/MSYS2 en Windows o GCC en Linux.
- Python 3 si se desea utilizar `Compile.py` para compilar y ejecutar automáticamente las pruebas, o si se desea volver a generar archivos de prueba con `input_gen.py`.

Para ejecutar la *Parte 2* se necesita:

- Un navegador web moderno, como Chrome, Edge o Firefox.
- Live Server Extension (opcional)

---

# Parte 1: cálculo de la mediana

La carpeta `Parte-1` contiene tres programas independientes. Cada archivo `.cpp` tiene su propia función `main`, por lo que puede compilarse y ejecutarse por separado. También se incluye `Compile.py`, que automatiza la compilación y ejecución de los tres programas.

Los métodos implementados son:

- `ord-selec.cpp`: ordena el arreglo mediante *Merge Sort* y selecciona el elemento central.
- `lomuto.cpp`: obtiene la mediana mediante *QuickSelect con partición de Lomuto*.
- `med-de-med.cpp`: utiliza el algoritmo *Mediana de Medianas (BFPRT)* para seleccionar el elemento central.

## Formato de entrada

Los tres programas reciben los datos por la entrada estándar con el siguiente formato:

```text
n
x1 x2 x3 ... xn
```

Donde:

- `n` es el número de elementos.
- Después se proporcionan los `n` números enteros del arreglo.


La salida de cada programa contiene el valor de la mediana y el tiempo utilizado únicamente para calcularla:

```text
5 0.012
```

El primer valor corresponde a la mediana y el segundo al tiempo de ejecución del algoritmo en milisegundos. La lectura de los datos de entrada no forma parte de esta medición.

Los archivos incluidos en `Parte-1/inputs/` ya tienen este formato.

## Compilación y ejecución

Existen dos formas de trabajar con los programas de la *Parte 1*: compilarlos por separado o utilizar `Compile.py`.

### Opción 1: compilación por separado

Esta opción es útil cuando se desea ejecutar o revisar un algoritmo de manera individual. También permite probar manualmente un archivo `.cpp` sin ejecutar los otros dos.

Abrir una terminal dentro de la carpeta `Parte-1` y ejecutar:

#### Linux / macOS / MSYS2

```bash
g++ -std=c++17 -O2 lomuto.cpp -o lomuto
g++ -std=c++17 -O2 med-de-med.cpp -o med-de-med
g++ -std=c++17 -O2 ord-selec.cpp -o ord-selec
```

#### Windows con g++

```bash
g++ -std=c++17 -O2 lomuto.cpp -o lomuto.exe
g++ -std=c++17 -O2 med-de-med.cpp -o med-de-med.exe
g++ -std=c++17 -O2 ord-selec.cpp -o ord-selec.exe
```

Cada comando genera un ejecutable distinto.

Esta forma se recomienda cuando:

- Se desea probar solamente uno de los algoritmos.
- Se quiere introducir una entrada manual.
- Se está revisando o depurando un archivo `.cpp` en particular.

### Opción 2: usar `Compile.py`

Dentro de `Parte-1` se encuentra el archivo `Compile.py`. Este script compila automáticamente los tres programas con las mismas opciones de compilación y después ejecuta todos los archivos de prueba encontrados en la carpeta `inputs`.

Para utilizarlo, abrir una terminal dentro de `Parte-1` y ejecutar:

```bash
python Compile.py
```

En algunos sistemas puede ser necesario utilizar:

```bash
python3 Compile.py
```

El script:

- Compila `ord-selec.cpp`, `lomuto.cpp` y `med-de-med.cpp`.
- Ejecuta los tres algoritmos con los mismos archivos de prueba.
- Muestra la mediana obtenida.
- Muestra el tiempo de cálculo de la mediana reportado por cada programa en milisegundos.
- Comprueba que los tres algoritmos hayan obtenido la misma mediana. Si coinciden, muestra `OK`.

Ejemplo de salida:

```text
input1_100001.txt | Mediana: 50001 | Ordena: 17.546 ms | Lomuto: 0.879 ms | Med. Medianas: 8.530 ms | OK
```

`Compile.py` se recomienda cuando se desea probar rápidamente todos los algoritmos bajo las mismas condiciones y comparar sus resultados y tiempos sin compilar ni ejecutar cada programa de forma manual.

La compilación por separado y `Compile.py` utilizan los mismos archivos `.cpp`; la diferencia es que `Compile.py` automatiza el proceso.

## Ejecución manual (Opcional)

Después de compilar, se puede ejecutar cualquiera de los programas e introducir los datos manualmente.

Ejemplo en Windows:

```text
lomuto.exe
5
9 1 5 3 7
```

Ejemplo en Linux/macOS:

```bash
./lomuto
```

Después se escriben `n` y los elementos del arreglo.

## Ejecución usando los archivos de prueba (Preferible)

Desde la carpeta `Parte-1` se puede redirigir un archivo de entrada hacia el programa.

### Linux / macOS / terminal MSYS2

```bash
./lomuto < inputs/input1_100001.txt
./med-de-med < inputs/input1_100001.txt
./ord-selec < inputs/input1_100001.txt
```

### Windows CMD

```cmd
lomuto.exe < inputs\input1_100001.txt
med-de-med.exe < inputs\input1_100001.txt
ord-selec.exe < inputs\input1_100001.txt
```

Si se está usando PowerShell, también se puede ejecutar el comando de CMD de esta forma:

```powershell
cmd /c "lomuto.exe < inputs\input1_100001.txt"
```

Para probar otro tamaño, basta con cambiar el nombre del archivo de entrada. El proyecto contiene cinco pruebas para varios tamaños, desde `100001` hasta `1000001` elementos.

---

## Generación de archivos de prueba (En caso de necesitar mas pruebas)

Dentro de `Parte-1/inputs/` se encuentra `input_gen.py`.

El script genera cinco archivos con números del `1` al `n` colocados en orden aleatorio.

Para ejecutarlo:

```bash
cd inputs
python input_gen.py
```

En algunos sistemas el comando puede ser:

```bash
python3 input_gen.py
```

El tamaño de la entrada se controla con la variable:

```python
n = 1000001
```

Si se desea otro tamaño, se cambia ese valor antes de ejecutar el script.

---

# Parte 2: miniaplicación visual de Lomuto

La carpeta `Parte-2` contiene una visualización web de **QuickSort usando la partición de Lomuto**. Los valores del arreglo se representan mediante labiales que cambian de posición durante el proceso de ordenamiento.

Esta parte está desarrollada con:

- HTML
- CSS
- JavaScript

No necesita compilación.

## Ejecución

1. Entrar a la carpeta `Parte-2`.
2. Abrir el archivo `index.html` en un navegador web (Live Server).
3. Escribir los valores separados por comas.
4. Presionar **Colocar en tocador**.
5. Presionar **Ordenar** para iniciar la animación del algoritmo.

También puede abrirse utilizando una extensión como **Live Server** de Visual Studio Code, aunque no es obligatoria.

## Valores disponibles en la visualización

La aplicación contiene imágenes para los siguientes valores:

```text
5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55
```

Por esta razón, para visualizar correctamente los labiales se recomienda utilizar esos valores, separados por comas. Por ejemplo:

```text
55, 15, 45, 5, 25, 50, 10, 35, 20, 40, 30
```

---

### Resumen rápido de ejecución

```text
1. Entrar a Parte-1.
2. Elegir una opción:
   - Compilar cada .cpp por separado para probar un algoritmo individual.
   - Ejecutar Compile.py para compilar y probar automáticamente los tres algoritmos.
3. Si se compila por separado, ejecutar el programa manualmente o redirigir uno de los archivos de inputs/.
4. Para la miniaplicación, abrir Parte-2/index.html en el navegador.
```


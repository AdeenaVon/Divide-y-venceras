#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono> //Solo para medir el tiempo exacto

using namespace std;

// Función para unir las dos mitades
void unir(vector<int>& lista, int inicio, int mitad, int fin) {
    int i, j, k;
    int tamIzq = mitad - inicio + 1; // Tamaño de la mitad izquierda
    int tamDer = fin - mitad;        // Tamaño de la mitad derecha

    // Crear vectores temporales
    vector<int> mitadIzq(tamIzq), mitadDer(tamDer);

    // Copiar los datos a los vectores temporales
    for (i = 0; i < tamIzq; i++)
        mitadIzq[i] = lista[inicio + i];
    for (j = 0; j < tamDer; j++)
        mitadDer[j] = lista[mitad + 1 + j];

    // Unir los vectores temporales de vuelta en la lista original
    i = 0;
    j = 0;
    k = inicio;
    
    // Comparamos elementos de ambas mitades y colocamos el menor en la lista original
    while (i < tamIzq && j < tamDer) {
        if (mitadIzq[i] <= mitadDer[j]) {
            lista[k] = mitadIzq[i];
            i++;
        } else {
            lista[k] = mitadDer[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de la mitad izquierda (si sobraron)
    while (i < tamIzq) {
        lista[k] = mitadIzq[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de la mitad derecha (si sobraron)
    while (j < tamDer) {
        lista[k] = mitadDer[j];
        j++;
        k++;
    }
}

// Función recursiva que divide el arreglo
void ordenaMerge(vector<int>& lista, int inicio, int fin) {
    if (inicio < fin) {
        // Calcular el punto medio (se hace así para evitar desbordamiento de memoria)
        int mitad = inicio + (fin - inicio) / 2;

        // Ordenar la primera y segunda mitad recursivamente
        ordenaMerge(lista, inicio, mitad);
        ordenaMerge(lista, mitad + 1, fin);

        // Unir las mitades ya ordenadas
        unir(lista, inicio, mitad, fin);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    auto inicio = chrono::high_resolution_clock::now();

    ordenaMerge(arr, 0, n - 1);
    int mediana = arr[n/2];
    
    auto fin = chrono::high_resolution_clock::now();
    double tiempo = chrono::duration<double, milli>(fin - inicio).count();
    
    cout << mediana << " " << tiempo;

    return 0;
}
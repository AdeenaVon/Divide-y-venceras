#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> //Solo para medir tiempo exacto

using namespace std;


int select_bfprt(vector<int>& arr, int k){
    int n = arr.size();

    if(n<=5) {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        return sorted_arr[k];
    }

    // 1) Grupos de 5 y medianas
    vector<int> medianas;
    for(int i=0; i<n; i+=5){
        int end = min(i + 5, n);
        vector<int> grupo(arr.begin() + i, arr.begin() + end);
        sort(grupo.begin(), grupo.end());
        medianas.push_back(grupo[grupo.size() / 2]);
    }

    // 2) Pivote = mediana de medianas (recursivo)
    int nMed = medianas.size();
    int pivote = select_bfprt(medianas, nMed / 2);

    // 3) Particion: < pivote, == pivote, > pivote
    vector<int> L, E, G;
    for(int x : arr){
        if(x < pivote) L.push_back(x);
        if(x == pivote) E.push_back(x);
        if(x > pivote) G.push_back(x);
    }

    if(k < L.size()) return select_bfprt(L, k);
    else if(k < L.size() + E.size()) return pivote;
    else return select_bfprt(G, k - L.size() - E.size());
}

int main() {
    int n;
    float mediana;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    auto inicio = chrono::high_resolution_clock::now();

    if(n % 2) mediana = select_bfprt(arr, n / 2);
    else {
        int lo = select_bfprt(arr, n / 2 - 1);
        int hi = select_bfprt(arr, n / 2);
        mediana = (lo + hi) / 2.0;
    }

    auto fin = chrono::high_resolution_clock::now();

    double tiempo = chrono::duration<double, milli>(fin - inicio).count();

    cout << mediana << " " << tiempo;
    return 0;
}

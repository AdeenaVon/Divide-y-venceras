#include <iostream>
#include <vector>

using namespace std;

int particion_lomuto(vector<int>& arr,int bajo, int alto){
    int i=bajo-1, j=bajo, aux;
    while (j<=alto){
        if(arr[j] <= arr[alto]){
            i++;

            aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
        j++;
    }
    return i;
}

int quickselect(vector<int>& arr, int k){
    int bajo = 0;
    int alto = arr.size() - 1;
    int iMedi = -1;

    while (iMedi != k){
        iMedi = particion_lomuto(arr,bajo,alto);
        if(iMedi < k) bajo = iMedi + 1;
        else if(iMedi > k) alto = iMedi - 1;
    }

    return arr[iMedi];
}


int main() {
    int n;
    float mediana;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    if(n%2) mediana = quickselect(arr, n / 2);
    else{
        int hi = quickselect(arr, n / 2);
        int lo = quickselect(arr, n / 2 - 1);
        mediana = (lo + hi) / 2.0;
    }

    cout << mediana;

    return 0;
}

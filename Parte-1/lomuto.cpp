#include <iostream>

using namespace std;


int particion_lomuto(int arr[],int bajo, int alto){
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

int main() {
    int n, iMedi=-1;
    cin >> n;
    int arr[n],bajo=0,alto=n-1;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    while (iMedi != n/2){
        iMedi = particion_lomuto(arr,bajo,alto);
        if(iMedi < n/2) bajo = iMedi;
        if(iMedi > n/2) alto = iMedi;
    }
    


    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl << iMedi;
    return 0;
}

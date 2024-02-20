#include <iostream>
#include <vector>

using namespace std;

// Untuk Mengeksekusi Merge Sort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Untuk Mengeksekusi Shotgun Merge Sort
void shotgunMergeSort(vector<int>& arr, int l, int r) {
    if (r - l <= 10) { // Gunakan algoritma pengurutan lain untuk array kecil
        // Contoh: Insertion Sort / Sortir Penyisipan
        for (int i = l + 1; i <= r; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= l && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    } else {
        int m = l + (r - l) / 2;
        shotgunMergeSort(arr, l, m);
        shotgunMergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr_init[] = {12, 11, 13, 5, 6, 7};
    vector<int> arr(arr_init, arr_init + sizeof(arr_init) / sizeof(arr_init[0]));

    cout << "Array Sebelum Shorting :\n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Menggunakan Merge Sort
    mergeSort(arr, 0, arr.size() - 1);

    cout << "Array Setelah Merge Sort:\n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Menggunakan Shotgun Merge Sort
    shotgunMergeSort(arr, 0, arr.size() - 1);

    cout << "Array Setelah Shotgun Merge Sort:\n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

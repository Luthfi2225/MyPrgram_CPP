#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menukar dua elemen dalam array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk memilih pivot dan mempartisi array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Pilih pivot sebagai elemen terakhir
    int i = low - 1; // Indeks elemen yang lebih kecil dari pivot

    for (int j = low; j < high; j++) {
        // Jika elemen saat ini lebih kecil dari atau sama dengan pivot
        if (arr[j] <= pivot) {
            i++; // Pindahkan indeks elemen yang lebih kecil
            swap(arr[i], arr[j]);
        }
    }

    // Pindahkan pivot ke posisi yang tepat
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Fungsi Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Temukan pivot yang tepat
        int pi = partition(arr, low, high);

        // Urutkan elemen sebelum dan setelah pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr_init[] = {12, 11, 13, 5, 6, 7};
    vector<int> arr(arr_init, arr_init + sizeof(arr_init) / sizeof(arr_init[0]));

    cout << "Array sebelum sorting:\n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Menggunakan Quick Sort
    quickSort(arr, 0, arr.size() - 1);

    cout << "Array setelah sorting:\n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}


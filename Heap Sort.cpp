#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk melakukan pengaturan (heapify) dari simpul di posisi i dalam array
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // inisialisasi largest sebagai root
    int l = 2 * i + 1; // kiri = 2*i + 1
    int r = 2 * i + 2; // kanan = 2*i + 2

    // Jika simpul kiri anak lebih besar dari root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Jika simpul kanan anak lebih besar dari largest yang sekarang
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Jika largest tidak berada di root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Rekursif untuk heapify subtree yang terpengaruh
        heapify(arr, n, largest);
    }
}

// Fungsi untuk melakukan Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Membangun heap (mengubah array menjadi heap)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Menjalankan ekstraksi elemen satu per satu dari heap
    for (int i = n - 1; i > 0; i--) {
        // Pindahkan root saat ini ke ujung
        swap(arr[0], arr[i]);

        // Panggil fungsi heapify pada heap yang direduksi
        heapify(arr, i, 0);
    }
}

int main() {
    int arr_init[] = {12, 11, 13, 5, 6, 7};
    vector<int> arr(arr_init, arr_init + sizeof(arr_init) / sizeof(arr_init[0]));

    cout << "Array sebelum sorting:\n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Menggunakan Heap Sort
    heapSort(arr);

    cout << "Array setelah sorting:\n";
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

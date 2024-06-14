//Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>

// Fungsi untuk menggabungkan dua array terurut menjadi satu array terurut
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Buat array sementara
    int L[n1], R[n2];

    // Salin data ke array sementara L[] dan R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Gabungkan array sementara kembali menjadi arr[l..r]
    i = 0;
    j = 0;
    k = l;
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

    // Salin sisa elemen dari L[], jika ada
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen dari R[], jika ada
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi rekursif untuk melakukan pengurutan dengan Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Temukan titik tengah
        int m = l + (r - l) / 2;

        // Urutkan setengah bagian kiri dan kanan
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Gabungkan bagian-bagian yang telah diurutkan
        merge(arr, l, m, r);
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {6, 4, 16, 10, 3, 25};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum diurutkan: \n");
    printArray(arr, arr_size);

    // Panggil fungsi Merge Sort
    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray setelah diurutkan: \n");
    printArray(arr, arr_size);
    return 0;
}

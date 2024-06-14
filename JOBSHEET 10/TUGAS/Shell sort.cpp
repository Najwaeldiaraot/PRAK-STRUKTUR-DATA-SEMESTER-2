//Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>

// Fungsi untuk melakukan pengurutan dengan Shell Sort
void shellSort(int arr[], int n) {
    // Mulai dengan jarak yang besar, kemudian kurangi jaraknya
    for (int jarak = n / 2; jarak > 0; jarak /= 2) {
        // Lakukan pengurutan insertion sort untuk elemen-elemen dengan jarak yang diberikan
        for (int i = jarak; i < n; i++) {
            int elemen = arr[i];
            int j;
            for (j = i; j >= jarak && arr[j - jarak] > elemen; j -= jarak) {
                arr[j] = arr[j - jarak];
            }
            arr[j] = elemen;
        }
    }
}

// Fungsi untuk mencetak array
void cetakArray(int arr[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {30, 24, 73, 69, 11};
    int ukuran = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum diurutkan: \n");
    cetakArray(arr, ukuran);

    shellSort(arr, ukuran);

    printf("Array setelah diurutkan: \n");
    cetakArray(arr, ukuran);

    return 0;
}

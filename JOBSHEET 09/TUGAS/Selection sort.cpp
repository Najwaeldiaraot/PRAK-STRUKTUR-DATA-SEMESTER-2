//Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>

#define MAX_SIZE 100

// Fungsi untuk menukar nilai dua variabel
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi selection sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(&arr[i], &arr[min_index]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Masukkan jumlah elemen array: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Ukuran array tidak valid.\n");
        return 1;
    }

    printf("Masukkan %d elemen array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array sebelum diurutkan: ");
    printArray(arr, size);

    // Panggil fungsi selection sort
    selectionSort(arr, size);

    printf("Array setelah diurutkan: ");
    printArray(arr, size);

    return 0;
}

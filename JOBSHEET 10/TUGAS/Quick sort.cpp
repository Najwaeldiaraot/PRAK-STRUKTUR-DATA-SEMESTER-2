//Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>

// Fungsi untuk menukar dua elemen
void tukar(int *a, int *b) {
    int sementara = *a;
    *a = *b;
    *b = sementara;
}

// Fungsi untuk menemukan indeks pivot dan mengatur ulang array
int partisi(int array[], int rendah, int tinggi) {
    int pivot = array[tinggi];
    int i = (rendah - 1);

    for (int j = rendah; j < tinggi; j++) {
        if (array[j] <= pivot) {
            i++;
            tukar(&array[i], &array[j]);
        }
    }
    tukar(&array[i + 1], &array[tinggi]);
    return (i + 1);
}

// Fungsi utama Quick Sort
void quickSort(int array[], int rendah, int tinggi) {
    if (rendah < tinggi) {
        int pi = partisi(array, rendah, tinggi);

        quickSort(array, rendah, pi - 1);
        quickSort(array, pi + 1, tinggi);
    }
}

// Fungsi untuk mencetak array
void cetakArray(int array[], int ukuran) {
    for (int i = 0; i < ukuran; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int ukuran;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &ukuran);

    int array[ukuran];

    printf("Masukkan %d elemen:\n", ukuran);
    for (int i = 0; i < ukuran; i++) {
        scanf("%d", &array[i]);
    }

    printf("Array sebelum diurutkan: \n");
    cetakArray(array, ukuran);

    quickSort(array, 0, ukuran - 1);

    printf("Array setelah diurutkan: \n");
    cetakArray(array, ukuran);

    return 0;
}

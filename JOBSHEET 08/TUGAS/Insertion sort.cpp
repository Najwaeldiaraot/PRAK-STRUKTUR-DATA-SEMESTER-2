// Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>
#include <string.h>

#define MAX_KONTAK 100

// Struktur data untuk menyimpan kontak
struct Kontak {
    char nama[50];
    char nomor[15];
};

// Fungsi untuk menampilkan daftar kontak
void tampilkanKontak(struct Kontak kontak[], int n) {
    printf("Daftar Kontak:\n");
    for (int i = 0; i < n; i++) {
        printf("Nama: %s\t Nomor: %s\n", kontak[i].nama, kontak[i].nomor);
    }
}

// Fungsi insertion sort untuk mengurutkan daftar kontak berdasarkan nama
void insertionSort(struct Kontak kontak[], int n) {
    int i, j;
    struct Kontak key;
    for (i = 1; i < n; i++) {
        key = kontak[i];
        j = i - 1;

        // Pindahkan elemen dari kontak[0..i-1] yang lebih besar dari key ke posisi satu lebih tinggi dari posisi saat ini
        while (j >= 0 && strcmp(kontak[j].nama, key.nama) > 0) {
            kontak[j + 1] = kontak[j];
            j = j - 1;
        }
        kontak[j + 1] = key;
    }
}

int main() {
    struct Kontak daftarKontak[MAX_KONTAK];
    int jumlahKontak;

    printf("Masukkan jumlah kontak: ");
    scanf("%d", &jumlahKontak);

    // Membaca data kontak dari pengguna
    for (int i = 0; i < jumlahKontak; i++) {
        printf("Masukkan nama kontak ke-%d: ", i + 1);
        scanf(" %[^\n]s", daftarKontak[i].nama);
        printf("Masukkan nomor kontak ke-%d: ", i + 1);
        scanf("%s", daftarKontak[i].nomor);
    }

    // Menampilkan daftar kontak sebelum diurutkan
    printf("Daftar Kontak sebelum diurutkan:\n");
    tampilkanKontak(daftarKontak, jumlahKontak);

    // Mengurutkan daftar kontak menggunakan insertion sort
    insertionSort(daftarKontak, jumlahKontak);

    // Menampilkan daftar kontak setelah diurutkan
    printf("\nDaftar Kontak setelah diurutkan:\n");
    tampilkanKontak(daftarKontak, jumlahKontak);

    return 0;
}

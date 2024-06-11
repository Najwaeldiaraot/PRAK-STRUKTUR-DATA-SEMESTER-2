//Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>
#include <stdlib.h>

#define MAKSIMUM_SIMPUL 100

typedef struct Graf {
    int jumlahSimpul;
    int matriksKetetanggaan[MAKSIMUM_SIMPUL][MAKSIMUM_SIMPUL];
    int sudahDikunjungi[MAKSIMUM_SIMPUL];
} Graf;

typedef struct Antrian {
    int item[MAKSIMUM_SIMPUL];
    int depan;
    int belakang;
} Antrian;

Antrian* buatAntrian() {
    Antrian* antrian = (Antrian*)malloc(sizeof(Antrian));
    antrian->depan = -1;
    antrian->belakang = -1;
    return antrian;
}

int kosong(Antrian* antrian) {
    return antrian->belakang == -1;
}

void masukkan(Antrian* antrian, int nilai) {
    if (antrian->belakang == MAKSIMUM_SIMPUL - 1) {
        printf("\nAntrian penuh!!");
        return;
    }
    if (antrian->depan == -1) {
        antrian->depan = 0;
    }
    antrian->belakang++;
    antrian->item[antrian->belakang] = nilai;
}

int keluarkan(Antrian* antrian) {
    if (kosong(antrian)) {
        printf("\nAntrian kosong!!");
        return -1;
    }
    int item = antrian->item[antrian->depan];
    antrian->depan++;
    if (antrian->depan > antrian->belakang) {
        antrian->depan = antrian->belakang = -1;
    }
    return item;
}

Graf* buatGraf(int simpul) {
    Graf* graf = (Graf*)malloc(sizeof(Graf));
    graf->jumlahSimpul = simpul;
    for (int i = 0; i < simpul; i++) {
        for (int j = 0; j < simpul; j++) {
            graf->matriksKetetanggaan[i][j] = 0;
        }
        graf->sudahDikunjungi[i] = 0;
    }
    return graf;
}

void tambahSisi(Graf* graf, int src, int dest) {
    graf->matriksKetetanggaan[src][dest] = 1;
    graf->matriksKetetanggaan[dest][src] = 1;
}

void bfs(Graf* graf, int simpulAwal) {
    Antrian* antrian = buatAntrian();

    graf->sudahDikunjungi[simpulAwal] = 1;
    masukkan(antrian, simpulAwal);

    while (!kosong(antrian)) {
        int simpulSekarang = keluarkan(antrian);
        printf("%d ", simpulSekarang);

        for (int i = 0; i < graf->jumlahSimpul; i++) {
            if (graf->matriksKetetanggaan[simpulSekarang][i] == 1 && !graf->sudahDikunjungi[i]) {
                graf->sudahDikunjungi[i] = 1;
                masukkan(antrian, i);
            }
        }
    }
}

void temukanKomponenTerhubung(Graf* graf) {
    printf("Komponen terhubung:\n");
    for (int i = 0; i < graf->jumlahSimpul; i++) {
        if (!graf->sudahDikunjungi[i]) {
            bfs(graf, i);
        }
    }
}

int main() {
    int jumlahSimpul;
    printf("Masukkan jumlah simpul: ");
    scanf("%d", &jumlahSimpul);

    Graf* graf = buatGraf(jumlahSimpul);

    int jumlahSisi;
    printf("Masukkan jumlah sisi: ");
    scanf("%d", &jumlahSisi);

    printf("Masukkan sisi-sisi:\n");
    for (int i = 0; i < jumlahSisi; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        tambahSisi(graf, src, dest);
    }

    temukanKomponenTerhubung(graf);

    return 0;
}

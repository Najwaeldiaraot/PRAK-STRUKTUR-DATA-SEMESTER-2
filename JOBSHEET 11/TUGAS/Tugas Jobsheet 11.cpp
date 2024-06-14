//Created by 23343079_Najwa Eldiara Owilia Tiksa
#include <stdio.h>
#include <string.h>

// Struktur untuk menyimpan data mahasiswa
typedef struct {
    int NIM;
    char Nama[50];
    char TTL[50];
    float IPK;
} Mahasiswa;

// Fungsi untuk mencetak data mahasiswa
void cetakMahasiswa(Mahasiswa m) {
    printf("NIM: %d\n", m.NIM);
    printf("Nama: %s\n", m.Nama);
    printf("TTL: %s\n", m.TTL);
    printf("IPK: %.2f\n", m.IPK);
}

// Fungsi sequential search
int sequentialSearch(Mahasiswa mhs[], int ukuran, int kunci) {
    for (int i = 0; i < ukuran; i++) {
        if (mhs[i].NIM == kunci) {
            return i;
        }
    }
    return -1;
}

// Fungsi binary search (array harus terurut berdasarkan NIM)
int binarySearch(Mahasiswa mhs[], int ukuran, int kunci) {
    int kiri = 0, kanan = ukuran - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (mhs[tengah].NIM == kunci) {
            return tengah;
        } else if (mhs[tengah].NIM < kunci) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

// Fungsi untuk mengurutkan array mahasiswa berdasarkan NIM menggunakan bubble sort
void urutkanMahasiswa(Mahasiswa mhs[], int ukuran) {
    for (int i = 0; i < ukuran - 1; i++) {
        for (int j = 0; j < ukuran - i - 1; j++) {
            if (mhs[j].NIM > mhs[j + 1].NIM) {
                Mahasiswa temp = mhs[j];
                mhs[j] = mhs[j + 1];
                mhs[j + 1] = temp;
            }
        }
    }
}

int main() {
    int ukuran;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &ukuran);
    getchar();  // Mengkonsumsi newline character

    Mahasiswa mhs[ukuran];

    for (int i = 0; i < ukuran; i++) {
        printf("Masukkan data mahasiswa ke-%d:\n", i + 1);
        printf("NIM: ");
        scanf("%d", &mhs[i].NIM);
        getchar();  // Mengkonsumsi newline character
        printf("Nama: ");
        fgets(mhs[i].Nama, sizeof(mhs[i].Nama), stdin);
        mhs[i].Nama[strcspn(mhs[i].Nama, "\n")] = '\0'; // Menghilangkan newline di akhir input
        printf("TTL: ");
        fgets(mhs[i].TTL, sizeof(mhs[i].TTL), stdin);
        mhs[i].TTL[strcspn(mhs[i].TTL, "\n")] = '\0'; // Menghilangkan newline di akhir input
        printf("IPK: ");
        scanf("%f", &mhs[i].IPK);
        getchar();  // Mengkonsumsi newline character
    }

    printf("\nData mahasiswa:\n");
    for (int i = 0; i < ukuran; i++) {
        cetakMahasiswa(mhs[i]);
        printf("\n");
    }

    // Pencarian data
    int kunci;
    printf("Masukkan NIM untuk pencarian: ");
    scanf("%d", &kunci);

    // Sequential Search
    int indeksSeq = sequentialSearch(mhs, ukuran, kunci);
    if (indeksSeq != -1) {
        printf("\nHasil pencarian (Sequential Search):\n");
        cetakMahasiswa(mhs[indeksSeq]);
    } else {
        printf("\nMahasiswa dengan NIM %d tidak ditemukan (Sequential Search).\n", kunci);
    }

    // Mengurutkan data mahasiswa berdasarkan NIM untuk Binary Search
    urutkanMahasiswa(mhs, ukuran);

    // Binary Search
    int indeksBin = binarySearch(mhs, ukuran, kunci);
    if (indeksBin != -1) {
        printf("\nHasil pencarian (Binary Search):\n");
        cetakMahasiswa(mhs[indeksBin]);
    } else {
        printf("\nMahasiswa dengan NIM %d tidak ditemukan (Binary Search).\n", kunci);
    }

    return 0;
}

//Created by 23343079_Najwa Eldiara Owilia Tiksa

#include <stdio.h>

// Definisi struct untuk tipe data mahasiswa
struct Mahasiswa {
    char NIM[20];
    char Nama[50];
    char TanggalLahir[20];
    float IPK;
};

// Fungsi untuk input data mahasiswa
void inputDataMahasiswa(struct Mahasiswa *mahasiswa) {
    printf("Masukkan NIM: ");
    scanf("%s", mahasiswa->NIM);
    
    printf("Masukkan Nama: ");
    scanf("%s", mahasiswa->Nama);
    
    printf("Masukkan Tanggal Lahir (format: dd-mm-yyyy): ");
    scanf("%s", mahasiswa->TanggalLahir);
    
    printf("Masukkan IPK: ");
    scanf("%f", &mahasiswa->IPK);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(struct Mahasiswa mahasiswa) {
    printf("\nData Mahasiswa:\n");
    printf("NIM: %s\n", mahasiswa.NIM);
    printf("Nama: %s\n", mahasiswa.Nama);
    printf("Tanggal Lahir: %s\n", mahasiswa.TanggalLahir);
    printf("IPK: %.2f\n", mahasiswa.IPK);
}

int main() {
    // Deklarasi variabel bertipe struct Mahasiswa
    struct Mahasiswa mhs;

    // Memanggil fungsi untuk input data mahasiswa
    inputDataMahasiswa(&mhs);

    // Memanggil fungsi untuk menampilkan data mahasiswa
    tampilkanDataMahasiswa(mhs);

    return 0;
}

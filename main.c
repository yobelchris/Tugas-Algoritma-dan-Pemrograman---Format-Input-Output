#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define JUMLAH_BARANG 5

int main() {
    char nama[50];
    char barang[JUMLAH_BARANG][20] = {"CPU","Monitor","Keyboard","Mouse","Printer"};
    int harga[JUMLAH_BARANG] = {2000000,2400000,200000,150000,850000};
    printf("\t\t\tToko ABC\n");
    printf("Masukkan nama anda : ");
    scanf("%[^\n]s",nama);

    int c;
    while((c = getchar()) != '\n' && c != EOF){}

    printf("\n");

    printf("Hai %s\n",nama);
    printf("Berikut list barang kami : \n");

    for (int i = 0; i < JUMLAH_BARANG; ++i) {
        printf("%d. %s\t\t: Rp %d,00\n",i+1,barang[i],harga[i]);
    }

    printf("\nSilahkan masukkan pesanan anda\n\n");

    int done = 0;

    int i = 0;
    long barangBeli[JUMLAH_BARANG];
    long jumlahBeli[JUMLAH_BARANG];

    for (int l = 0; l < JUMLAH_BARANG; ++l) {
        barangBeli[l] = -1;
        jumlahBeli[l] = -1;
    }

    do{
        printf("=========================\n");
        printf("Masukkan nomor barang (masukkan lagi nomor barang yang sudah diisi sebelulmnya jika ingin mengganti jumlah sebelumnya): ");
        char nomorBarangChar[2];
        long nomorBarang;
        scanf("%[^\n]",nomorBarangChar);

        while((c = getchar()) != '\n' && c != EOF){}

        nomorBarang = strtol(nomorBarangChar,NULL,10);

        if (nomorBarang == LONG_MAX || nomorBarang == LONG_MIN) {
            perror("Error input nomor barang");
            continue;
        } else if (!nomorBarang) {
            printf("Nomor barang tidak ada\n");
            continue;
        }

        if (nomorBarang < 0 || nomorBarang > JUMLAH_BARANG) {
            printf("Nomor barang tidak ada\n");
            continue;
        }

        int alreadyInsertedIndex = -1;

        for (int j = 0; j < JUMLAH_BARANG; ++j) {
            if(barangBeli[j] == nomorBarang - 1) {
                alreadyInsertedIndex = j;
            }
        }

        if(alreadyInsertedIndex < 0){
            barangBeli[i] = nomorBarang - 1;
        }

        long jumlah;
        char jumlahChar[8];
        printf("Masukkan jumlah barang : ");
        scanf("%[^\n]",jumlahChar);

        while((c = getchar()) != '\n' && c != EOF){}

        jumlah = strtol(jumlahChar,NULL,10);

        if (jumlah == LONG_MAX || jumlah == LONG_MIN) {
            perror("Error input jumlah");
            continue;
        } else if (!jumlah) {
            printf("jumlah harus angka dan harus lebih dari nol\n");
            continue;
        }

        if(alreadyInsertedIndex >= 0) {
            jumlahBeli[alreadyInsertedIndex] = jumlah;
        } else {
            jumlahBeli[i] = jumlah;
        }

        printf("\nBarang di keranjang : \n");
        for (int k = 0; k < JUMLAH_BARANG; ++k) {
            if (barangBeli[k] >= 0) {
                printf("%s \t\t: %ld = Rp %ld,00\n",barang[barangBeli[k]],jumlahBeli[k],harga[barangBeli[k]]*jumlahBeli[k]);
            }
        }

        if(alreadyInsertedIndex < 0) {
            i++;
        }

        char selesai[2];
        printf("\nIngin menambah barang ?[y/n]");
        scanf("%c",selesai);

        while((c = getchar()) != '\n' && c != EOF){}

        if(selesai[0] != 'y' && selesai[0] != 'Y') {
            done = 1;
        }

        printf("=========================\n");

    } while (!done);

    printf("\n===============================\n");
    printf("RINCIAN PEMBELIAN\n");
    printf("===============================\n");
    printf("Nama pelanggan\t\t: %s\n\n",nama);
    long totalHarga = 0;

    for (int k = 0; k < JUMLAH_BARANG; ++k) {
        if (barangBeli[k] >= 0) {
            printf("%s \t\t\t\t: %ld = Rp %ld,00\n",barang[barangBeli[k]],jumlahBeli[k],harga[barangBeli[k]]*jumlahBeli[k]);
            totalHarga += harga[barangBeli[k]] * jumlahBeli[k];
        }
    }

    printf("===============================\n");
    printf("Total Harga\t\t\t: Rp. %ld,00\n",totalHarga);
    printf("===============================\n");

    getchar();
    return 0;
}
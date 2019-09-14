#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define JUMLAH_BARANG 5

int main() {
    char nama[50];
    char barang[JUMLAH_BARANG][20] = {"CPU","Monitor","Keyboard","Mouse","Printer"};
    int harga[JUMLAH_BARANG] = {2000000,2400000,200000,150000,850000};
    printf("\t\t\tSelamat Datang di Toko ABC\n");
    printf("\t\t\t==========================\n");
    printf("Masukkan nama anda : ");
    scanf("%[^\n]s",nama);

    int c;
    while((c = getchar()) != '\n' && c != EOF){}

    printf("\n");

    printf("Hai %s\n",nama);
    printf("Daftar Pemesanan [0 jika tidak ingin memesan] : \n");

    long jumlahBeli[JUMLAH_BARANG];
    for (int i = 0; i < JUMLAH_BARANG; ++i) {
        printf("%d. %s\t\t: Rp %d,00\t\t: ",i+1,barang[i],harga[i]);
        long jumlah;
        char jumlahChar[8];
        scanf("%[^\n]",jumlahChar);

        while((c = getchar()) != '\n' && c != EOF){}

        jumlah = strtol(jumlahChar,NULL,10);

        if (jumlah == LONG_MAX || jumlah == LONG_MIN) {
            perror("Error input jumlah");
            return 0;
        }

        jumlahBeli[i] = jumlah;
    }

    printf("\n");
    printf("Rincian Pembelian :\n");
    long totalHarga = 0;

    for (int k = 0; k < JUMLAH_BARANG; ++k) {
        if (jumlahBeli[k] > 0) {
            printf("%s \t\t: %ld = Rp %ld,00\n",barang[k],jumlahBeli[k],harga[k]*jumlahBeli[k]);
            totalHarga += harga[k] * jumlahBeli[k];
        }
    }

    printf("\nTotal Harga\t: Rp. %ld,00\n",totalHarga);

    getchar();
    return 0;
}
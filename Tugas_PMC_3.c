#include <stdio.h>
#include <stdlib.h>                         // untuk exit

/*
Nama : Surya Dharma
NIM  : 13220027
*/

void main()
{
    /* Kamus */
    FILE *myfile;
    int len;
    int elemen_sama_pdf = 0, elemen_sama_jpg = 0;
    char FILE_NAME[] = {};
    char hex_file[8];
    char hex_pdf[8] = "25504446";
    char hex_jpg[4] = "ffd8";

    /* Algoritma */
    printf("=== Program menentukan ekstensi file (pdf/jpg/tidak keduanya) ===\n\n");
    printf("Nama file : ");
    scanf("%s", &FILE_NAME);
    myfile = fopen(FILE_NAME, "rb");       // mode rb untuk non-text file, mode r untuk text file
    if (myfile == NULL){
        printf("File tidak ada");
        exit(1);
    }

    /* Menghitung panjang magic file signature dari myfile */
    fseek(myfile, 0, SEEK_END);
    len = ftell(myfile);

    /* Set pointer di posisi paling awal */
    fseek(myfile, 0, SEEK_SET);

    unsigned char arr[len + 1];

    /* Membaca file signature myfile lalu memasukkan ke arr */
    fread(arr, 1, 4, myfile);

    sprintf(arr, "%02hhx%02hhx%02hhx%02hhx", arr[0], arr[1], arr[2], arr[3]);
    sprintf(hex_file, "%s", arr);
    for (int i = 0; i < 10; i++){
        if (hex_file[i] == hex_pdf[i]){
            elemen_sama_pdf += 1;
        }
        else if (hex_file[i] == hex_jpg[i] && i <= 3){
            elemen_sama_jpg += 1;
        }
    }

    if (elemen_sama_pdf == 8){
        printf("Ekstensi file ini adalah pdf");
    }
    else if (elemen_sama_jpg == 4){
        printf("Ekstensi file ini adalah jpg");
    }
    else {
        printf("Ekstensi file ini tidak terdefinisi (bukan pdf atau jpg)");
    }
}

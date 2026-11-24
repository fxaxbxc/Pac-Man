#include <ncurses.h>

// Mengatur konfigurasi permainan
const int LEBAR = 31;
const int TINGGI = 21;
const int JUMLAH_HANTU = 4;

// Menyimpan isi labirin
char labirin[TINGGI][LEBAR];

// Menyimpan posisi Pac-Man
int pemainX, pemainY;

// Menyimpan posisi empat hantu
int hantuX[JUMLAH_HANTU];
int hantuY[JUMLAH_HANTU];

// Menyimpan informasi permainan
int skor = 0;
int nyawa = 3;
int sisaTitik = 0;
int statusPermainan = 0;

bool mulutTerbuka = true;

// Mengatur warna setiap hantu
int warnaHantu[JUMLAH_HANTU] = {
    3, 4, 5, 7
};

// Menentukan simbol setiap hantu
char simbolHantu[JUMLAH_HANTU] = {
    'R', 'P', 'B', 'O'
};

// Menentukan posisi awal Pac-Man dan empat hantu
void resetPositions() {

    // Posisi Pac-Man
    pemainX = 1;
    pemainY = 1;

    // Posisi empat hantu
    hantuX[0] = 13;
    hantuY[0] = 9;

    hantuX[1] = 14;
    hantuY[1] = 9;

    hantuX[2] = 16;
    hantuY[2] = 9;

    hantuX[3] = 17;
    hantuY[3] = 9;
}
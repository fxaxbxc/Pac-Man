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
// Mengatur warna yang digunakan dalam permainan
void initializeColors() {

    if (!has_colors()) return;

    start_color();
    use_default_colors();

    init_pair(1, COLOR_BLUE, -1);
    init_pair(2, COLOR_YELLOW, -1);
    init_pair(3, COLOR_RED, -1);
    init_pair(4, COLOR_MAGENTA, -1);
    init_pair(5, COLOR_CYAN, -1);
    init_pair(6, COLOR_WHITE, -1);
    init_pair(7, COLOR_GREEN, -1);
}

// Membuat dan mengatur labirin
void initializeMap() {

    // Mengisi labirin dengan titik
    for (int baris = 0; baris < TINGGI; baris++) {

        for (int kolom = 0; kolom < LEBAR; kolom++) {

            labirin[baris][kolom] = '.';
        }
    }

    // Membuat dinding luar horizontal
    for (int kolom = 0; kolom < LEBAR; kolom++) {

        labirin[0][kolom] = '#';
        labirin[TINGGI - 1][kolom] = '#';
    }

    // Membuat dinding luar vertikal
    for (int baris = 0; baris < TINGGI; baris++) {

        labirin[baris][0] = '#';
        labirin[baris][LEBAR - 1] = '#';
    }

    // Membuat dinding horizontal
    for (int kolom = 3; kolom <= 27; kolom++) {

        if (kolom != 7 && kolom != 15 && kolom != 23) {

            labirin[5][kolom] = '#';
            labirin[10][kolom] = '#';
            labirin[15][kolom] = '#';
        }
    }

    // Membuat dinding vertikal
    for (int baris = 2; baris <= 18; baris++) {

        if (baris != 3 && baris != 8 &&
            baris != 13 && baris != 17) {

            labirin[baris][8] = '#';
            labirin[baris][22] = '#';
        }
    }

    // Mengatur posisi awal pemain dan hantu
    resetPositions();

    // Membuka area awal pemain
    labirin[pemainY][pemainX] = ' ';

    // Membuka area awal hantu
    for (int indeks = 0; indeks < JUMLAH_HANTU; indeks++) {

        labirin[hantuY[indeks]][hantuX[indeks]] = ' ';
    }

    // Menghitung jumlah titik yang tersisa
    sisaTitik = 0;

    for (int baris = 0; baris < TINGGI; baris++) {

        for (int kolom = 0; kolom < LEBAR; kolom++) {

            if (labirin[baris][kolom] == '.') {
                sisaTitik++;
            }
        }
    }
}
// Mengatur ulang kondisi permainan
void resetGame() {

    initializeMap();

    skor = 0;
    nyawa = 3;

    mulutTerbuka = true;

    statusPermainan = 1;
}

// Memeriksa apakah posisi merupakan dinding
bool isWall(int posisiX, int posisiY) {

    if (posisiX < 0 || posisiX >= LEBAR ||
        posisiY < 0 || posisiY >= TINGGI) {

        return true;
    }

    return labirin[posisiY][posisiX] == '#';
}

// Menampilkan judul permainan
void drawTitle() {

    attron(COLOR_PAIR(2) | A_BOLD);

    mvprintw(2, 13, "======================");
    mvprintw(3, 13, "       PAC-MAN        ");
    mvprintw(4, 13, "======================");

    attroff(COLOR_PAIR(2) | A_BOLD);
}

// Menampilkan menu utama
void drawMenu() {

    clear();

    drawTitle();

    attron(A_BOLD);

    mvprintw(7, 20, "MAIN MENU");

    attroff(A_BOLD);

    mvprintw(10, 17, "[1] START GAME");
    mvprintw(12, 17, "[2] LEADERBOARD");
    mvprintw(14, 17, "[3] SEARCH PLAYER");
    mvprintw(16, 17, "[4] INSTRUCTIONS");
    mvprintw(18, 17, "[5] EXIT");

    attron(COLOR_PAIR(2));

    mvprintw(
        22, 7,
        "Collect dots, avoid ghosts, and get the highest score!"
    );

    attroff(COLOR_PAIR(2));

    refresh();
}

// Menggambar labirin
void drawMap() {

    for (int baris = 0; baris < TINGGI; baris++) {

        for (int kolom = 0; kolom < LEBAR; kolom++) {

            int layarX = kolom + 2;
            int layarY = baris + 3;

            if (labirin[baris][kolom] == '#') {

                attron(COLOR_PAIR(1) | A_BOLD);

                mvaddch(
                    layarY,
                    layarX,
                    ACS_CKBOARD
                );

                attroff(COLOR_PAIR(1) | A_BOLD);
            }

            else if (labirin[baris][kolom] == '.') {

                attron(COLOR_PAIR(6));

                mvaddch(
                    layarY,
                    layarX,
                    ACS_BULLET
                );

                attroff(COLOR_PAIR(6));
            }

            else {

                mvaddch(layarY, layarX, ' ');
            }
        }
    }
}

// Menggambar Pac-Man
void drawPlayer() {

    attron(COLOR_PAIR(2) | A_BOLD);

    char simbol = mulutTerbuka ? 'C' : 'O';

    mvaddch(
        pemainY + 3,
        pemainX + 2,
        simbol
    );

    attroff(COLOR_PAIR(2) | A_BOLD);
}

// Menggambar empat hantu
void drawGhosts() {

    for (int indeks = 0; indeks < JUMLAH_HANTU; indeks++) {

        attron(
            COLOR_PAIR(warnaHantu[indeks]) | A_BOLD
        );

        mvaddch(
            hantuY[indeks] + 3,
            hantuX[indeks] + 2,
            simbolHantu[indeks]
        );

        attroff(
            COLOR_PAIR(warnaHantu[indeks]) | A_BOLD
        );
    }
}

// Menampilkan informasi permainan
void drawHUD() {

    attron(COLOR_PAIR(2) | A_BOLD);

    mvprintw(0, 2, "PAC-MAN");

    attroff(COLOR_PAIR(2) | A_BOLD);

    attron(COLOR_PAIR(6));

    mvprintw(0, 13, "SCORE: %06d", skor);
    mvprintw(0, 29, "LIVES: %d", nyawa);
    mvprintw(1, 13, "DOTS: %d", sisaTitik);

    attroff(COLOR_PAIR(6));
}

// Menggabungkan seluruh tampilan permainan
void drawGame() {

    clear();

    drawHUD();

    drawMap();

    drawPlayer();

    drawGhosts();

    mvprintw(26, 2, "WASD / ARROWS: MOVE");
    mvprintw(27, 2, "Q: BACK TO MENU");

    refresh();
}
#include <ncurses.h>

int main() {
    initscr();                 // Mulai mode ncurses.
    cbreak();                  // Baca tombol tanpa menunggu Enter.
    noecho();                  // Jangan tampilkan tombol yang ditekan.
    keypad(stdscr, TRUE);      // Aktifkan tombol panah.

    mvprintw(1, 2, "Contoh ncurses berjalan di WSL");
    mvprintw(3, 2, "Tekan tombol panah atau q untuk keluar.");
    refresh();

    int key;
    do {
        key = getch();
    } while (key != 'q' && key != 'Q');

    endwin();                  // Pulihkan tampilan terminal.
    return 0;

    cout << "tes!" << endl;
}

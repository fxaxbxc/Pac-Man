# 👾 Pac-Man — Maze Adventure

> 🎮 **Final Project Pemrograman C++**
>
> Game Pac-Man berbasis terminal menggunakan C++ dan Ncurses. Kumpulkan seluruh titik, hindari empat hantu, dan selesaikan labirin sebelum kehabisan nyawa!

---

## 🗺️ Tentang Game

Pac-Man merupakan game klasik yang dikembangkan menggunakan bahasa pemrograman C++ dengan library Ncurses.

Pemain mengendalikan Pac-Man untuk menjelajahi labirin, mengumpulkan titik, dan menghindari empat hantu yang bergerak mendekati posisi pemain.

Proyek ini menerapkan konsep pemrograman prosedural, pengelolaan alur permainan, deteksi tabrakan, serta pengolahan data menggunakan file eksternal.

---

## ✨ Fitur Permainan

| Fitur | Deskripsi |
|---|---|
| 🏰 Maze Exploration | Labirin berukuran 31 × 21 dengan dinding dan titik yang dapat dikumpulkan. |
| 👾 Ghost Enemies | Empat hantu dengan simbol dan warna berbeda. |
| 🧠 Ghost Movement | Hantu bergerak mendekati Pac-Man menggunakan perhitungan jarak Manhattan. |
| 🍒 Collectible Dots | Setiap titik yang dikumpulkan memberikan 10 poin. |
| ❤️ Life System | Pemain memiliki tiga nyawa. |
| 🏆 Win & Game Over | Permainan berakhir ketika seluruh titik habis atau nyawa pemain mencapai nol. |
| 📊 Leaderboard | Menampilkan hingga 10 pemain dengan skor tertinggi. |
| 🔎 Player Search | Mencari pemain berdasarkan nama menggunakan Linear Search. |
| 💾 Score Saving | Menyimpan nama dan skor pemain ke file `score.txt`. |
| 🎨 Colorful Interface | Tampilan terminal menggunakan warna Ncurses. |

---

## 🧩 Struktur Repository

Berikut struktur file proyek Pac-Man:

```text
📦 Pac-Man
 ┣ 📜 .gitignore
 ┣ 📜 README.md
 ┣ 📜 main
 ┗ 📜 main.cpp
```

### 📌 Penjelasan File

| File       | Keterangan                                                       |
| ---------- | ---------------------------------------------------------------- |
| .gitignore | Mengatur file atau folder yang tidak perlu disertakan dalam Git. |
| README.md  | Dokumentasi proyek dan panduan penggunaan.                       |
| main.cpp   | Source code utama yang berisi seluruh fungsi permainan.          |
| main       | File hasil kompilasi program.                                    |

### 🛠️ Prasyarat

Sebelum menjalankan game, pastikan perangkat memiliki:

* Compiler C++ seperti G++.

* Library Ncurses.

* Terminal yang mendukung Ncurses.

* Sistem operasi Linux atau Windows melalui WSL.

### 📦 Instalasi pada Linux / WSL

Jalankan perintah berikut untuk memasang compiler dan library:

```bash
sudo apt update
sudo apt install g++ libncurses-dev
```

### 🚀 Cara Menjalankan Game

### 1\. Clone Repository

```bash
git clone <URL_REPOSITORY>
```

Masuk ke direktori proyek:

```bash
cd Pac-Man
```

### 2\. Kompilasi Program

```bash
g++ main.cpp -o main -lncurses
```

### 3\. Jalankan Game

```bash
./main
```

> 💡 Gunakan terminal dengan ukuran minimal 50 kolom × 29 baris agar tampilan permainan dapat ditampilkan dengan baik.

### ⌨️ Kontrol Permainan

| Tombol | Aksi                                            |
| ------ | ----------------------------------------------- |
| W / ↑  | Bergerak ke atas                                |
| S / ↓  | Bergerak ke bawah                               |
| A / ←  | Bergerak ke kiri                                |
| D / →  | Bergerak ke kanan                               |
| Q      | Kembali ke menu utama                           |
| 1 – 5  | Memilih menu utama                              |
| R      | Memulai ulang permainan setelah selesai         |
| M      | Kembali ke menu utama setelah permainan selesai |

### 🎯 Cara Bermain

* Pilih Start Game pada menu utama.

* Gerakkan Pac-Man menggunakan tombol WASD atau tombol panah.

* Kumpulkan seluruh titik yang terdapat di labirin.

* Hindari hantu agar nyawa tidak berkurang.

* Selesaikan labirin dan raih skor tertinggi!

### 💾 Sistem Skor & Penyimpanan

Game menggunakan file eksternal `score.txt` untuk menyimpan data skor pemain.

### Format Penyimpanan

```text
NamaPemain Skor
```

Contoh:

```text
Farid 240
Naura 230
Mitha 229
```

### Pengelolaan Skor

* Save Score: Menyimpan nama dan skor pemain setelah permainan selesai.

* Load Leaderboard: Membaca data skor dari file `score.txt`.

* Bubble Sort: Mengurutkan skor pemain dari tertinggi ke terendah.

* Linear Search: Mencari pemain berdasarkan nama.

* Leaderboard: Menampilkan maksimal 10 pemain dengan skor tertinggi.

> ℹ️ File `score.txt` dibuat ketika program menyimpan skor pertama kali. Jika file belum tersedia, leaderboard akan kosong.

### 🧠 Konsep Pemrograman

Program ini menggunakan pendekatan pemrograman prosedural dengan fungsi-fungsi yang memiliki tugas berbeda.

* Function: Memisahkan proses permainan menjadi fungsi-fungsi terstruktur.

* Array: Menyimpan posisi, simbol, dan warna hantu serta data leaderboard.

* Global Variables: Menyimpan kondisi permainan seperti skor, nyawa, dan posisi karakter.

* Conditional Statements: Mengatur kondisi pergerakan, tabrakan, kemenangan, dan kekalahan.

* Looping: Mengatur game loop dan pembaruan tampilan permainan.

* Linear Search: Mencari nama pemain dalam leaderboard.

* Bubble Sort: Mengurutkan skor pemain.

* File Handling: Membaca dan menyimpan data skor menggunakan file eksternal.

### 👥 Tim Pengembang

Universitas Lampung

| Nama             | NPM   |
| ---------------- | ----- |
| [Farid Hidayattulloh] | [2617051033] |
| [Naura Cindra Rahmadani] | [2617051045] |
| [Mitha Aprilia] | [261701009] |

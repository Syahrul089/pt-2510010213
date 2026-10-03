# P02 Tipe dan Input: Tipe Data, Variabel, Konstanta, dan Input Dasar

Folder kode Pertemuan 2 Pemrograman Terstruktur. Buka folder ini di Visual Studio Code
(File, Open Folder) supaya pengaturan di `.vscode` ikut terpakai.

## Isi

| Berkas | Kegunaan |
|---|---|
| `tipe_dasar.cpp` | Lima tipe yang dipakai sepanjang semester: int, double, char, bool, string. Mulai pertemuan ini semua kode kelas memakai `using namespace std;` |
| `konstanta.cpp` | Konstanta dengan `const`, memakai bobot penilaian mata kuliah ini. Ada satu baris untuk dicoba diubah |
| `input_dasar.cpp` | Membaca input dengan `cin`. Coba dengan nama satu kata lalu dua kata |
| `sinilai_v01_awal.cpp` | Starter SiNilai v0.1: lengkapi TODO sampai kartu data mahasiswa tampil benar |
| `contoh_masukan.txt` | Contoh masukan untuk mencoba SiNilai: `./sinilai_v01 < contoh_masukan.txt` |
| `.vscode/`, `.gitignore` | Sama dengan Pertemuan 1: Git Bash, Code Runner, Ctrl+Shift+B, hasil build tidak di-commit |

## Keluaran SiNilai v0.1 yang diharapkan

```
=== SiNilai v0.1 ===
Nama      : Muhammad Syahrul Mukmin
NPM       : 2510010213
Kehadiran : 100
Mingguan  : 90
UTS       : 85
UAS       : 90

--- Kartu Data Mahasiswa ---
Nama      : Muhammad Syahrul Mukmin
NPM       : 2510010213
Kehadiran : 100
Mingguan  : 90
UTS       : 85
UAS       : 90
```

## Yang dikumpulkan mahasiswa

Folder `p02` di repository `pt-NPM` berisi `sinilai_v01.cpp`, dan  `README.md`. Lihat Modul Pertemuan 2 bagian E.

## Deklarasi AI
Chat Gpt, Data input dapat diberikan melalui file contoh_masukan.txt, kemudian program menampilkan data tersebut dalam bentuk Kartu Data Mahasiswa., dan Input dari file contoh_masukan.txt dapat digunakan untuk mengisi data mahasiswa. Output program menampilkan Nama dan NPM pada bagian Kartu Data Mahasiswa.
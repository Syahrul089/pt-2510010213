#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int TARIF_AWAL_MOTOR = 2000;
    const int TARIF_LANJUT_MOTOR = 1000;
    const int MAKS_MOTOR = 10000;
    const int TARIF_AWAL_MOBIL = 5000;
    const int TARIF_LANJUT_MOBIL = 3000;
    const int MAKS_MOBIL = 30000;

    int jumlah = 0;

    cout << "=== Parkir Kampus ===\n";
    cout << "Jumlah kendaraan: ";
    cin >> jumlah;

    while (cin.fail() || jumlah < 1) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Jumlah kendaraan: ";
        cin >> jumlah;
    }

    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    int total = 0;
    int banyak_motor = 0;
    int banyak_mobil = 0;

    // TODO 5a: Menyiapkan biaya tertinggi
    int biaya_tertinggi = -1;
    string plat_tertinggi = "";

    for (int i = 1; i <= jumlah; i++) {
        string plat;
        char jenis = ' ';
        int durasi = 0;

        cout << "\n--- Kendaraan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1: Membaca dan memvalidasi plat nomor
        cout << "Plat nomor : ";
        getline(cin, plat);

        while (plat.find_first_not_of(" \t\r\n") == string::npos) {
            cout << "Plat tidak boleh kosong.\n";
            cout << "Plat nomor : ";
            getline(cin, plat);
        }

        for (char &huruf : plat) {
            huruf = static_cast<char>(
                toupper(static_cast<unsigned char>(huruf))
            );
        }

        // TODO 2: Membaca dan memvalidasi jenis kendaraan
        cout << "Jenis (M/R): ";
        cin >> jenis;

        jenis = static_cast<char>(
            toupper(static_cast<unsigned char>(jenis))
        );

        while (jenis != 'M' && jenis != 'R') {
            cin.ignore(1000, '\n');

            cout << "Hanya M (motor) atau R (roda empat). Jenis (M/R): ";
            cin >> jenis;

            jenis = static_cast<char>(
                toupper(static_cast<unsigned char>(jenis))
            );
        }

        cin.ignore(1000, '\n');

        // TODO 3: Membaca dan memvalidasi durasi parkir
        cout << "Durasi (jam, 1-24): ";
        cin >> durasi;

        while (cin.fail() || durasi < 1 || durasi > 24) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Harus bilangan bulat 1 sampai 24. Durasi (jam): ";
            cin >> durasi;
        }

        cin.ignore(1000, '\n');

        // TODO 4: Menghitung biaya parkir
        int biaya = 0;
        string nama_jenis;

        if (jenis == 'M') {
            nama_jenis = "Motor";

            biaya = TARIF_AWAL_MOTOR +
                    (durasi - 1) * TARIF_LANJUT_MOTOR;

            if (biaya > MAKS_MOTOR) {
                biaya = MAKS_MOTOR;
            }

            banyak_motor++;
        } else {
            nama_jenis = "Mobil";

            biaya = TARIF_AWAL_MOBIL +
                    (durasi - 1) * TARIF_LANJUT_MOBIL;

            if (biaya > MAKS_MOBIL) {
                biaya = MAKS_MOBIL;
            }

            banyak_mobil++;
        }

        cout << "  " << left << setw(12) << plat
             << setw(8) << nama_jenis
             << right << setw(4) << durasi
             << " jam" << setw(9) << biaya << "\n";

        total += biaya;

        // TODO 5b: Memperbarui biaya tertinggi
        if (biaya > biaya_tertinggi) {
            biaya_tertinggi = biaya;
            plat_tertinggi = plat;
        }
    }

    cout << "\n=== Rekap Hari Ini ===\n";
    cout << "Jumlah kendaraan : " << jumlah << "\n";
    cout << "Motor            : " << banyak_motor << "\n";
    cout << "Mobil            : " << banyak_mobil << "\n";
    cout << "Total pendapatan : " << total << "\n";
    cout << "Rata-rata biaya  : "
         << static_cast<double>(total) / jumlah << "\n";

    // TODO 5c: Menampilkan biaya tertinggi
    cout << "Tertinggi        : " << plat_tertinggi
         << " (" << biaya_tertinggi << ")\n";

    // TODO 6: Diagram batang sebaran jenis kendaraan
    string label[2] = {"Motor", "Mobil"};
    int jumlah_jenis[2] = {banyak_motor, banyak_mobil};

    cout << "\nSebaran jenis:\n";

    for (int i = 0; i < 2; i++) {
        cout << left << setw(6) << label[i] << "| ";

        for (int j = 0; j < jumlah_jenis[i]; j++) {
            cout << "#";
        }

        cout << " " << jumlah_jenis[i] << "\n";
    }

    return 0;
}
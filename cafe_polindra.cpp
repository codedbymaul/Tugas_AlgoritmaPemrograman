#include <iostream>
#include <string>
using namespace std;

// PROSEDUR menampilkan menu
void tampilkanMenu() {
    cout << "\n========== MENU CAFE ==========" << endl;
    cout << "1. Americano      : Rp15.000" << endl;
    cout << "2. Butterscotch   : Rp17.000" << endl;
    cout << "3. Vanilla Latte  : Rp15.000" << endl;
    cout << "4. Matcha         : Rp12.000" << endl;
    cout << "5. Kopi Gula Aren : Rp16.000" << endl;
}

// FUNGSI menentukan harga berdasarkan pilihan
int hitungHarga(int pilihan) {
    if (pilihan == 1) {
        return 15000;
    }
    else if (pilihan == 2) {
        return 17000;
    }
    else if (pilihan == 3) {
        return 15000;
    }
    else if (pilihan == 4) {
        return 12000;
    }
    else if (pilihan == 5) {
        return 16000;
    }
    else {
        return 0;
    }
}

// FUNGSI menghitung harga berdasarkan tingkat kemanisan
int hargaAkhir(int harga, char manis) {
    if (manis == 'y' || manis == 'Y') {
        return harga + 1000;
    }
    else {
        return harga - 1000;
    }
}

// PROSEDUR memproses pesanan
void prosesPesanan(int &totalBiaya) {
    int pilihan, harga;
    char manis;

    tampilkanMenu();

    cout << "Masukkan pilihan (1-5): ";
    cin >> pilihan;

    harga = hitungHarga(pilihan);

    if (harga == 0) {
        cout << "Pilihan tidak valid!" << endl;
        return;
    }

    cout << "Suka manis? (y/n): ";
    cin >> manis;

    totalBiaya += hargaAkhir(harga, manis);
}

// PROGRAM UTAMA
int main() {
    string hari;
    int totalBiaya = 0;
    char ulang;

    cout << "=================================" << endl;
    cout << "         CAFE POLINDRA" << endl;
    cout << "=================================" << endl;
    cout << "Input Hari: ";
    cin >> hari;

    do {
        prosesPesanan(totalBiaya);

        cout << "\nAPAKAH MAU BELI LAGI (Y/N): ";
        cin >> ulang;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "\n=================================" << endl;
    cout << "          STRUK CAFE" << endl;
    cout << "=================================" << endl;
    cout << "Hari         : " << hari << endl;
    cout << "Total Biaya  : Rp" << totalBiaya << endl;
    cout << "=================================" << endl;
    cout << "Terima kasih telah berkunjung!" << endl;

    return 0;
}
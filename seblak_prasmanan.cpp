#include <iostream>
#include <string>

using namespace std;

//prosedur 1 berfungsi untuk menampilkan daftar pilihan menu seblak beserta harganya ke layar setiap kali dipanggil di dalam perulangan do-while, tanpa mengembalikan nilai apa pun
void tampilkan_menu() {
    cout << "\n===== menu seblak prasmanan =====" << endl;
    cout << "1. sayur    = rp 2000" << endl;
    cout << "2. telor    = rp 3000" << endl;
    cout << "3. kerupuk  = rp 2000" << endl;
    cout << "4. seafood  = rp 3000" << endl;
    cout << "5. tulang   = rp 2000" << endl;
}

//fungsi 1 untuk mengecek dan mengembalikan harga sesuai pilihan menu

int cek_harga(int pilihan) {
    if (pilihan == 1 || pilihan == 3 || pilihan == 5) {
        return 2000;
    } 
    else if (pilihan == 2 || pilihan == 4) {
        return 3000;
    } 
    else {
        cout << "pilihan tidak valid!" << endl;
        return 0;
    }
}

//fungsi 2 (int) untuk mengecek pilihan tambah sambal (y/n) dan mengembalikan nilainya (1000 atau 0)
int hitung_sambel(char tambah) {
    if (tambah == 'y' || tambah == 'Y') {
        return 1000;
    }
    return 0;
}

//prosedur 2 untuk menghitung total akhir dan menampilkan struk pembayaran
void tampilkan_struk(string hari, int total_biaya, int biaya_sambel) {
    int total_akhir = total_biaya + biaya_sambel;

    cout << "\n========== struk pembayaran ==========" << endl;
    cout << "hari          = " << hari << endl;
    cout << "total biaya   = rp " << total_biaya << endl;

    if (biaya_sambel > 0) {
        cout << "tambah sambel = rp " << biaya_sambel << endl;
    }

    cout << "total bayar   = rp " << total_akhir << endl;
}

//program utama
int main() {
    int pilihan, total_biaya = 0, biaya_sambel = 0;
    char ulang, tambah_sambel;
    string hari;

    cout << "input hari = ";
    cin >> hari;

    do {
        tampilkan_menu();

        cout << "input pilihan = ";
        cin >> pilihan;

        total_biaya += cek_harga(pilihan);

        cout << "\napakah ada pesanan lain (y/n)? = ";
        cin >> ulang;
        cout << "--------------------------" << endl;

    } while (ulang == 'y' || ulang == 'Y');

    cout << "apakah nambah sambel? (y/n) = ";
    cin >> tambah_sambel;

    biaya_sambel = hitung_sambel(tambah_sambel);

    tampilkan_struk(hari, total_biaya, biaya_sambel);

    return 0;
}
#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// Maksimum jumlah tempat pariwisata yang dapat disimpan
const int MAX_TEMPAT = 100;

// Struktur untuk menyimpan informasi tempat pariwisata
struct TempatPariwisata {
    string nama;
    string deskripsi;
    string lokasi;
    string rating;
};

// Array untuk menyimpan data tempat pariwisata
TempatPariwisata tempat_pariwisata[MAX_TEMPAT];

// Jumlah tempat pariwisata yang telah disimpan
int jumlah_tempat = 0;

// Queue untuk menyimpan tempat pariwisata yang akan ditambahkan
queue<TempatPariwisata> tempat_queue;

// Stack untuk menyimpan daftar tempat pariwisata yang telah ditambahkan
stack<TempatPariwisata> tempat_stack;

// Fungsi untuk menambahkan tempat pariwisata baru
void tambahTempat() {
    if (jumlah_tempat < MAX_TEMPAT) {
        TempatPariwisata tempat;
        cout << "Masukkan informasi tempat pariwisata:" << endl;
        cout << "Nama Tempat: ";
        getline(cin >> ws, tempat.nama);
        cout << "Deskripsi Tempat: ";
        getline(cin, tempat.deskripsi);
        cout << "Lokasi: ";
        getline(cin, tempat.lokasi);
        cout << "Rating: ";
        getline(cin, tempat.rating);
        tempat_queue.push(tempat); // Tambahkan ke dalam queue
        jumlah_tempat++;
        cout << "Tempat pariwisata berhasil ditambahkan ke dalam antrian!" << endl;
    } else {
        cout << "Kapasitas maksimum tempat pariwisata telah tercapai." << endl;
    }
}

// Fungsi untuk mentransfer tempat pariwisata dari queue ke stack
void transferTempat() {
    while (!tempat_queue.empty()) {
        tempat_stack.push(tempat_queue.front());
        tempat_queue.pop();
    }
}

// Fungsi untuk mencari tempat pariwisata berdasarkan nama
void cariTempat(const string& nama) {
    bool ditemukan = false;
    transferTempat(); // Transfer tempat dari queue ke stack untuk pencarian
    while (!tempat_stack.empty()) {
        TempatPariwisata tempat = tempat_stack.top();
        if (tempat.nama == nama) {
            ditemukan = true;
            cout << "Nama Tempat: " << tempat.nama << endl;
            cout << "Deskripsi Tempat: " << tempat.deskripsi << endl;
            cout << "Lokasi: " << tempat.lokasi << endl;
            cout << "Rating: " << tempat.rating << endl << endl;
            break;
        }
        tempat_stack.pop();
    }
    if (!ditemukan) {
        cout << "Tempat pariwisata tidak ditemukan." << endl << endl;
    }
}

int main() {
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Tambah Tempat Pariwisata" << endl;
        cout << "2. Cari Tempat Pariwisata" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer stdin

        switch (pilihan) {
            case 1:
                tambahTempat();
                break;
            case 2: {
                cout << "Masukkan nama tempat pariwisata yang ingin dicari: ";
                string nama;
                getline(cin >> ws, nama);
                cariTempat(nama);
                break;
            }
            case 3:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                return 0;
            default:
                cout << "Menu tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }
}
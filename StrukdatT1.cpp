#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 13;

// Struktur menyimpan
struct Tugas {
    string nama;
    string mata_kuliah;
    string deadline;
};

// Deklarasi array menyimpan data tugas
Tugas data_tugas[MAX_TASKS];
int jumlah_tugas = 0;

// menampilkan semua data tugas
void tampilkan_data_tugas() {
    cout << "Data Tugas:" << endl;
    for (int i = 0; i < jumlah_tugas; i++) {
        cout << i + 1 << ": " << "Nama Tugas: " << data_tugas[i].nama << ", Mata Kuliah: " << data_tugas[i].mata_kuliah << ", Deadline: " << data_tugas[i].deadline << endl;
    }
}

// menambahkan tugas baru
void tambahkan_tugas() {
    if (jumlah_tugas < MAX_TASKS) {
        Tugas tugas_baru;
        cout << "Apa nama tugas baru: ";
        cin.ignore();
        getline(cin, tugas_baru.nama);
        cout << "Matkul apa: ";
        getline(cin, tugas_baru.mata_kuliah);
        cout << "Kapan deadline: ";
        getline(cin, tugas_baru.deadline);

        data_tugas[jumlah_tugas] = tugas_baru;
        jumlah_tugas++;
        cout << "Tugas berhasil ditambahkan." << endl;
    } else {
        cout << "Daftar tugas sudah penuh." << endl;
    }
}

// menghapus tugas berdasarkan nomor
void hapus_tugas() {
    if (jumlah_tugas > 0) {
        cout << "No berapa yang ingin dihapus: ";
        int nomor_tugas;
        cin >> nomor_tugas;

        if (nomor_tugas >= 1 && nomor_tugas <= jumlah_tugas) {
            for (int i = nomor_tugas - 1; i < jumlah_tugas - 1; i++) {
                data_tugas[i] = data_tugas[i + 1];
            }
            jumlah_tugas--;
            cout << "Tugas berhasil dihapus." << endl;
        } else {
            cout << "Nomor tugas tidak valid." << endl;
        }
    } else {
        cout << "Daftar tugas kosong." << endl;
    }
}

// mengubah tugas berdasarkan nomor
void ubah_tugas() {
    if (jumlah_tugas > 0) {
        cout << "No berapa yang ingin diubah: ";
        int nomor_tugas;
        cin >> nomor_tugas;

        if (nomor_tugas >= 1 && nomor_tugas <= jumlah_tugas) {
            cout << "Nama tugas baru: ";
            cin.ignore();
            getline(cin, data_tugas[nomor_tugas - 1].nama);
            cout << "Mata kuliah baru: ";
            getline(cin, data_tugas[nomor_tugas - 1].mata_kuliah);
            cout << "Deadline baru: ";
            getline(cin, data_tugas[nomor_tugas - 1].deadline);
            cout << "Tugas berhasil diubah." << endl;
        } else {
            cout << "Nomor tugas tidak valid." << endl;
        }
    } else {
        cout << "Daftar tugas kosong." << endl;
    }
}

// Fungsi untuk mencari data tugas berdasarkan kata kunci
void cari_tugas() {
    cout << "Ketik sesuatu yang anda cari: ";
    string kata_kunci;
    cin.ignore();
    getline(cin, kata_kunci);

    bool ditemukan = false;
    for (int i = 0; i < jumlah_tugas; i++) {
        if (data_tugas[i].nama.find(kata_kunci) != string::npos || data_tugas[i].mata_kuliah.find(kata_kunci) != string::npos || data_tugas[i].deadline.find(kata_kunci) != string::npos) {
            cout << i + 1 << ": " << "Nama Tugas: " << data_tugas[i].nama << ", Mata Kuliah: " << data_tugas[i].mata_kuliah << ", Deadline: " << data_tugas[i].deadline << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Tugas tidak ditemukan untuk kata kunci '" << kata_kunci << "'." << endl;
    }
}

int main() {
    while (true) {
        cout << "1. Tampilkan Data Tugas" << endl;
        cout << "2. Tambahkan Tugas Baru" << endl;
        cout << "3. Hapus Tugas" << endl;
        cout << "4. Ubah Tugas" << endl;
        cout << "5. Cari Tugas" << endl;
        cout << "6. Keluar" << endl;

        int pilihan;
        cout << "Mau no berapa?: ";
        cin >> pilihan;

        if (pilihan == 1) {
            tampilkan_data_tugas();
        } else if (pilihan == 2) {
            tambahkan_tugas();
        } else if (pilihan == 3) {
            hapus_tugas();
        } else if (pilihan == 4) {
            ubah_tugas();
        } else if (pilihan == 5) {
            cari_tugas();
        } else if (pilihan == 6) {
            cout << "Program selesai." << endl;
            return 0;
        } else {
            cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
    }

    return 0;
}

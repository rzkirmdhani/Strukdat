#include <iostream>
#include <string>

using namespace std;

// Struktur menyimpan data tugas
struct Tugas {
    string nama;
    string mata_kuliah;
    string deadline;
    Tugas* next; // Pointer ke node berikutnya
};

Tugas* head = nullptr; // Pointer ke node pertama

// Menampilkan semua data tugas
void tampilkan_data_tugas() {
    cout << "Data Tugas:" << endl;
    Tugas* current = head; // Pointer saat ini
    int nomor = 1;
    
    while (current != nullptr) {
        cout << nomor << ": Nama Tugas: " << current->nama << ", Mata Kuliah: " << current->mata_kuliah << ", Deadline: " << current->deadline << endl;
        current = current->next; // Pindah ke node berikutnya
        nomor++;
    }
}

// Menambahkan tugas baru ke akhir linked list
void tambahkan_tugas() {
    Tugas* tugas_baru = new Tugas;
    cout << "Apa nama tugas baru: ";
    cin.ignore();
    getline(cin, tugas_baru->nama);
    cout << "Matkul apa: ";
    getline(cin, tugas_baru->mata_kuliah);
    cout << "Kapan deadline: ";
    getline(cin, tugas_baru->deadline);
    
    tugas_baru->next = nullptr; // Mengatur pointer ke node berikutnya menjadi nullptr
    
    if (head == nullptr) {
        // Jika linked list masih kosong, atur head ke tugas baru
        head = tugas_baru;
    } else {
        // Jika tidak kosong, cari node terakhir dan tambahkan tugas baru ke sana
        Tugas* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = tugas_baru;
    }
    
    cout << "Tugas berhasil ditambahkan." << endl;
}

// Menghapus tugas berdasarkan nomor
void hapus_tugas() {
    if (head != nullptr) {
        cout << "No berapa yang ingin dihapus: ";
        int nomor_tugas;
        cin >> nomor_tugas;
        
        if (nomor_tugas == 1) {
            // Jika yang dihapus adalah node pertama
            Tugas* temp = head;
            head = head->next;
            delete temp;
            cout << "Tugas berhasil dihapus." << endl;
        } else if (nomor_tugas > 1) {
            Tugas* current = head;
            int nomor = 1;
            
            while (current != nullptr && nomor < nomor_tugas - 1) {
                current = current->next;
                nomor++;
            }
            
            if (current != nullptr && current->next != nullptr) {
                Tugas* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Tugas berhasil dihapus." << endl;
            } else {
                cout << "Nomor tugas tidak valid." << endl;
            }
        } else {
            cout << "Nomor tugas tidak valid." << endl;
        }
    } else {
        cout << "Daftar tugas kosong." << endl;
    }
}

// Implementasi lainnya (ubah_tugas, cari_tugas) dapat tetap digunakan dengan sedikit perubahan dalam tipe data.

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

        switch (pilihan) {
            case 1:
                tampilkan_data_tugas();
                break;
            case 2:
                tambahkan_tugas();
                break;
            case 3:
                hapus_tugas();
                break;
            case 4:
                // Tambahkan implementasi ubah_tugas
                break;
            case 5:
                // Tambahkan implementasi cari_tugas
                break;
            case 6:
                cout << "Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
    }

    return 0;
}

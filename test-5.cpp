#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string namaFile;
    cout << "Masukkan nama file yang ingin diedit: ";
    getline(cin, namaFile);

    ifstream file(namaFile);
    if (!file) {
        cout << "File tidak ditemukan!\n";
        return 1;
    }

    string isi;
    getline(file, isi);
    file.close();

    // Cek isi file
    if (isi == "hello world") {
        isi += "!";
        
        ofstream out(namaFile);
        out << isi;
        out.close();

        cout << "Tanda seru berhasil ditambahkan!\n";
    } else {
        cout << "Isi file bukan 'hello world', tidak ada perubahan.\n";
    }

    return 0;
}

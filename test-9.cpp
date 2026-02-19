#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string sumber, tujuan;  // folder asal dan folder tujuan

    std::cout << "Masukkan path folder sumber: "; // user memilih folder sumber
    std::getline(std::cin, sumber);

    std::cout << "Masukkan path folder tujuan: "; // user memilih folder tujuan
    std::getline(std::cin, tujuan);

    try {
        fs::copy(  // memanggil fungsi copy dari filesystem
            sumber,
            tujuan,
            fs::copy_options::recursive |  // isinya ikut dicopy
            fs::copy_options::overwrite_existing // ditimpa isinya kalo ada
        );

        std::cout << "Folder berhasil dicopy!\n";
    }
    catch (fs::filesystem_error& e) {  // jika terjadi eror
        std::cout << "Error: " << e.what() << "\n"; // pesan erornya
    }
    return 0;
}

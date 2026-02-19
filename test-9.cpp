#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    std::string sumber, tujuan;

    std::cout << "Masukkan path folder sumber: ";
    std::getline(std::cin, sumber);

    std::cout << "Masukkan path folder tujuan: ";
    std::getline(std::cin, tujuan);

    try {
        fs::copy(
            sumber,
            tujuan,
            fs::copy_options::recursive |
            fs::copy_options::overwrite_existing
        );

        std::cout << "Folder berhasil dicopy!\n";
    }
    catch (fs::filesystem_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}

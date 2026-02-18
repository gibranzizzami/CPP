#include <iostream>
#include <fstream>

int main() {
    std::ofstream file("output.txt");

    if (file.is_open()) {
        file << "hello" << std::endl;
        file << "world" << std::endl;
        file.close();
        std::cout << "file berhasil dibuat" << std::endl;
    } else {
        std::cout << "gagal membuat file." << std::endl;
    }
    return 0;
}

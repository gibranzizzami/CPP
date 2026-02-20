#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {

    // 1. Membuat folder
    fs::create_directory("folder_asli");

    // 2. Membuat file
    ofstream buatFile("folder_asli/data.txt");
    buatFile.close();

    // 3. Delete folder dan file (contoh folder & file lain)
    fs::create_directory("folder_hapus");
    ofstream("file_hapus.txt").close();
    fs::remove("file_hapus.txt");
    fs::remove_all("folder_hapus");

    // 4. Write file (line 1 hello, line 2 world)
    ofstream tulis("folder_asli/data.txt");
    tulis << "hello" << endl;
    tulis << "world" << endl;
    tulis.close();

    // 5. Update file (tambah tanda seru)
    {
        ifstream baca("folder_asli/data.txt");
        string baris1, baris2;
        getline(baca, baris1);
        getline(baca, baris2);
        baca.close();

        baris2 += "!";

        ofstream update("folder_asli/data.txt");
        update << baris1 << endl;
        update << baris2 << endl;
        update.close();
    }

    // 6. Ganti enter menjadi spasi (jadi 1 baris)
    {
        ifstream baca("folder_asli/data.txt");
        string baris, hasil;

        while (getline(baca, baris)) {
            if (!hasil.empty()) hasil += " ";
            hasil += baris;
        }
        baca.close();

        ofstream tulisUlang("folder_asli/data.txt");
        tulisUlang << hasil;
        tulisUlang.close();
    }

    // 7. Copy file
    fs::copy("folder_asli/data.txt",
             "folder_asli/data_copy.txt",
             fs::copy_options::overwrite_existing);

    // 8. Move file
    fs::rename("folder_asli/data_copy.txt",
               "folder_asli/data_moved.txt");

    // 9. Copy folder
    fs::copy("folder_asli",
             "folder_copy",
             fs::copy_options::recursive |
             fs::copy_options::overwrite_existing);

    return 0;
}
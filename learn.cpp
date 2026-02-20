#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
    // 1. Membuat folder
    fs::create_directory("folder_asli");
    cout << "Folder 'folder_asli' dibuat.\n";

    // 2. Membuat file
    ofstream("folder_asli/data.txt").close();
    cout << "File 'data.txt' dibuat di folder_asli.\n";

    // 3. Write file (line 1 hello, line 2 world)
    ofstream tulis("folder_asli/data.txt");
    tulis << "hello" << endl;
    tulis << "world" << endl;
    tulis.close();
    cout << "File diisi dengan 'hello' dan 'world'.\n";

    // 4. Update file (tambah tanda seru)
    {
        ifstream baca("folder_asli/data.txt");
        string baris1, baris2;
        getline(baca, baris1);
        getline(baca, baris2);
        baca.close();

        baris2 += "!";

        ofstream update("folder_asli/data.txt");
        update << baris1 <<endl;
        update << baris2 << endl;
        update.close();
        cout << "Tanda seru ditambahkan pada baris kedua.\n";
    }

    // 5. Ganti enter menjadi spasi (jadi satu baris)
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
        cout << "Enter diganti spasi, file menjadi satu baris.\n";
    }

    // 6. Copy file
    fs::copy("folder_asli/data.txt",
             "folder_asli/data_copy.txt",
             fs::copy_options::overwrite_existing);
    cout << "File berhasil dicopy menjadi data_copy.txt.\n";

    // 7. Move file
    fs::rename("folder_asli/data_copy.txt",
               "folder_asli/data_moved.txt");
    cout << "File data_copy.txt dipindahkan menjadi data_moved.txt.\n";

    // 8. Copy folder
    fs::copy("folder_asli",
             "folder_copy",
             fs::copy_options::recursive |
             fs::copy_options::overwrite_existing);
    cout << "Folder folder_asli berhasil dicopy menjadi folder_copy.\n";

    // 9. Delete folder dan file
    fs::remove("folder_asli/data_moved.txt");
    fs::remove("folder_asli/data.txt");
    fs::remove_all("folder_asli");
    cout << "Folder dan file berhasil dihapus.\n";
    return 0;
}
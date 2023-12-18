#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Menu {
  string nama;
  int harga;
};

void tampilkanMenu(const Menu daftarMenu[], int size) {
  cout <<"selamat datang di restoran tawa saji" << endl;
  cout <<"Dapatkan diskon jika berbelanja lebih dari 500.000" << endl;
  cout <<"------anda puas kami bahagia--------" << endl <<endl;
  cout << "Daftar Menu Restoran:" << endl;
  cout << setw(20) << left << "Menu" << setw(31) << right << "Harga" << endl;
  cout << setfill('-') << setw(51) << "" << setfill(' ') << endl;

  for (int i = 0; i < size; ++i) {
        cout << setw(31) << left << daftarMenu[i].nama << setw(20) << right << daftarMenu[i].harga << endl;
  }
}

int totalHarga = 0;
char lanjutPesan;
int uangPelanggan = 0;
int pajak = 0;
double persentase = 0.10;
int hargaSPajak;
int hargaSDiskon;
int kembalian;

int discount (int x) {
  double diskon = 0.20 * hargaSPajak;
  return hargaSPajak - diskon;
};

int main() {
  // Inisialisasi daftar menu
  const int jumlahMenu = 8;
    Menu daftarMenu[jumlahMenu] = {
    {"1. Roti Jala Maklima Biadab", 20000},
    {"2. Sop Iga Tulang Belakang Eren", 30000},
    {"3. Nasi Kentut Medan", 25000},
    {"4. Steak Wahyu A5", 350000},
    {"5. Telor Presto", 5000},
    {"6. Mekdi Israel", 30000},
    {"7. Tahu", 4000},
    {"8. Tidak Tahu", 4000}
  };

  // Menampilkan daftar menu
  tampilkanMenu(daftarMenu,jumlahMenu);

  // Memproses pesanan
  Menu * pesananPelanggan = new Menu[jumlahMenu];

    int pesananCount=0;
  do {
    int nomorMenu, jumlahPesanan;


  cout << "Masukkan uang anda: ";
  cin >> uangPelanggan;
  

    cout << "\nMasukkan nomor menu yang dipilih: ";
    cin >> nomorMenu;

    if (nomorMenu >= 1 && nomorMenu <= jumlahMenu) {
            cout << "Masukkan jumlah pesanan: ";
        cin >> jumlahPesanan;

        totalHarga += daftarMenu[nomorMenu - 1].harga * jumlahPesanan; //dikurangin 1 karena index array dimulai dari 0
        pajak = totalHarga * persentase;
        hargaSPajak = totalHarga + pajak;

        cout << "Makan disini atau dirumah?(y/n)";
        cin >> lanjutPesan;
        
              int makanDisini;
                if (makanDisini == 'y' || makanDisini == 'Y') {
                    cout << "Total harga: " << hargaSPajak << endl;
                }
        
        

        // Menyimpan pesanan
        pesananPelanggan[pesananCount] = daftarMenu[nomorMenu - 1];
        pesananPelanggan[pesananCount].harga = jumlahPesanan;

            pesananCount++;
        cout << "\nLanjutkan pesanan? (y/n): ";
        cin >> lanjutPesan;

          
            cout << "\nDaftar Pesanan Anda:" << endl;
            cout << setw(20) << left << "Menu" << setw(10) << right << "Jumlah" << endl;
            cout << setfill('-') << setw(30) << "" << setfill(' ') << endl;
        } else {
            cout << "Nomor menu tidak valid. Silakan coba lagi." << endl;
        }
  } while (lanjutPesan == 'y' || lanjutPesan == 'Y');

  kembalian = uangPelanggan - hargaSPajak;

    switch (uangPelanggan < totalHarga) {
        case 1 :
        cout << "Maaf uang anda kurang untuk membeli menu ini." << endl;
        break;
        default :
        cout << "Kembalian anda: " << kembalian << endl; // Menampilkan kembalian pelanggan
    } 
        
    cout << setw(35) << left << "\nmenu yang dipesan" << setw(10) << right << "jumlah" << endl;
    cout << setfill('-') << setw(50) << "" << setfill(' ') << endl;
    for (int i = 0; i < pesananCount; ++i) {
        cout << setw(33) << left << pesananPelanggan[i].nama << setw(10) << right << pesananPelanggan[i].harga << endl;
    }


hargaSDiskon = discount(1) + pajak;
if (hargaSPajak > 500000)
{
  cout << "Harga setelah anda mendapat diskon: " << hargaSDiskon << endl;
} else {
  cout << "\nTotal Harga: " << hargaSPajak << endl;
}

  return 0;
}

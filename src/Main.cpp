#include <iostream>
#include <array>
#include <string.h>
#include <conio.h>
// #include <termios.h>
// #include <thread>
// #include <unistd.h>

using namespace std;

/*
BUAT SISTEM TOKO SWALAYAN, dengan ketentuan sebagai berikut :

dengan inputan : iya
fungsi string minimal 3 : strlen(), stoi(), to_string()
while/do while : while
fungsi prototype : iya
for : wajib
if else :wajib
switch-case : wajib
runtutan :wajib
array :wajib
overloading : opsional
struct : tidak
*/

int getLengthArray();
int autoIncrementKodeBarang();
int autoIncrement();
void menuKasir();
void menuAdmin();
void login();
void changePassword(char password[50]);
void tambahDataBarang();
void updateDataBarang();
void hapusDataBarang();
void hanyaTampilkanData();
void tampilDataBarang();
void struk(string jumlah_barang[6][6], int bayar, int kembalian, int jumlah, int total);
void transaksi();
int getIncrementBarang(string kode_barang);
void getCart(string jumlah_beli[6][6], int jumlah);
// char getch(void);

// data barang
string barang[10][5] = {
    {" 1 ", "22001", "Beras Petruk ", "KG", "25000 "},
    {" 2 ", "22002", "Gula Pasir ", "KG", "5000 "},
    {" 3 ", "22003", "Minyak Goreng Sania ", "Liter", "15000 "},
    {" 4 ", "22004", "Susu Dancow ", "Gram", "20000 "},
    {" 5 ", "22005", "Telur Ayam ", "KG", "20000 "}};

int main(int argc, char const *argv[])
{

  login();

  return 0;
}

int getLengthArray()
{
  int i = 0;
  int nomor;
  for (i = 0; i < end(barang) - begin(barang); i++)
  {
    if (barang[i][0] != "")
    {
      nomor = stoi(barang[i][0]);
    }
  }

  return nomor;
}

int autoIncrementKodeBarang()
{
  int i = 0;
  int kode_barang;
  for (i = 0; i < getLengthArray(); i++)
  {
    // get last kode_barang in array barang
    if (barang[i][0] != "")
    {
      kode_barang = stoi(barang[i][1]);
    }
  }
  kode_barang = kode_barang + 1;

  return kode_barang;
}

int autoIncrement()
{
  int i = 0;
  int nomor;
  for (i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      nomor = stoi(barang[i][0]);
    }
  }

  return nomor;
}

//! proses enkripsi password menjadi bintang
void changePassword(int ch, string &password)
{
  while (ch != 13) // 13 as enter key
  {
    while (ch == 8) // 8 as backspace key
    {
      cout << "\b \b";
      password.pop_back();
      ch = getch();
    }
    password.push_back(ch);
    cout << '*';
    ch = getch();
  }
}

void menuKasir()
{
  int pilihan;
  // cout << "\033[2J\033[0;0H";
  system("cls");
  cout << "|===============================|" << endl;
  cout << "|             MENU              |" << endl;
  cout << "|===============================|" << endl;
  cout << "| 1. Point Of Sale              |" << endl;
  cout << "| 2. Logout                     |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Pilihan : ";
  cin >> pilihan;
  cout << "|===============================|" << endl;

  switch (pilihan)
  {
  case 1:
    transaksi();
    break;
  case 2:
    cin.ignore();
    login();
    break;
  default:
    cout << "| Pilihan tidak ada" << endl;
    cout << "|===============================|" << endl;
    menuKasir();
    break;
  }
}

//! pilihan menu admin
void menuAdmin()
{

  int pilihan;
  // cout << "\033[2J\033[0;0H";
  system("cls");
  cout << "|===============================|" << endl;
  cout << "|             MENU              |" << endl;
  cout << "|===============================|" << endl;
  cout << "| 1. Lihat Barang               |" << endl;
  cout << "| 2. Tambah Barang              |" << endl;
  cout << "| 3. Edit Barang                |" << endl;
  cout << "| 4. Hapus Barang               |" << endl;
  cout << "| 5. Logout                     |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Pilihan : ";
  cin >> pilihan;
  cout << "|===============================|" << endl;

  switch (pilihan)
  {
  case 1:
    tampilDataBarang();
    break;
  case 2:
    tambahDataBarang();
    break;
  case 3:
    updateDataBarang();
    break;
  case 4:
    hapusDataBarang();
    break;
  case 5:
    cin.ignore();
    login();
    break;
  default:
    cout << "| Pilihan tidak ada" << endl;
    cout << "|===============================|" << endl;
    menuAdmin();
    break;
  }
}

//! untuk melekakukan login
void login()
{
  int ch;
  string username, password;

  // cout << "\033[2J\033[0;0H";
  system("cls");
  cout << "|===============================|" << endl;
  cout << "|             LOGIN             |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Username : ";
  cin >> username;
  cout << "| Password : ";
  ch = getch();
  changePassword(ch, password);
  cout << "|===============================|" << endl;

  if (username == "admin" && password == "admin")
  {
    cout << "| Login Berhasil" << endl;
    cout << "|===============================|" << endl;
    menuAdmin();
  }
  else if (username == "kasir" && password == "kasir")
  {
    cout << "| Login Berhasil" << endl;
    cout << "|===============================|" << endl;
    menuKasir();
  }
  else
  {
    cout << "| Login Gagal" << endl;
    cout << "|===============================|" << endl;
    login();
  }
}

// fungsi untuk menambahkan data barang
void tambahDataBarang()
{
  char kembali;
  int nomor = autoIncrement();
  int kode_barang = autoIncrementKodeBarang();
  string namaBarang, hargaBarang, satuanBarang;

  // cout << "\033[2J\033[0;0H";
  system("cls");

  cout << "\nTambah data barang" << endl;
  hanyaTampilkanData();

  cin.ignore();
  cout << "\nMasukkan nama barang : ";
  getline(cin, namaBarang);
  cout << "Masukkan harga barang : ";
  cin >> hargaBarang;
  cout << "Masukkan satuan barang : ";
  cin >> satuanBarang;

  barang[nomor][0] = " " + to_string(nomor + 1);
  barang[nomor][1] = to_string(kode_barang);
  barang[nomor][2] = namaBarang;
  barang[nomor][3] = satuanBarang;
  barang[nomor][4] = hargaBarang;

  cout << "\n\nTambah barang berhasil" << endl;
  ;

  cout << "\n\nanda ingin kembali? (y/n) : ";
  cin >> kembali;
  if (kembali == 'y' || kembali == 'Y')
  {
    menuAdmin();
  }
  else
  {
    login();
  }
}

void updateDataBarang()
{
  char kembali;
  int nomor, kode_barang;

  // cout << "\033[2J\033[0;0H";
  system("cls");

  cout << "\Edit data barang" << endl;

  hanyaTampilkanData();

  cout << "\nMasukan kode barang yang ingin di ubah :";
  cin >> kode_barang;

  char namaBarang[50], hargaBarang[50], satuanBarang[50];
  cin.ignore();

  cout << "\nMasukkan nama barang : ";
  cin.getline(namaBarang, 50);
  cout << "Masukkan harga barang : ";
  cin.getline(hargaBarang, 50);
  cout << "Masukkan satuan barang : ";
  cin.getline(satuanBarang, 50);

  if (strlen(namaBarang) == 0)
  {
    cout << "Nama barang tidak boleh kosong" << endl;
  }
  else if (strlen(hargaBarang) == 0)
  {
    cout << "Harga barang tidak boleh kosong" << endl;
  }
  else if (strlen(satuanBarang) == 0)
  {
    cout << "Satuan barang tidak boleh kosong" << endl;
  }
  else
  {

    for (int i = 0; i < getLengthArray(); i++)
    {
      if (barang[i][0] != "")
      {
        if (stoi(barang[i][1]) == kode_barang)
        {
          kode_barang = stoi(barang[i][1]);
          nomor = stoi(barang[i][0]);
        }
      }
    }

    nomor = nomor - 1;

    barang[nomor][0] = to_string(nomor + 1);
    barang[nomor][1] = to_string(kode_barang);
    barang[nomor][2] = namaBarang;
    barang[nomor][3] = satuanBarang;
    barang[nomor][4] = hargaBarang;
  }

  cout << "\n\nUpdate Barang berhasil" << endl;

  cout << "\n\nanda ingin kembali? (y/n) : ";
  cin >> kembali;
  if (kembali == 'y' || kembali == 'Y')
  {
    menuAdmin();
  }
  else
  {
    login();
  }
}

void hapusDataBarang()
{
  int nomor;
  char kembali, kode_barang[6];
  // cout << "\033[2J\033[0;0H";
  system("cls");
  cout << "\nHapus data barang" << endl;

  hanyaTampilkanData();
  cin.ignore();
  cout << "\nMasukkan kode barang yang akan dihapus : ";
  cin.getline(kode_barang, 6);

  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      if (stoi(barang[i][1]) == stoi(kode_barang))
      {
        nomor = stoi(barang[i][0]);
      }
    }
  }
  nomor = nomor - 1;

  barang[nomor][0] = "";
  barang[nomor][1] = "";
  barang[nomor][2] = "";
  barang[nomor][3] = "";
  barang[nomor][4] = "";

  cout << "\n\nHapus Barang berhasil" << endl;

  cout << "\n\nAnda ingin kembali? (y/n) : ";
  cin >> kembali;
  if (kembali == 'y' || kembali == 'Y')
  {
    menuAdmin();
  }
  else if (kembali == 'n' || kembali == 'N')
  {
    login();
  }
}

void hanyaTampilkanData()
{
  cout << "\nNo. \t| Kode Barang \t| Nama Barang \t\t| Satuan \t| Harga" << endl;
  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      cout << barang[i][0] << "\t| " << barang[i][1] << "\t\t| " << barang[i][2] << "\t\t| " << barang[i][3] << "\t| " << barang[i][4] << endl;
    }
  }
}

void tampilDataBarang()
{
  char pilihan;
  // cout << "\033[2J\033[0;0H";
  system("cls");
  cout << "\nNo. \t| Kode Barang \t| Nama Barang \t\t| Satuan \t| Harga" << endl;
  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      cout << barang[i][0] << "\t| " << barang[i][1] << "\t\t| " << barang[i][2] << "\t\t| " << barang[i][3] << "\t| " << barang[i][4] << endl;
    }
  }

  cout << "\n\nanda ingin kembali? (y/n) : ";
  cin >> pilihan;
  if (pilihan == 'y' || pilihan == 'Y')
  {
    menuAdmin();
  }
  else
  {
    login();
  }
}

// function for printing receipt
void struk(string jumlah_beli[6][6], int bayar, int kembalian, int jumlah, int total)
{
  // cout << "\033[2J\033[0;0H";
  system("cls");
  cout << "              PT. SWALAYAN             " << endl;
  cout << "      NPWP : 75.245.132.3-556.000      " << endl;
  cout << "             OUTLET JAGAKARSA          " << endl;
  cout << "=======================================" << endl;
  for (int i = 0; i < jumlah; i++)
  {
    cout << "   \t" << jumlah_beli[i][1] << " -" << jumlah_beli[i][0] << "("
         << jumlah_beli[i][2] << ")"
         << "\t\t" << endl;
    cout << " \t\t" << jumlah_beli[i][3] << " x " << jumlah_beli[i][4] << " : "
         << jumlah_beli[i][5] << "\t" << endl;
  }
  cout << "=======================================" << endl;
  cout << " Total              : " << total << "\t\t" << endl;
  cout << " Bayar              : " << bayar << "\t\t" << endl;
  cout << " Kembalian          : " << kembalian << "\t\t" << endl;
  cout << "=======================================" << endl;
  cout << " Terima Kasih Telah Berbelanja di Toko " << endl;
  cout << "=======================================" << endl;
  cout << endl;
}

void transaksi()
{
  string jawab, jumlah_beli[6][6];
  int pilihan, jumlah = 1, qty, total = 0, bayar, kembalian, total_harga;
  bool repeat = true;
  char re;
  while (repeat != false)
  {
    system("cls");
    cout << "==================================" << endl;
    cout << "Selamat Datang Kasir Toko Swalayan" << endl;
    cout << "==================================" << endl;
    cout << "ketik 13 untuk kembali menu kasir" << endl;
    cout << "==================================" << endl;
    cout << "\n========DAFTAR BARANG ======" << endl;
    for (int i = 0; i < getLengthArray(); i++)
    {
      if (barang[i][0] != "")
      {
        cout << barang[i][0] << ". " << barang[i][1] << " - " << barang[i][2] << " Rp. " << barang[i][4] << endl;
      }
    }

    for (int i = 0; i < jumlah; i++)
    {
      // input barang yang ingin dibeli
      cout << "==============================" << endl;
      cout << "\nMasukkan kode barang : ";
      cin >> jawab;

      if (jawab == "13")
      {
        menuKasir();
        break;
      }

      pilihan = getIncrementBarang(jawab);

      if (barang[pilihan][0] == "")
      {
        cout << "Tidak ada barang" << endl;
        cout << "Apakah anda ingin mengulang? (y/n) : ";
        cin >> re;
        if (re == 'y' || re == 'Y')
        {
          transaksi();
        }
        else if (re == 'n' || re == 'N')
        {
          repeat = false;
        }
        else
        {
          cout << "Inputan salah, silahkan lakukan transaksi kembali" << endl;
        }
      }
      else
      {
        cout << "Anda memilih " << barang[pilihan][2] << endl;
        cout << "Masukkan " << barang[pilihan][3] << " : ";
        cin >> qty;
        int harga = stoi(barang[pilihan][4]);
        total = qty * harga;
        // input jumlah barang yang ingin dibeli
        jumlah_beli[i][0] = barang[pilihan][2]; // nama barang
        jumlah_beli[i][1] = barang[pilihan][1]; // kode barang
        jumlah_beli[i][2] = barang[pilihan][3]; // satuan barang
        jumlah_beli[i][3] = to_string(qty);     // qty barang
        jumlah_beli[i][4] = to_string(harga);   // harga barang persatuan
        jumlah_beli[i][5] = to_string(total);   // total harga barang

        // tambah barang?
        cout << "\nApakah anda ingin menambah barang? (y/n) : ";
        cin >> jawab;
        if (jawab == "y" || jawab == "Y")
        {
          jumlah++;
        }
        else
        {
          break;
        }
      }
    }

    // calultae all qty in jumlah_beli
    total_harga = 0;
    for (int i = 0; i < jumlah; i++)
    {
      total_harga += stoi(jumlah_beli[i][5]);
    }

    system("cls");
    cout << "\n==============CART================" << endl;
    getCart(jumlah_beli, jumlah);
    cout << "\nTotal Harga : Rp. " << total_harga << endl;
    cout << "Masukkan Uang Anda : Rp. ";
    cin >> bayar;

    while (bayar < total_harga)
    {
      cout << "Uang anda kurang, silahkan masukan ulang" << endl;
      cout << "Masukkan Uang Anda : Rp. ";
      cin >> bayar;
    }
    kembalian = bayar - total_harga;
    // call function struk
    struk(jumlah_beli, bayar, kembalian, jumlah, total_harga);
    cout << "Tekan enter untuk melanjutkan..";
    cin.ignore();
    cin.get();
  }
}

int getIncrementBarang(string kode_barang)
{
  int nomor = 0;
  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][1] == kode_barang)
    {
      nomor = stoi(barang[i][0]);
    }
  }

  return nomor - 1;
}

void getCart(string jumlah_beli[6][6], int jumlah)
{
  for (int i = 0; i < jumlah; i++)
  {
    if (jumlah_beli[i][0] != "")
    {
      cout << jumlah_beli[i][0] << " - " << jumlah_beli[i][3] << " " << jumlah_beli[i][2] << " - Rp. " << jumlah_beli[i][5] << endl;
    }
  }
}

// char getch(void)
// {
//   char buf = 0;
//   struct termios old = {0};
//   fflush(stdout);
//   if (tcgetattr(0, &old) < 0)
//     perror("tcsetattr()");
//   old.c_lflag &= ~ICANON;
//   old.c_lflag &= ~ECHO;
//   old.c_cc[VMIN] = 1;
//   old.c_cc[VTIME] = 0;
//   if (tcsetattr(0, TCSANOW, &old) < 0)
//     perror("tcsetattr ICANON");
//   if (read(0, &buf, 1) < 0)
//     perror("read()");
//   old.c_lflag |= ICANON;
//   old.c_lflag |= ECHO;
//   if (tcsetattr(0, TCSADRAIN, &old) < 0)
//     perror("tcsetattr ~ICANON");
//   return buf;
// }
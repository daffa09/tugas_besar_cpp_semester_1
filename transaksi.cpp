#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

/*
BUAT SISTEM TOKO SWALAYAN, dengan ketentuan sebagai berikut :

dengan inputan : iya
fungsi string minimal 3 : strlen(), strcmp(), stoi(), to_string()
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

void struk(string jumlah_barang[6][6], int bayar, int kembalian, int jumlah);
void transaksi();
int getIncrementBarang(string kode_barang);
void getCart(string jumlah_beli[6][6], int jumlah);

string barang[10][5] = {
    {" 1 ", "22001", " Beras Petruk ", "KG", "25000 "},
    {" 2 ", "22002", " Gula Pasir ", "KG", "5000 "},
    {" 3 ", "21003", " Minyak Goreng Sania ", "Liter", "15000 "},
    {" 4 ", "19004", " Susu Dancow ", "Gram", "20000 "},
    {" 5 ", "20005", " Telur Ayam ", "KG", "20000 "}};

int main(int argc, char const *argv[])
{
  transaksi();

  cout << "program selesai" << endl;
  time_t waktu;
  time(&waktu);
  cout << ctime(&waktu) << endl;
  cin.get();
  return 0;
}

// function for printing receipt
void struk(string jumlah_beli[6][6], int bayar, int kembalian, int jumlah)
{
  system("cls");
  cout << "              PT. SWALAYAN             " << endl;
  cout << "      NPWP : 75.245.132.3-556.000      " << endl;
  cout << "             OUTLET JAGAKARSA          " << endl;
  cout << "=======================================" << endl;
  for (int i = 0; i < jumlah; i++)
  {
    cout << "   \t" << jumlah_beli[i][1] << " -" << jumlah_beli[i][0] << "(" << jumlah_beli[i][2] << ")"
         << "\t\t" << endl;
    cout << " \t\t" << jumlah_beli[i][3] << " x " << jumlah_beli[i][4] << " : " << jumlah_beli[i][5] << "\t" << endl;
  }
  cout << "=======================================" << endl;
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
  int pilihan, jumlah = 1, qty, total = 0, bayar, kembalian;
  bool repeat = true;
  char re;
  while (repeat != false)
  {
    system("cls");
    cout << "==================================" << endl;
    cout << "Selamat Datang Kasir Toko Swalayan" << endl;
    cout << "==================================" << endl;
    // cout << "masukan jumlah barang yang ingin dibeli : ";
    // cin >> jumlah;
    cout << "\n========DAFTAR BARANG ======" << endl;
    for (int i = 0; i < size(barang); i++)
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
      cout << "Masukkan kode barang : ";
      cin >> jawab;

      // pilihan = pilihan - 1;
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
        cout << "Apakah anda ingin menambah barang? (y/n) : ";
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
    for (int i = 0; i < jumlah; i++)
    {
      total += stoi(jumlah_beli[i][5]);
    }

    system("cls");
    cout << "\n==============CART================" << endl;
    getCart(jumlah_beli, jumlah);
    cout << "\nTotal Harga : Rp. " << total << endl;
    cout << "Masukkan Uang Anda : Rp. ";
    cin >> bayar;

    while (bayar < total)
    {
      cout << "Uang anda kurang, silahkan masukan ulang" << endl;
      cout << "Masukkan Uang Anda : Rp. ";
      cin >> bayar;
    }
    kembalian = bayar - total;
    // call function struk
    struk(jumlah_beli, bayar, kembalian, jumlah);

    cout << "Apakah anda ingin membeli barang lagi? (y/n) : ";
    cin >> re;

    if (re == 'y' || re == 'Y')
    {
      repeat = true;
    }
    else if (re == 'n' || re == 'N')
    {
      repeat = false;
    }
    else
    {
      cout << "Inputan salah, silahkan mulai ulang" << endl;
    }
  }
}

int getIncrementBarang(string kode_barang)
{
  int nomor = 0;
  for (int i = 0; i < size(barang); i++)
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
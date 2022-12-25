#include <iostream>
#include <string.h>
#include <array>

using namespace std;

/* BUAT SISTEM TOKO SWALAYAN */

int getLengthArray();
int autoIncrementKodeBarang();
int autoIncrement();
void tambahDataBarang();
void updateDataBarang();
void hapusDataBarang();
void tampilDataBarang();

// data barang, dimulai dari index 1
string barang[10][5] = {
    {" 1 ", "22001", " Beras Petruk ", "KG", "25000 "},
    {" 2 ", "22002", " Gula Pasir ", "KG", "5000 "},
    {" 3 ", "21003", " Minyak Goreng Sania ", "Liter", "15000 "},
    {" 4 ", "19004", " Susu Dancow ", "Gram", "20000 "},
    {" 5 ", "20005", " Telur Ayam ", "KG", "20000 "}};

int main(int argc, char const *argv[])
{

  // tambahDataBarang();
  // cout << getLengthArray() << endl;
  // cout << autoIncrementKodeBarang() << endl;
  // cout << autoIncrement() << endl;
  tampilDataBarang();
  updateDataBarang();
  // hapusDataBarang();
  tampilDataBarang();

  return 0;
}

int getLengthArray()
{
  int i = 0;
  int nomor = 0;
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
  int kode_barang = 0;
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

void tambahDataBarang()
{
  int nomor = autoIncrement();
  int kode_barang = autoIncrementKodeBarang();

  string namaBarang, hargaBarang, satuanBarang;

  cout << "Masukkan nama barang : ";
  cin >> namaBarang;
  cout << "Masukkan harga barang : ";
  cin >> hargaBarang;
  cout << "Masukkan satuan barang : ";
  cin >> satuanBarang;

  barang[nomor][0] = to_string(nomor + 1);
  barang[nomor][1] = to_string(kode_barang);
  barang[nomor][2] = namaBarang;
  barang[nomor][3] = satuanBarang;
  barang[nomor][4] = hargaBarang;

  cout << "\n\nTambah Barang berhasil" << endl;
}

void updateDataBarang()
{
  int nomor, kode_barang;
  cout << "Masukan nomor barang yang ingin di ubah :";
  cin >> kode_barang;

  char namaBarang[50], hargaBarang[50], satuanBarang[50];
  cin.ignore();

  cout << "Masukkan nama barang : ";
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
}

void hapusDataBarang()
{
  int nomor;
  cout << "Masukkan nomor yang akan dihapus : ";
  cin >> nomor;
  nomor = nomor - 1;
  barang[nomor][0] = "";
  barang[nomor][1] = "";
  barang[nomor][2] = "";
  barang[nomor][3] = "";
  barang[nomor][4] = "";

  cout << "\n\nHapus Barang berhasil" << endl;
}

void tampilDataBarang()
{
  cout << "No. \t| Kode Barang \t| Nama Barang \t\t| Satuan \t| Harga" << endl;
  for (int i = 0; i < getLengthArray(); i++)
  {
    if (barang[i][0] != "")
    {
      cout << barang[i][0] << "\t| " << barang[i][1] << "\t\t| " << barang[i][2] << "\t\t| " << barang[i][3] << "\t| " << barang[i][4] << endl;
    }
  }
}
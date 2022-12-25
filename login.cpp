#include <iostream>
#include <string.h>

using namespace std;

/*
BUAT SISTEM TOKO SWALAYAN, dengan ketentuan sebagai berikut :

dengan inputan : iya
fungsi string minimal 3 : strlen(), strcmp()
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

void changePassword(char password[50]);
void transaksi();
void menuAdmin();
void login();

int main(int argc, char const *argv[])
{
  login();

  return 0;
}

//! proses enkripsi password menjadi bintang
void changePassword(char password[50])
{
  int i = 0;
  while (password[i] != '\0')
  {
    password[i] = '*';
    i++;
  }
}

void transaksi()
{
  cout << "ini adalah transaksi" << endl;
}

//! pilihan menu admin
void menuAdmin()
{

  int pilihan;
  system("cls");
  cout << "|===============================|" << endl;
  cout << "|             MENU              |" << endl;
  cout << "|===============================|" << endl;
  cout << "| 1. Tambah Barang              |" << endl;
  cout << "| 2. Edit Barang                |" << endl;
  cout << "| 2. Hapus Barang               |" << endl;
  cout << "| 3. Logout                     |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Pilihan : ";
  cin >> pilihan;
  cout << "|===============================|" << endl;

  switch (pilihan)
  {
  case 1:
    // tambahBarang();
    break;
  case 2:
    // editBarang();
    break;
  case 3:
    // deleteBarang();
  case 4:
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

  char username[50], password[50];

  system("cls");
  cout << "|===============================|" << endl;
  cout << "|             LOGIN             |" << endl;
  cout << "|===============================|" << endl;
  cout << "| Username : ";
  cin.getline(username, 50);
  cout << "| Password : ";
  cin.getline(password, 50);
  cout << "|===============================|" << endl;

  if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0)
  {
    cout << "| Login Berhasil" << endl;
    cout << "|===============================|" << endl;
    menuAdmin();
  }
  else if (strcmp(username, "kasir") == 0 && strcmp(password, "kasir") == 0)
  {
    cout << "| Login Berhasil" << endl;
    cout << "|===============================|" << endl;
    transaksi();
  }
  else
  {
    cout << "| Login Gagal" << endl;
    cout << "|===============================|" << endl;
    login();
  }
}
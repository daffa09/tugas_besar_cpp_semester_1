DECLARE
void login();
void menuKasir();
void transaksi();
void getLengthArray();
void getCart(string jumlah_beli[6][6], int jumlah);
void struk(string jumlah_beli[6][6], int bayar, int kembalian, int jumlah, int total);
int getIncrementBarang(string kode_barang);

var barang[10][5] = {
    {" 1 ", "22001", " Beras Petruk ", "KG", "25000 "},
    {" 2 ", "22002", " Gula Pasir ", "KG", "5000 "},
    {" 3 ", "22003", " Minyak Goreng Sania ", "Liter", "15000 "},
    {" 4 ", "22004", " Susu Dancow ", "Gram", "20000 "},
    {" 5 ", "22005", " Telur Ayam ", "KG", "20000 "}} : string;

IMPLEMENTATION

login()



FUNCTION
VOID login()
  var ch : int
  var username, password : string

  print(=======login========)
  print(username : )
  input(username)
  print(password : )
  input(password)

  IF(username == "admin" && password == "admin")
    print("login berhasil")
    menuKasir()
  ELSE
    print("login gagal")
    login()
ENDLOGIN

VOID menuKasir()
  var pilihan : int

  print(=======menu kasir========)
  print(1. transaksi)
  print(2. keluar)
  print(pilihan : )
  input(pilihan)

  IF(pilihan == 1)
    transaksi()
  ELSE IF(pilihan == 2)
    login()
  ELSE
    print("pilihan tidak ada")
    menuKasir()
ENDMENUKASIR

VOID transaksi()
  var jawab, jumlah_beli[6][6] : string
  var jumlah=1,pilihan, qty, total=0, bayar, kembalian, total_harga : int
  var repeat : bool
  var re : char

  WHILE(repeat != false)
    print(daftar barang)
    FOR(i=0; i<getLengthArray(); i++)
      IF(barang[i][0] != "")
        print(barang[i][0] + " " + barang[i][1] + " " + barang[i][2] + " " + barang[i][3] + " " + barang[i][4])
      ENDIF
    ENDFOR

    FOR(int i = 0; i < jumlah; i++)
      print(masukan kode barang : )
      input(jawab)

      IF(jawab == "13")
        menuKasir()
        break;
      ENDIF

      pilihan = getIncrementBarang(jawab)

      IF(barang[pilihan][0] == "")
        print(tidak ada barang)
        print(ingin mengulang? (y/n) : )
        input(re)
        IF(re == 'y' || re == 'Y')
          transaksi()
        ELSE IF(re == 'n' || re == 'N')
          repeat = false
        ELSE
          print(inputan salah, silahkan lakukan transaksi kembali)
        ENDIF
      ELSE
        print(anda memilih : barang[pilihan][2])
        print(masukan barang[pilihan][3] : )
        input(qty)
        var harga:int = stoi(barang[pilihan][4])
        total = qty * harga
        jumlah_beli[i][0] = barang[pilihan][2];
        jumlah_beli[i][1] = barang[pilihan][1];
        jumlah_beli[i][2] = barang[pilihan][3];
        jumlah_beli[i][3] = to_string(qty);
        jumlah_beli[i][4] = to_string(harga);
        jumlah_beli[i][5] = to_string(total);

        print(Apakah anda ingin menambah barang? (y/n) : )
        input(re)
        IF(re == 'y' || re == 'Y')
          jumlah++
        ELSE
          break
        ENDIF
      ENDIF
    ENDFOR

    total_harga = 0
    FOR(int i = 0; i < jumlah; i++)
      total_harga += stoi(jumlah_beli[i][5])
    ENDFOR

    print(=========CART==========)
    getCart(jumlah_beli, jumlah)
    print(total harga : total_harga)
    print(masukan uang anda : )
    input(bayar)

    WHILE(bayar < total_harga)
      print(uang anda kurang)
      print(masukan uang anda : )
      input(bayar)
    ENDWHILE

    kembalian = bayar - total_harga
    struk(jumlah_beli, bayar, kembalian, jumlah, total_harga)

    print(tekan enter untuk melanjutkan..)

  ENDWHILE
ENDTRANSAKSI

VOID getLengthArray()
  var i=0, nomor : int
  FOR(i=0; i<end(barang) - begin(barang); i++)
    IF(barang[i][0] != "")
      nomor = stoi(barang[i][0])
    ENDIF
  ENDFOR
  return nomor
ENDGETLENGTHARRAY

VOID getCart(string jumlah_beli[6][6], int jumlah)
  FOR(int i = 0; i < jumlah; i++)
    IF(jumlah_beli[i][0] != "")
      print(i+1 + " " + jumlah_beli[i][0] + " " + jumlah_beli[i][3] + " " + jumlah_beli[i][2] + " - Rp. " + jumlah_beli[i][5])
    ENDIF
  ENDFOR
ENDGETCART

VOID struk(string jumlah_beli[6][6], int bayar, int kembalian, int jumlah, int total)
  print(PT. SWALAYAN)
  FOR(int i = 0; i < jumlah; i++)
    print(jumlah_beli[i][1] + " -" + jumlah_beli[i][0] + " (" + jumlah_beli[i][2] + ") ")
    print(jumlah_beli[i][3] + " x " + jumlah_beli[i][4] + " = " + jumlah_beli[i][5])
  ENDFOR
  print(total : total)
  print(bayar : bayar)
  print(kembalian : kembalian)
  print(Terima kasih telah berbelanja di toko)
ENDSTRUK

VOID getIncrementBarang(string kode_barang)
  var nomor = 0 : int
  FOR(int i=0; i<getLengthArray(); i++)
    IF(barang[i][1] == kode_barang)
      nomor = stoi(barang[i][0])
    ENDIF
  ENDFOR
  return nomor-1
ENDGETINCREMENTBARANG
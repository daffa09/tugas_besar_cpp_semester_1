<!-- portfolio -->
<!-- slug: tugas-besar-cpp-semester-1 -->
<!-- title: Tugas Besar C++ Semester 1 -->
<!-- description: Proyek akhir semester dalam bahasa C++ yang menampilkan operasi CRUD untuk sistem manajemen barang -->
<!-- image: https://github.com/user-attachments/assets/8b23c442-350f-4cf2-abef-1f206bd64c6d -->
<!-- tags: c++, crud, aplikasi-konsol, proyek-semester, manajemen-barang -->

# Tugas Besar C++ Semester 1 (Final Project)

<img width="1536" height="1024" alt="tugas-besar-cpp-semester-1" src="https://github.com/user-attachments/assets/8b23c442-350f-4cf2-abef-1f206bd64c6d" />

Sistem manajemen barang komprehensif yang dibangun dengan C++ sebagai proyek akhir semester satu. Aplikasi berbasis konsol ini mendemonstrasikan operasi CRUD, autentikasi pengguna, dan manajemen transaksi.

## 📋 Ringkasan

Proyek akhir (Tugas Besar) untuk Semester 1 ini menampilkan sistem manajemen barang lengkap yang dibangun sepenuhnya dengan C++. Aplikasi ini memiliki fitur CRUD lengkap untuk mengelola item inventaris, sistem login, dan pemrosesan transaksi — semuanya diimplementasikan sebagai aplikasi konsol.

## ✨ Fitur

- **Sistem Autentikasi**
  - Fungsi login yang aman.
  - Manajemen sesi pengguna.
  - Kontrol akses.

- **Operasi CRUD Lengkap**
  - **Create**: Menambah barang baru ke inventaris.
  - **Read**: Melihat semua barang dan detailnya.
  - **Update**: Mengubah informasi barang yang sudah ada.
  - **Delete**: Menghapus barang dari sistem.

- **Manajemen Transaksi**
  - Memproses transaksi barang.
  - Melacak barang masuk dan keluar.
  - Riwayat transaksi.

- **Persistensi Data**
  - Penyimpanan berbasis file (text files).
  - Menyimpan dan memuat data di antara sesi.

## 🛠️ Teknologi yang Digunakan

- **C++**: Bahasa pemrograman inti.
- **Standard Library**: Kontainer STL dan File I/O.
- **File Handling**: Untuk penyimpanan data.
- **Prinsip OOP**: Kelas dan objek.

## 📁 Struktur Proyek

```
tugas_besar_cpp_semester_1/
├── hasil_akhir.cpp        # File aplikasi utama
├── CRUD_barang.cpp        # Implementasi CRUD
├── login.cpp              # Sistem login
├── transaksi.cpp          # Manajemen transaksi
├── pseudocode.coffee      # Pseudocode algoritma
└── README.md
```

## 🚀 Memulai

### Prasyarat
- Kompiler C++ (GCC, Clang, atau MSVC).
- Mendukung standar C++11 atau lebih tinggi.

### Kompilasi
```bash
g++ -o manajemen_barang hasil_akhir.cpp -std=c++11
```

### Menjalankan Aplikasi
```bash
./manajemen_barang
```
Atau klik dua kali pada file `.exe` di Windows.

## 💻 Panduan Penggunaan

1. **Login**: Masukkan username dan password untuk mengakses menu utama.
2. **Menu Utama**:
   - **1. Lihat Barang**: Menampilkan semua daftar inventaris.
   - **2. Tambah Barang**: Membuat entri barang baru.
   - **3. Update Barang**: Mengubah data barang berdasarkan kode.
   - **4. Hapus Barang**: Menghapus barang dari inventaris.
   - **5. Proses Transaksi**: Menangani stok masuk atau keluar.
   - **6. Keluar**: Menyimpan semua data dan menutup aplikasi.

## 🎓 Tujuan Pembelajaran
Proyek ini mendemonstrasikan penguasaan terhadap fundamental C++, konsep OOP (Class, Encapsulation), File I/O (Txt files), struktur data (Vector, Struct), dan logika pemrograman modular.

---

**Proyek Akhir Semester 1** 🎓💻  
Sistem manajemen barang lengkap yang menampilkan dasar-dasar pemrograman C++!

#include <iostream>
using namespace std;
string namaBarang, jenisBarang, kamuNanya = "y", besaranPajakImport;
int hargaBarang, jumlahBarang, kelasBarang, totalHargaBarang, TotalNilaiPajak;

// funtion main
void makanan()
{
    jenisBarang = __func__;
    besaranPajakImport = "5%";
    totalHargaBarang = (jumlahBarang * hargaBarang);
    TotalNilaiPajak = totalHargaBarang * 0.05;
}
void pakaian()
{
    jenisBarang = __func__;
    besaranPajakImport = "10%";
    totalHargaBarang = (jumlahBarang * hargaBarang);
    TotalNilaiPajak = totalHargaBarang * 0.1;
}
void mesinMesin()
{
    jenisBarang = __func__;
    besaranPajakImport = "5%";
    totalHargaBarang = (jumlahBarang * hargaBarang);
    TotalNilaiPajak = totalHargaBarang * 0.2;
}
// end function

// core main function
int main()
{
    cout << "DEPARTEMEN PERDAGANGAN REPUBLIK ANU" << endl;
    do
    {
        cout << "Masukan Nama Barang: ";
        cin >> namaBarang;
        cout << "Masukan Harga Barang: ";
        cin >> hargaBarang;
        cout << "Masukan Jumlah Barang: ";
        cin >> jumlahBarang;
        cout << "Masukan Kelas Barang\n1. Makanan 5%\n2. Pakaian 10%\n3. Mesin - Mesin 20%\nPilihan [1/2/3]: ";
        cin >> kelasBarang;
        switch (kelasBarang)
        {
        case 1:
            makanan();
            break;
        case 2:
            pakaian();
            break;
        case 3:
            mesinMesin();
            break;
        default:
            cout << "Pilihan " << kelasBarang << " Tidak Tersedia Mohon Memasukan Data Kembali!";
        }
        cout << "Jenis Barang: " << jenisBarang << endl;
        cout << "Besaran Pajak Import: " << besaranPajakImport << endl;
        cout << "Total Harga Barang: Rp. " << totalHargaBarang << endl;
        cout << "Total Nilai Pajak: Rp. " << TotalNilaiPajak << endl;
        cout << "Masih Ingin Bertanya\" Maksud Nya Menginput Data? <y/n> : ";
        cin >> kamuNanya;
    } while (kamuNanya == "y");
    // next?
}
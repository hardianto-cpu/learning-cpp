#include <iostream>
#include <iomanip>
using namespace std;
int plg, jmlhBrng;
string condition = "y", conditionBrg = "y";
struct dataBarang
{
    string kodeBrg, namaBrg;
    float hrgSatuan, jumlahBeli;
    int totHrg;
};
struct dataPelanggan
{
    string kodePlgn, namaPlgn;
    struct dataBarang brg[50];
    float subTot, potongan, grandTot, totJumlah;
};

struct dataPelanggan pembeli[100];

float chooseSubtotal(int jumlah)
{
    float potongan = 0;
    if (jumlah <= 10 && jumlah >= 5)
        potongan = 0.05;
    if (jumlah <= 20 && jumlah >= 11)
        potongan = 0.1;
    if (jumlah > 20)
        potongan = 0.2;
    return potongan;
}
int main()
{
    while (condition == "y")
    {
        plg++;
        cout << "Masukan Data Pembeli Ke-" << plg << ": " << endl;
        cout << "Masukan Kode Pelanggan: ";
        cin >> pembeli[plg].kodePlgn;
        cout << "Masukan Nama Pelanggan: ";
        cin >> pembeli[plg].namaPlgn;
        // data barang maximal 50 ye
        do
        {
            jmlhBrng++;
            cout << "Masukan Data Barang ke-" << jmlhBrng << ": " << endl;
            cout << "Masukan Kode Barang: ";
            cin >> pembeli[plg].brg[jmlhBrng].kodeBrg;
            cout << "Masukan Nama Barang: ";
            cin >> pembeli[plg].brg[jmlhBrng].namaBrg;
            cout << "Harga Satuan: Rp.";
            cin >> pembeli[plg].brg[jmlhBrng].hrgSatuan;
            cout << "Jumlah Barang: ";
            cin >> pembeli[plg].brg[jmlhBrng].jumlahBeli;
            pembeli[plg].brg[jmlhBrng].totHrg = pembeli[plg].brg[jmlhBrng].hrgSatuan * pembeli[plg].brg[jmlhBrng].jumlahBeli;
            float potongan = chooseSubtotal(pembeli[plg].brg[jmlhBrng].jumlahBeli) * pembeli[plg].brg[jmlhBrng].totHrg;
            pembeli[plg].totJumlah = pembeli[plg].totJumlah + pembeli[plg].brg[jmlhBrng].jumlahBeli;
            pembeli[plg].potongan = pembeli[plg].potongan + potongan;
            pembeli[plg].subTot = pembeli[plg].subTot + (pembeli[plg].brg[jmlhBrng].totHrg);
            cout << "Total Harga: " << pembeli[plg].brg[jmlhBrng].totHrg << endl;
            cout << "Sub Total Harga: " << (pembeli[plg].brg[jmlhBrng].totHrg - potongan) << endl;
            cout << "Ada Barang Lain [y/t]: ";
            cin >> conditionBrg;
        } while (conditionBrg == "y");
        pembeli[plg].grandTot = pembeli[plg].subTot - pembeli[plg].potongan;
        cout << "\n\nKode Pelanggan: " << pembeli[plg].kodePlgn << endl;
        cout << "Nama Pelanggan: " << pembeli[plg].namaPlgn << endl;
        cout << "| No | Kode Brg | Nama Barang | Harga Stn | Jumlah | Total Harga |" << endl;
        cout << "------------------------------------------------------------------\n";
        for (int i = 1; i <= jmlhBrng; i++)
        {
            cout << "| " << setiosflags(ios::left) << setw(3) << i;
            cout << "| " << setiosflags(ios::left) << setw(9) << pembeli[plg].brg[i].kodeBrg;
            cout << "| " << setiosflags(ios::left) << setw(12) << pembeli[plg].brg[i].namaBrg;
            cout << "| " << setiosflags(ios::left) << setw(10) << int(pembeli[plg].brg[i].hrgSatuan);
            cout << "| " << setiosflags(ios::left) << setw(7) << pembeli[plg].brg[i].jumlahBeli;
            cout << "| " << setiosflags(ios::left) << setw(12) << pembeli[plg].brg[i].totHrg;
            cout << endl;
        }
        cout << "------------------------------------------------------------------\n";

        cout << "Sub Total Harga: Rp." << int(pembeli[plg].subTot) << endl;
        cout << "Total Jumlah Barang: " << pembeli[plg].totJumlah << endl;
        cout << "Potongan: Rp." << pembeli[plg].potongan << endl;
        cout << "Jumlah Yang Harus Di Bayar: Rp." << (pembeli[plg].grandTot) << endl;
        jmlhBrng = 0; // reset
        cout << "Input Transaksi Berikutnya [y/n]: ";
        cin >> condition;
    }
}
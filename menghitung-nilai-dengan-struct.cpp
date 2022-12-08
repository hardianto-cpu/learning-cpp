/**
 * intinya jangan bernafas
 * author: hardianto
 * noted: jangan lupa ganti variable brani edit brani fix sendiri
*/

#include <iostream>
#include <iomanip>
using namespace std;
int jumlah, i;
string iya = "y";
struct dataMataKuliah
{
    string kodeMk;
    string namaMK;
    char NH;
    short bobot;
    short sks;
};
struct dataMahasiswa
{
    string noPokok;
    string namaMhs;
    int jumlahMk, jumlahBo;
    struct dataMataKuliah mk[70];
    short totalSks;
    float IPK;
};

struct dataMahasiswa mhs[40];

void showTable(int u)
{
    cout << "| No | KODE MK | Nama Matakuliah | NH | Bobot | SKS | Bobot x SKS |" << endl;
    cout << "-------------------------------------------------------------------\n";
    for (int uu = 0; uu < mhs[u].jumlahMk; uu++)
    {
        cout << "| " << setiosflags(ios::left) << setw(3) << uu + 1;
        cout << "| " << setiosflags(ios::left) << setw(8) << mhs[u].mk[uu].kodeMk;
        cout << "| " << setiosflags(ios::left) << setw(16) << mhs[u].mk[uu].namaMK;
        cout << "| " << setiosflags(ios::left) << setw(3) << mhs[u].mk[uu].NH;
        cout << "| " << setiosflags(ios::left) << setw(6) << mhs[u].mk[uu].bobot;
        cout << "| " << setiosflags(ios::left) << setw(4) << mhs[u].mk[uu].sks;
        cout << "| " << setiosflags(ios::left) << setw(12) << mhs[u].mk[uu].bobot * mhs[u].mk[uu].sks << "|";
        cout << endl;
    }
    cout << "-------------------------------------------------------------------\n";
}
int main()
{
    cout << "PROGRAM CETAK TRANSKIRPSI NILAI\n";
    cout << "-------------------------------\n";
    while (iya == "y")
    {
        int ii;
        cout << "Masukan Data Mahasiswa ke-" << i + 1 << ": " << endl;
        cout << "NO POKOK: ";
        cin >> mhs[i].noPokok;
        cout << "Nama Mahasiswa: ";
        cin >> mhs[i].namaMhs;
        cout << "Jumlah Mata Kuliah: ";
        cin >> mhs[i].jumlahMk;
        for (ii = 0; ii < mhs[i].jumlahMk; ii++)
        {
            cout << "Masukan Data MataKuliah ke-" << ii + 1 << ": " << endl;
            cout << "Kode Matakuliah: ";
            cin >> mhs[i].mk[ii].kodeMk;
            cout << "Nama Matakuliah: ";
            cin >> mhs[i].mk[ii].namaMK;
            cout << "Masukan Nilai Huruf [A/B/C/D/E]: ";
            cin >> mhs[i].mk[ii].NH;
            switch (mhs[i].mk[ii].NH)
            {
            case 'A':
                mhs[i].mk[ii].bobot = 4;
                break;
            case 'B':
                mhs[i].mk[ii].bobot = 3;
                break;
            case 'C':
                mhs[i].mk[ii].bobot = 2;
                break;
            case 'D':
                mhs[i].mk[ii].bobot = 1;
                break;
            default:
                mhs[i].mk[ii].bobot = 0;
                break;
            }
            cout << "Bobot Nilai: " << mhs[i].mk[ii].bobot << endl;
            cout << "Nilai Sks [1/2/3/4]: ";
            cin >> mhs[i].mk[ii].sks;
            // hitung sks
            mhs[i].totalSks = mhs[i].totalSks + mhs[i].mk[ii].sks;
            int bobotXsks = mhs[i].mk[ii].sks * mhs[i].mk[ii].bobot;
            jumlah = jumlah + bobotXsks;
            cout << "Bobot x Sks: " << bobotXsks << endl;
        }
        mhs[i].IPK = float(jumlah) / float(mhs[i].totalSks);
        cout << "Jumlah Bobot x Sks: " << jumlah << endl;
        cout << "Total Sks: " << mhs[i].totalSks << endl;
        cout << "\n\nTRANSKRIPSI NILAI" << endl;
        cout << "No.Pokok: " << mhs[i].noPokok << endl;
        cout << "Nama Mhs: " << mhs[i].namaMhs << endl;
        showTable(i);
        cout << "Total Bobot x Sks: " << jumlah << endl;
        cout << "Total Sks: " << mhs[i].totalSks << endl;
        cout << "Index Prestasi Komulatif (IPK): " << setprecision(2) << mhs[i].IPK << endl;
        i++;
        cout << "Masih Ada Mahasiswa Lain <y/n>: ";
        cin >> iya;
    }
}
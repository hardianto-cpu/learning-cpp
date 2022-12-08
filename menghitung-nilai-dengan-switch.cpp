/**
 * ngoding di kertas awog awog
 * ------------------------------
 * author: hardianto
 * license: mit
 * ***************************
 * ***************************
 * **************************
 * **************************
 */

// starting program
#include <iostream>
using namespace std;

string keadaan = "y", nama, bahasaPemrograman, namaMaxBasic, namaMaxPascal, namaMaxCpp;
int noRegistrasi, kodeBahasa, nilai = -1, beliau, maxPascal, maxBasic, maxCpp, nilaiMaxBasic, noMaxBasic, nilaiMaxPascal, noMaxPascal, nilaiMaxCpp, noMaxCpp;
int main()
{
    cout << "PUSAT PENDIDIKAN KOMPUTER INFORMATIKA!!" << endl;
    cout << "_______________________________________" << endl;
    // logic y teams
    while (keadaan == "y")
    {
        beliau++;
        // logic lagi
        cout << "No.Registrasi: ";
        cin >> noRegistrasi;
        cout << "Nama Peserta: ";
        cin >> nama;
        cout << "Pilih Bahasa Pemrograman: \n1. Basic\n2. Pascal\n3. C++\nInput Kode Bahasa [1/2/3] : ";
        cin >> kodeBahasa;
        while (nilai > 100 || nilai <= -1) // kalo lebih besar dari 100 dan kurang dari atau sama dengan 0
        {
            if (nilai != -1)
                cout << "Input Anda Lebih Dari 100 atau Kurang Dari 0 :)" << endl;
            cout << "Input Nilai: ";
            cin >> nilai;
        }
        switch (kodeBahasa)
        {
        case 1:
            bahasaPemrograman = "Basic";
            if (nilai > maxBasic)
            { // jika nilai basic tidak nol atau nilai lebih besar dari minBasic
                maxBasic = nilai;
                namaMaxBasic = nama;
                nilaiMaxBasic = nilai;
                noMaxBasic = noRegistrasi;
            }
            break;
        case 2:
            bahasaPemrograman = "Pascal";
            if (nilai > maxPascal)
            { // jika nilai Pascal tidak nol atau nilai lebih besar dari maxPascal
                maxPascal = nilai;
                namaMaxPascal = nama;
                nilaiMaxPascal = nilai;
                noMaxPascal = noRegistrasi;
            }
            break;
        case 3:
            bahasaPemrograman = "C++";
            if (nilai > maxCpp)
            { // jika nilai Pascal tidak nol atau nilai lebih Besar dari maxCPp
                maxCpp = nilai;
                namaMaxCpp = nama;
                nilaiMaxCpp = nilai;
                noMaxCpp = noRegistrasi;
            }
            break;
        }
        cout << "Bahasa Pemrograman: " << bahasaPemrograman << endl;

        // kembali ke semula
        nilai = -1;
        cout << "Masih Ada Data Lain Ngabs? [y/n]: ";
        cin >> keadaan;
    }
    cout << "__________________________________" << endl;
    cout << "Nilai Tertinggi Pada Bahasa Basic: " << endl;
    cout << "\tNo.Registrasi: " << noMaxBasic << endl;
    cout << "\tNama Perserta: " << namaMaxBasic << endl;
    cout << "\tNilai Ujian: " << maxBasic << endl;
    cout << "__________________________________" << endl;
    cout << "Nilai Tertinggi Pada Bahasa Pascal: " << endl;
    cout << "\tNo.Registrasi: " << noMaxPascal << endl;
    cout << "\tNama Perserta: " << namaMaxPascal << endl;
    cout << "\tNilai Ujian: " << maxPascal << endl;
    cout << "__________________________________" << endl;
    cout << "Nilai Tertinggi Pada Bahasa C++: " << endl;
    cout << "\tNo.Registrasi: " << noMaxCpp << endl;
    cout << "\tNama Perserta: " << namaMaxCpp << endl;
    cout << "\tNilai Ujian: " << maxCpp << endl;
    cout << "__________________________________";
}

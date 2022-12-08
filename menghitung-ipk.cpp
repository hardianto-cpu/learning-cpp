#include <iostream>
#include <string>
using namespace std;

int main()
{
    int no_pokok, count = 1, matkul_count = 1, nilai_count = 1, mahasiswa_count = 1, no_pokok_l, no_pokok_h, fix_data2;
    float nilai_udin = 9.99, total_bobot = 0, bobot, total_sks = 0, sks, indexIP, ip_l = 0, ip_h = 0;
    string kode, jurusan = "salah", nama, lagi, nama_matkul, kode_matkul, nilai, y2, nama_l, nama_h, fix_data;
    for (int lu = 0; lu < mahasiswa_count; lu++)
    {
        cout << "Masukan Data Anda Pribadi Anda Dengan Benar" << endl;
        cout << "No.Pokok Anda: ";
        cin >> no_pokok;
        cout << "Nama Anda: ";
        cin >> nama;
        for (int i = 0; i < count; i++)
        {
            cout << "Masukan Kode Jurusan Anda: ";
            cin >> kode;
            if (kode == "TI")
                jurusan = "TEKNIK INFORMATIKA";
            else if (kode == "SI")
                jurusan = "SISTEM INFORMATIKA";
            else if (kode == "RPL")
                jurusan = "REKAYASA PERANGKAT LUNAK";
            else if (kode == "MI")
                jurusan = "MANAJEMEN INFORMATIKA";
            else if (kode == "BD")
                jurusan = "BISNIS DIGITAL";
            else if (kode == "KWH")
                jurusan = "KEWIRAUSAHAAN";
            else
            {
                count = count + 1;
            }
        }
        if ((jurusan != "salah"))
        {
            cout << "jURUSAN ANDA: " << jurusan << endl;
        }
        for (int i = 0; i < matkul_count; i++)
        {
            cout << "Masukkan Data MataKuliah : " << endl;
            cout << "Kode Mata Kuliah : ";
            cin >> kode_matkul;
            cout << "Nama Mata Kuliah : ";
            cin >> nama_matkul;
            cout << "Jumlah Sks: ";
            cin >> sks;

            for (int i = 0; i < nilai_count; i++)
            {
                cout << "Masukan Nilai Huruf [A/A-/B+/B/B-/C+/C/D/E]: ";
                cin >> nilai;
                if (nilai == "A")
                    nilai_udin = 4.00;
                else if (nilai == "A-")
                    nilai_udin = 3.67;
                else if (nilai == "B+")
                    nilai_udin = 3.33;
                else if (nilai == "B")
                    nilai_udin = 3.00;
                else if (nilai == "B-")
                    nilai_udin = 2.67;
                else if (nilai == "C+")
                    nilai_udin = 2.33;
                else if (nilai == "C")
                    nilai_udin = 2.00;
                else if (nilai == "D")
                    nilai_udin = 1.00;
                else if (nilai == "E")
                    nilai_udin = 0;
                else
                    nilai_count++;
                    cout << nilai_count << endl;
                if (int(nilai_udin) != 9)
                    cout << "Bobot: " << float(nilai_udin) << endl;
            }
            total_sks = total_sks + sks;
            bobot = (sks * nilai_udin);        //
            total_bobot = total_bobot + bobot; // sigma

            cout << "Masih Ingin Menginput Data Mata Kuliah ? y/n: ";
            cin >> y2;
            if (y2 == "y")
                matkul_count = (matkul_count + 1);
        }
        cout << "total sks: " << total_sks << endl;
        indexIP = total_bobot / total_sks;
        cout << "IP: " << indexIP << endl;
        if (indexIP > ip_h)
        {
            ip_h = indexIP;
            nama_h = nama;
            no_pokok_h = no_pokok;
        }
        if (indexIP < ip_l)
        {
            nama_l = nama;
            no_pokok_l = no_pokok;
            ip_l = indexIP;
        }
        if (ip_l == 0)
            ip_l = indexIP;
        cout << "Masih Ingin Menginput Data Mahasiswa ? y/n: ";
        cin >> lagi;
        if (lagi == "y")
            mahasiswa_count = mahasiswa_count + 1;
    }
    cout << "\n----------------------------\n";
    cout << "IP TERTINGGI : " << ip_h << endl;
    cout << "NAMA: " << nama_h << endl;
    cout << "NO. POKOK: " << no_pokok_h << endl;

    fix_data = (ip_h == ip_l) ? nama_h : nama_l;
    fix_data2 = (ip_h == ip_l) ? no_pokok_h : no_pokok_l;
    cout << "\n----------------------------\n";
    cout << "\n\nIP TERENDAH : " << ip_l << endl;
    cout << "NAMA: " << fix_data << endl;
    cout << "NO. POKOK: " << fix_data2 << endl;
}
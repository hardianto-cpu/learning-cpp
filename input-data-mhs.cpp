#include <iostream>
#include <iomanip>
using namespace std;
string jawab = "y",
       matkul_jawab = "y",
       kode_jurusan = "DEFAULT",
       nama,
       kode_matkul,
       nilai = "DEFAULT",
       nama_matkul,
       nama_l,
       nama_h,
       fix_data,
       jurusan;
int no_pokok,
    ke = 1,
    nilai_count = 1,
    fix_int,
    no_pokok_h,
    no_pokok_l,
    fix_data2;
float nilai_udin = 99, total_sks, bobot, sigma_bobot, indexIP, ip_l, ip_h = 0, sks;

int main()
{
    cout << "\tPROGRAM INPUT DATA NILAI MAHASISWA" << endl;
    cout << "------------------------------------------------" << endl;
    // logic yteam
    while (jawab == "y")
    {
        cout << "No. Pokok: ";
        cin >> no_pokok;
        if (!no_pokok) {
            jawab = "n";
            continue;
        }
        cout << "Nama : ";
        cin >> nama;
        // looping penginputan JURUSAN via nilai
        while (kode_jurusan == "DEFAULT")
        {
            cout << "Masukan Jurusan: ";
            cin >> kode_jurusan;
            if (kode_jurusan == "TI")
                jurusan = "TEKNIK INFORMATIKA";
            else if (kode_jurusan == "SI")
                jurusan = "SISTEM INFORMASI";
            else if (kode_jurusan == "RPL")
                jurusan = "REKAYASA PERANGKAT LUNAK";
            else if (kode_jurusan == "MI")
                jurusan = "MANAJEMEN INFORMATIKA";
            else if (kode_jurusan == "BD")
                jurusan = "BISNIS DIGITAL";
            else if (kode_jurusan == "KWH")
                jurusan = "KEWIRAUSAHAAN";
            else
                kode_jurusan = "DEFAULT";
            if (kode_jurusan != "DEFAULT")
                cout << "JURUSAN : " << jurusan << endl;
        }

        if (ke && ke != 0)
            matkul_jawab = "y";
        // LOOPING PENGINPUTAN MATA KULIAH
        while (matkul_jawab == "y")
        {
            cout << "Masukkan Data Mata Kuliah "
                 << "Ke-" << ke << " : " << endl;
            cout << "Kode Mata Kuliah : ";
            cin >> kode_matkul;
            cout << "Nama Mata Kuliah : ";
            cin >> nama_matkul;
            cout << "Jumlah Sks: ";
            cin >> sks;
            // looping logic NILAI HURUF
            for (int i = 0; i < nilai_count; i++)
            {
                matkul_jawab = "n";
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
                {
                    nilai_count = nilai_count + 1;
                    matkul_jawab = "y";
                    nilai_udin = 99;
                }
                if (nilai_udin != 99)
                    cout << "BOBOT: " << nilai_udin << endl;
                // sini
                total_sks = total_sks + sks;
            }
            // end looping nilai HURUF

            ke++;
            cout << "Masih Ingin Menginput Data Kuliah ? <y/n>: ";
            cin >> matkul_jawab;
            nilai_count = 1;
            bobot = (sks * nilai_udin);        //
            sigma_bobot = sigma_bobot + bobot; // sigma

            indexIP = sigma_bobot / total_sks;

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
        }
        if (nama_l == "") nama_l = nama_h;
        if (!no_pokok_l) no_pokok_l = no_pokok_h;
        cout << "TOTAL SKS: " << total_sks << " sks" << endl;
        cout << "IP: " << setprecision(3) << indexIP << endl;
        // end penginputan MATA KULIAH

        // reset input
        total_sks = 0;
        sigma_bobot = 0;
        ke = 1;
        jawab = "n";
        kode_jurusan = "DEFAULT";
        cout << "Masih Ada Mahasiswa Lain? <y/n> : ";
        cin >> jawab;
    }
    cout << "\n----------------------------\n";
    cout << "IP TERTINGGI : " << float(ip_h) << endl;
    cout << "NAMA: " << nama_h << endl;
    cout << "NO. POKOK: " << no_pokok_h << endl;

    cout << "\n----------------------------\n";
    cout << "\n\nIP TERENDAH : " << ip_l << endl;
    cout << "NAMA: " << nama_l << endl;
    cout << "NO. POKOK: " << no_pokok_l << endl;
    // end looping penginputan MAHASISWA
}
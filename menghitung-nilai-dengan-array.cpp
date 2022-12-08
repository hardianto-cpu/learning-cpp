#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;
int count = 0, a, b, c, d, e, maxN, minN, maxS, minS;
int stambuk[9999], nilai[999], total;
string lanjut = "y", nama[999];
string maxNama, minNama;

char nilaiHuruf(int nilai)
{
    if (nilai >= 80 && nilai <= 100)
    {
        a++;
        return 'A';
    }
    else if (nilai >= 65 && nilai <= 80)
    {
        b++;
        return 'B';
    }
    else if (nilai >= 50 && nilai <= 65)
    {
        c++;
        return 'C';
    }
    else if (nilai >= 35 && nilai <= 50)
    {
        d++;
        return 'D';
    }
    else
    {
        e++;
        return 'E';
    }
}
void inputBreaks(int &input)
{
    cout << "Masukan Nilai [100..0]: ";
    cin >> input;
    while (input >= 100 || input < 0)
    {
        cout << "Input Anda Lebih Dari 100 atau Kurang Dari 0" << endl;
        cout << "Masukan Nilai [100..0]: ";
        cin >> input;
    }
}

void initialize()
{
    cout << "---------------------------" << endl;
    cout << "Masukan Stambuk: ";
    cin >> stambuk[count];
    cout << "Masukan Nama: ";
    cin >> nama[count];
    inputBreaks(nilai[count]);
    cout << "Nilai Huruf: " << nilaiHuruf(nilai[count]) << endl;
    total = total + nilai[count];
    count++;
}

int main()
{
    while (lanjut == "y")
    {
        initialize();
        cout << "Masih Ada Mahasiswa Lain? <y/n> : ";
        cin >> lanjut;
    }

    int rata = total / count;
    system("cls");
    cout << "---------------------------" << endl;
    cout << "Hasil REKAPITULASI" << endl;
    cout << "Rata-rata: " << rata << endl;
    cout << "Jumlah-Nilai: " << endl;
    cout << "\tA: " << a << endl;
    cout << "\tB: " << b << endl;
    cout << "\tC: " << c << endl;
    cout << "\tD: " << d << endl;
    cout << "\tE: " << e << endl;
    cout << endl;
    cout << "DAFTAR NILAI MAHASISWA" << endl;
    cout << "| No | Stambuk | Nama Mahasiswa | Nilai | N.Huruf |" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < count; i++)
    {
        if (nilai[i] <= minN || minN <= 0)
        {
            minNama = nama[i];
            minS = stambuk[i];
            minN = nilai[i];
        }
        if (nilai[i] > maxN)
        {
            maxN = nilai[i];
            maxS = stambuk[i];
            maxNama = nama[i];
        }

        cout << "| " << setiosflags(ios::left) << setw(3) << i + 1 << "|";
        cout << " " << setiosflags(ios::left) << setw(8) << stambuk[i] << "|";
        cout << " " << setiosflags(ios::left) << setw(15) << nama[i] << "|";
        cout << " " << setiosflags(ios::left) << setw(6) << nilai[i] << "|";
        cout << " " << setiosflags(ios::left) << setw(8) << nilaiHuruf(nilai[i]) << "|" << endl;
    }
    cout << "--------------------------------------------------" << endl;
    cout << endl;
    cout << "Nilai Tertinggi: " << maxN << endl;
    cout << "\tStambuk: " << maxS << endl;
    cout << "\tNama: " << maxNama << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Nilai Terendah: " << minN << endl;
    cout << "\tStambuk: " << minS << endl;
    cout << "\tNama: " << minNama << endl;

    return 0;
}
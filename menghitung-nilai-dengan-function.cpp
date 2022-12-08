#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
string nama, iya = "iya", namaBeliauP, namaBeliauB, kt;
int noPokok, nilaiMid, nilaiFinal, nilaiAkhir, nilaiHuruf, i = 1, nilaiTugas, nilaiPresensi, beliau, sipalingPintar, siPalingPaling, noPokokP, noPokokB, a, b, c, d, e;
bool toogleValidate(int first, int last, int &input)
{
    bool posisi;
    posisi = input >= first && input <= last;
    if (!posisi)
        cout << "Input Anda Salah!!!\nInput Anda: " << input << " Inputan Tidak Boleh Kurang Dari " << first << " Dan Tidak Boleh Lebih Dari " << last << endl;
    return posisi;
}
void spill(string kamuNanya, int &input, int rule1, int rule2)
{
    do
    {
        cout << kamuNanya;
        cin >> input;
    } while (!toogleValidate(rule1, rule2, input));
}
int totalJumlahan(int before, int after)
{
    return (before + after);
}
float rataRata(float input, int count)
{
    return input / count;
}
void formatterNilai(int count, int &nilaiT, string str)
{
    int input, matot = 0;
    for (int i = 1; i <= count; i++)
    {
        stringstream b;
        b << str << "Ke-" << i << ": ";
        spill(b.str(), input, 0, (count == 15 ? 1 : 100));
        matot = totalJumlahan(matot, input);
    }
    nilaiT = rataRata(matot, count) * (count == 15 ? 100 : 1);
}
void cariBeliau(int calonBeliau)
{
    if (sipalingPintar == 0)  sipalingPintar = calonBeliau;
    if (siPalingPaling == 0) siPalingPaling = calonBeliau; // set default
    if (calonBeliau >= sipalingPintar)
    {
        sipalingPintar = calonBeliau;
        namaBeliauP = nama;
        noPokokP = noPokok;
    }
    if (calonBeliau <= siPalingPaling)
    {
        siPalingPaling = calonBeliau;
        namaBeliauB = nama;
        noPokokB = noPokok;
    }
}
string eliminasi(int nilai)
{
    if (nilai >= 80)
    {
        a++;
        kt = "LULUS";
        return "a";
    }
    else if (nilai < 80 && nilai >= 65)
    {
        b++;
        kt = "LULUS";
        return "b";
    }
    else if (nilai < 65 && nilai >= 50)
    {
        c++;
        kt = "LULUS";
        return "c";
    }
    else if (nilai < 50 && nilai >= 40)
    {
        d++;
        kt = "LULUS";
        return "d";
    }
    else
    {
        e++;
        kt = "TIDAK LULUS";
        return "e";
    }
}
void bertanya()
{
    beliau++;
    cout << "Masukan Nama: ";
    cin >> nama;
    cout << "Masukan No. Pokok: ";
    cin >> noPokok;
    formatterNilai(5, nilaiTugas, "Masukan Nilai Tugas ");
    formatterNilai(15, nilaiPresensi, "Pertemuan [1/0] ");
    spill("Masukan Nilai Mid: ", nilaiMid, 0, 100);
    spill("Masukan Nilai Final: ", nilaiFinal, 0, 100);
    nilaiAkhir = 0.1 * nilaiPresensi + 0.2 * nilaiTugas + 0.3 * nilaiMid + 0.4 * nilaiFinal;
    cout << "Nilai Tugas: " << nilaiTugas << endl;
    cout << "Nilai Presensi: " << nilaiPresensi << endl;
    cout << "Nilai Mid: " << nilaiMid << endl;
    cout << "Nilai Akhir: " << nilaiAkhir << endl;
    cout << "Nilai Huruf: " << eliminasi(nilaiAkhir) << endl;
    cout << "Keterangan: " << kt << endl;
    cariBeliau(nilaiAkhir); // cari beliau
}

int main()
{
    do
    {
        bertanya();
        cout << "Masih Ingin Menginput Data Mahasiswa? <y/n>: ";
        cin >> iya;
    } while (iya == "y");
    cout << "---------------------------------" << endl;
    cout << "Data Paling Tertinggi Dari Sekian " << beliau << " Beliau" << endl;
    cout << "Nama: " << namaBeliauP << endl;
    cout << "Nilai Paling Tinggi " << sipalingPintar << endl;
    cout << "NO. POKOK: " << noPokokP << endl;
    cout << "--------------------------------" << endl;
    cout << "Data Paling Terendah Dari Sekian " << beliau << " Beliau" << endl;
    cout << "Nama: " << namaBeliauB << endl;
    cout << "Nilai Paling Rendah " << siPalingPaling << endl;
    cout << "NO. POKOK: " << noPokokB << endl;
    cout << "--------------------------------" << endl;
    cout << "--------------------------------" << endl;
    cout << "Perolehan Nilai Huruf Dari " << beliau << " org" << endl;
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;
    cout << "D: " << d << endl;
    cout << "E: " << e << endl;
    if (e != 0)
        cout << e << " orang tidak lulus!";
}
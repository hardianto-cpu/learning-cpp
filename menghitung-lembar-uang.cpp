#include <iostream>
using namespace std;
int duite, jumlahL, jumlahC;

void nanya()
{
    cout << "Masukan Jumlah Uang: ";
    cin >> duite;
    cout << "__________________________________" << endl;
}

int convert(int &input, int &total, int uang)
{
    int lembar;
    lembar = input / uang;
    input = input % uang;
    total = total + lembar;
    return lembar;
}

int main()
{
    nanya();
    cout << "Jumlah Uang 100ribu: " << convert(duite, jumlahL, 100000) << endl;
    cout << "Jumlah Uang 50ribu: " << convert(duite, jumlahL, 50000) << endl;
    cout << "Jumlah Uang 20ribu: " << convert(duite, jumlahL, 20000) << endl;
    cout << "Jumlah Uang 10ribu: " << convert(duite, jumlahL, 10000) << endl;
    cout << "Jumlah Uang 5ribu: " << convert(duite, jumlahL, 5000) << endl;
    cout << "Jumlah Uang 2ribu: " << convert(duite, jumlahL, 2000) << endl;
    cout << "Jumlah Uang 1000: " << convert(duite, jumlahL, 1000) << endl;
    cout << "Jumlah Uang 500: " << convert(duite, jumlahC, 500) << endl;
    cout << "Jumlah Uang 200: " << convert(duite, jumlahC, 200) << endl;
    cout << "Jumlah Uang 100: " << convert(duite, jumlahC, 100) << endl;
    cout << "Sisah Uang Tanpah Pecahan: " << duite << endl;
    cout << "__________________________________" << endl;
    cout << "Total Jumlah Lembaran: " << jumlahL << endl;
    cout << "Total Jumlah koin: " << jumlahC << endl;
}
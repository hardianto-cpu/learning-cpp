/**
 * intinya jangan bernafas
 * author: hardianto
 * noted: jangan lupa ganti variable brani edit brani fix sendiri
*/


#include <iostream>
#include <iomanip>
using namespace std;
string lagi = "y";
int matrixA[10][10], matrixB[10][10];
int operasi;
void isiMatrix()
{
    for (int brs = 0; brs < 4; brs++)
    {
        for (int kol = 0; kol < 5; kol++)
        {
            matrixA[brs][kol] = rand() % 9;
            matrixB[brs][kol] = rand() % 9;
        }
    }
}

void showMatrix(int baris, int kolom, int matrixA[10][10])
{
    cout << "| NO | VALUE MATRIX |" << endl;
    cout << "--------------------" << endl;
    for (int brs = 0; brs < baris; brs++)
    {
        cout << "| " << brs + 1 << " |";
        for (int i = 0; i < kolom; i++)
        {
            cout << " " << setiosflags(ios::left) << setw(1) << matrixA[brs][i];
        }
        cout << setiosflags(ios::left) << setw(1) << "\n--------------------" << endl;
    }
}
// tambah matrix
void tambah()
{
    int matrixTot[10][10];
    for (int brs = 0; brs < 4; brs++)
    {
        for (int kol = 0; kol < 5; kol++)
        {
            matrixTot[brs][kol] = matrixA[brs][kol] + matrixB[brs][kol];
        }
    }
    showMatrix(4, 5, matrixTot);
}

void gabung()
{
    int matrixGabungan[10][10];
    for (int i = 0; i < 4; i++)
    {
        for (int ii = 0; ii < 5; ii++)
        {
            matrixGabungan[i][ii] = matrixA[i][ii];
            matrixGabungan[4 + i][ii] = matrixB[i][ii];
        }
    }
    showMatrix(8, 5, matrixGabungan);
}
void pisahkan()
{
    int matrix1[10][10];
    int matrix2[10][10];
    system("cls");
    cout << "AUTOMATIC GENERATE MATRIX" << endl;
    showMatrix(4, 5, matrixA); // normal matrix
    cout << "\n\n";
    for (int i = 0; i < 4; i++)
    {
        for (int ii = 0; ii < 3; ii++)
        {
            /**
             * yang dulunya matrix 4*5 di ubah jadi 4*3
             */
            matrix1[i][ii] = matrixA[i][ii];
        }
    }
    cout << "Matrix A: " << endl;
    showMatrix(4, 3, matrix1);
    cout << "\n\n";
    cout << "Matrix B: " << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int ii = 0; ii < 2; ii++)
        {
            /**
             * yang dulunya matrix 4*5 di pisah jadi 4*3
             */
            matrix2[i][ii] = matrixA[i][ii + 3];
        }
    }
    showMatrix(4, 2, matrix2);
}
void perkalian()
{
    int kaliMatrix[10][10];
    for (int i = 0; i < 4; i++)
    {
        for (int ii = 0; ii < 5; ii++)
        {
            kaliMatrix[i][ii] = 0;
            kaliMatrix[i][ii] = kaliMatrix[i][ii] + matrixA[i][ii] * matrixB[i][ii];
        }
    }
    cout << "Hasil Perkalian Matrix\n"
         << endl;
    showMatrix(4, 5, kaliMatrix);
}
void transpose(int brsu, int klm)
{
    system("cls");
    cout << "Matrix Sebelum Di Transpose" << endl;
    showMatrix(4, 5, matrixA); // kita ambil example dari matrix sebelum nya;
    int transposeAfter[10][10];
    for (int i = 0; i < 4; i++)
    {
        for (int ii = 0; ii < 5; ii++)
        {
            transposeAfter[ii][i] = matrixA[i][ii];
        }
    }
    cout << "\n\nMatrix Sesudah Di Transpose" << endl;
    showMatrix(5, 4, transposeAfter);
}

int main()
{
    while (lagi == "y")
    {
        isiMatrix();
        cout << "Matrix A" << endl;
        showMatrix(4, 5, matrixA);
        cout << endl
             << "Matrix B" << endl;
        showMatrix(4, 5, matrixB);
        cout << "Masukan Operasi Matrix Yang:\n1. Penjumlahan Matrix\n2. Penggabungan Matrix\n3. Memisahkan Matrix\n4. Perkalian Matrix\n5. Transpose Matrix\n\nPilih Operasi Matrix Yang Dinginkan 1-5: ";
        cin >> operasi;
        switch (operasi)
        {
        case 1:
            tambah();
            break;
        case 2:
            gabung();
            break;
        case 3:
            pisahkan();
            break;
        case 4:
            perkalian();
            break;
        case 5:
            transpose(4, 5);
            break;
        default:
            cout << "Opersi Yang Anda Input Tidak Di Temukan :)";
            break;
        }
        cout << "Masih ingin melakukan operasi lain? <y/n> : ";
        cin >> lagi;
    }
}